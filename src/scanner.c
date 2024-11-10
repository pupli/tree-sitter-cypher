#include "tree_sitter/array.h"
#include "tree_sitter/alloc.h"
#include "tree_sitter/parser.h"
#include <wctype.h>

enum TokenType {
    LAYOUT_SEMICOLON,
    LAYOUT_OPEN_BRACE,
    LAYOUT_CLOSE_BRACE,
    ARROW,
    QUALIFIED_MODULE_DOT,
    INITIALIZE_LAYOUT
};

struct Scanner {
    Array(uint16_t) indent_length_stack;
    uint32_t queued_close_brace_count;
};

static unsigned scanner_serialize(struct Scanner *self, char *buffer) {
    size_t i = 0;
    buffer[i++] = self->queued_close_brace_count;

    if (self->indent_length_stack.size > 0) {
        uint16_t
            *iter = array_front(&self->indent_length_stack),
            *end = array_back(&self->indent_length_stack);

        for (; iter != end && i < TREE_SITTER_SERIALIZATION_BUFFER_SIZE; ++iter) {
            buffer[i++] = *iter;
        }
    }

    return i;
}

static void scanner_deserialize(struct Scanner *self, const char *buffer, unsigned length) {
    self->queued_close_brace_count = 0;
    array_clear(&self->indent_length_stack);

    if (length > 0) {
        size_t i = 0;
        self->queued_close_brace_count = buffer[i++];

        while (i < length) {
            array_push(&self->indent_length_stack, buffer[i++]);
        }
    }
}

static void scanner_init(struct Scanner *self) {
    self->queued_close_brace_count = 0;
    array_init(&self->indent_length_stack);
}

static void scanner_deinit(struct Scanner *self) {
    array_delete(&self->indent_length_stack);
}

static void advance(TSLexer *lexer) {
    lexer->advance(lexer, false);
}

static void skip(TSLexer *lexer) {
    lexer->advance(lexer, true);
}

static bool isolated_sequence(TSLexer *lexer, const char *sequence) {
    for (const char *c = sequence; *c; c++) {
        if (lexer->lookahead == *c) {
            advance(lexer);
        } else {
            return false;
        }
    }

    return lexer->lookahead == 0 || iswspace(lexer->lookahead);
}

static bool scanner_scan(struct Scanner *self, TSLexer *lexer, const bool *valid_symbols) {
    if (valid_symbols[INITIALIZE_LAYOUT]) {
        lexer->mark_end(lexer);

        while (iswspace(lexer->lookahead)) {
            skip(lexer);
        }

        if (lexer->lookahead == '{' || lexer->lookahead == '-') {
            skip(lexer);

            if (lexer->lookahead == '-') {
                return false;
            }
        }

        if (isolated_sequence(lexer, "module")) {
            return false;
        }

        if (!lexer->eof(lexer)) {
            uint32_t column = lexer->get_column(lexer);
            array_push(&self->indent_length_stack, column);
        }

        lexer->result_symbol = INITIALIZE_LAYOUT;

        return true;
    }

    if (valid_symbols[QUALIFIED_MODULE_DOT] && lexer->lookahead == '.') {
        skip(lexer);

        if (iswspace(lexer->lookahead)) {
            return false;
        }

        lexer->result_symbol = QUALIFIED_MODULE_DOT;

        return true;
    }

    if (valid_symbols[LAYOUT_CLOSE_BRACE] && self->queued_close_brace_count > 0) {
        self->queued_close_brace_count--;
        lexer->result_symbol = LAYOUT_CLOSE_BRACE;

        return true;
    }

    if (valid_symbols[LAYOUT_OPEN_BRACE]) {
        lexer->mark_end(lexer);

        while (iswspace(lexer->lookahead)) {
            skip(lexer);
        }

        if (lexer->eof(lexer)) {
            lexer->result_symbol = LAYOUT_OPEN_BRACE;

            return true;
        }

        uint32_t column = lexer->get_column(lexer);

        if (lexer->lookahead == '{') {
            skip(lexer);

            if (lexer->lookahead == '-') {
                skip(lexer);

                if (lexer->lookahead != '#') {
                    return false;
                }
            } else {
                return false;
            }
        }

        if (self->indent_length_stack.size == 1 && column == *array_back(&self->indent_length_stack)) {
            self->queued_close_brace_count++;
        } else {
            array_push(&self->indent_length_stack, column);
        }

        lexer->result_symbol = LAYOUT_OPEN_BRACE;

        return true;
    }

    while (lexer->lookahead == ' ' || lexer->lookahead == '\t') {
        skip(lexer);
    }

    if (lexer->lookahead == 0) {
        if (valid_symbols[LAYOUT_SEMICOLON]) {
            lexer->result_symbol = LAYOUT_SEMICOLON;

            return true;
        }

        if (valid_symbols[LAYOUT_CLOSE_BRACE]) {
            lexer->result_symbol = LAYOUT_CLOSE_BRACE;

            return true;
        }

        return false;
    }

    lexer->mark_end(lexer);

    if (lexer->lookahead == ')') {
        if (valid_symbols[LAYOUT_SEMICOLON]) {
            if (self->indent_length_stack.size > 0) {
                array_pop(&self->indent_length_stack);
            }

            self->queued_close_brace_count++;
            lexer->result_symbol = LAYOUT_SEMICOLON;

            return true;
        }

        if (valid_symbols[LAYOUT_CLOSE_BRACE]) {
            if (self->indent_length_stack.size > 0) {
                array_pop(&self->indent_length_stack);
            }

            lexer->result_symbol = LAYOUT_CLOSE_BRACE;

            return true;
        }
    }

    if (lexer->lookahead == 'i') {
        advance(lexer);

        if (iswspace(lexer->lookahead)) {
            return false;
        } else if (lexer->lookahead == 'n') {
            advance(lexer);

            if (iswspace(lexer->lookahead)) {
                if (valid_symbols[LAYOUT_CLOSE_BRACE]) {
                    if (self->indent_length_stack.size > 0) {
                        array_pop(&self->indent_length_stack);
                    }

                    lexer->result_symbol = LAYOUT_CLOSE_BRACE;

                    return true;
                } else if (valid_symbols[LAYOUT_SEMICOLON]) {
                    if (self->indent_length_stack.size > 0) {
                        array_pop(&self->indent_length_stack);
                    }

                    self->queued_close_brace_count++;
                    lexer->result_symbol = LAYOUT_SEMICOLON;

                    return true;
                }
            } else {
                return false;
            }
        }
    }

    if (!valid_symbols[ARROW] && isolated_sequence(lexer, "->")) {
        if (valid_symbols[LAYOUT_CLOSE_BRACE]) {
            if (self->indent_length_stack.size > 0) {
                array_pop(&self->indent_length_stack);
            }

            lexer->result_symbol = LAYOUT_CLOSE_BRACE;

            return true;
        }

        if (valid_symbols[LAYOUT_SEMICOLON] && self->indent_length_stack.size > 1) {
            array_pop(&self->indent_length_stack);

            self->queued_close_brace_count++;
            lexer->result_symbol = LAYOUT_SEMICOLON;

            return true;
        }
    }

    if (lexer->eof(lexer)) {
        return false;
    }

    if (valid_symbols[LAYOUT_SEMICOLON] && self->indent_length_stack.size > 0) {
        uint32_t column = lexer->get_column(lexer);

        if (column == *array_back(&self->indent_length_stack)) {
            lexer->result_symbol = LAYOUT_SEMICOLON;

            return true;
        }
    }

    if (lexer->lookahead != '\n') {
        return false;
    }

    advance(lexer);

    bool next_token_is_comment = false;
    uint32_t indent_length = 0;

    for (;;) {
        if (lexer->lookahead == '\n') {
            indent_length = 0;
            advance(lexer);
        } else if (lexer->lookahead == ' ') {
            indent_length++;
            advance(lexer);
        } else if (lexer->lookahead == '\t') {
            indent_length += 8;
            advance(lexer);
        } else if (lexer->lookahead == 0) {
            if (valid_symbols[LAYOUT_SEMICOLON]) {
                lexer->result_symbol = LAYOUT_SEMICOLON;

                return true;
            }

            if (valid_symbols[LAYOUT_CLOSE_BRACE]) {
                lexer->result_symbol = LAYOUT_CLOSE_BRACE;

                return true;
            }

            return false;
        } else {
            next_token_is_comment = lexer->lookahead == '#';

            if (lexer->lookahead == '{') {
                advance(lexer);

                if (lexer->lookahead == '-') {
                    advance(lexer);
                    next_token_is_comment = lexer->lookahead != '#';
                }
            }

            if (lexer->lookahead == '-') {
                advance(lexer);
                next_token_is_comment = lexer->lookahead == '}';
            }

            break;
        }
    }

    if (!next_token_is_comment) {
        if (lexer->lookahead == ')') {
            if (valid_symbols[LAYOUT_SEMICOLON]) {
                if (self->indent_length_stack.size > 0) {
                    array_pop(&self->indent_length_stack);
                }

                self->queued_close_brace_count++;
                lexer->result_symbol = LAYOUT_SEMICOLON;

                return true;
            }

            if (valid_symbols[LAYOUT_CLOSE_BRACE]) {
                if (self->indent_length_stack.size > 0) {
                    array_pop(&self->indent_length_stack);
                }

                lexer->result_symbol = LAYOUT_CLOSE_BRACE;

                return true;
            }
        }

        if (isolated_sequence(lexer, "in")) {
            if (valid_symbols[LAYOUT_CLOSE_BRACE]) {
                if (self->indent_length_stack.size > 0) {
                    array_pop(&self->indent_length_stack);
                }

                lexer->result_symbol = LAYOUT_CLOSE_BRACE;

                return true;
            } else if (valid_symbols[LAYOUT_SEMICOLON]) {
                if (self->indent_length_stack.size > 0) {
                    array_pop(&self->indent_length_stack);
                }

                self->queued_close_brace_count++;
                lexer->result_symbol = LAYOUT_SEMICOLON;

                return true;
            }
        }

        if (self->indent_length_stack.size > 0) {
            if (indent_length < *array_back(&self->indent_length_stack)) {
                while (self->indent_length_stack.size > 0 && indent_length < *array_back(&self->indent_length_stack)) {
                    array_pop(&self->indent_length_stack);
                    self->queued_close_brace_count++;
                }

                if (valid_symbols[LAYOUT_CLOSE_BRACE]) {
                    self->queued_close_brace_count--;
                    lexer->result_symbol = LAYOUT_CLOSE_BRACE;

                    return true;
                } else if (valid_symbols[LAYOUT_SEMICOLON]) {
                    lexer->result_symbol = LAYOUT_SEMICOLON;

                    return true;
                }
            } else if (indent_length == *array_back(&self->indent_length_stack)) {
                if (valid_symbols[LAYOUT_SEMICOLON]) {
                    lexer->result_symbol = LAYOUT_SEMICOLON;

                    return true;
                }
            }
        }
    }

    return false;
}

void *tree_sitter_curry_external_scanner_create() {
    struct Scanner *scanner = ts_malloc(sizeof(struct Scanner));
    scanner_init(scanner);
    return scanner;
}

bool tree_sitter_curry_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
    struct Scanner *scanner = (struct Scanner *)(payload);

    return scanner_scan(scanner, lexer, valid_symbols);
}

unsigned tree_sitter_curry_external_scanner_serialize(void *payload, char *buffer) {
    struct Scanner *scanner = (struct Scanner *)(payload);

    return scanner_serialize(scanner, buffer);
}

void tree_sitter_curry_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {
    struct Scanner *scanner = (struct Scanner *)(payload);

    scanner_deserialize(scanner, buffer, length);
}

void tree_sitter_curry_external_scanner_destroy(void *payload) {
    struct Scanner *scanner = (struct Scanner *)(payload);

    scanner_deinit(scanner);
    ts_free(scanner);
}