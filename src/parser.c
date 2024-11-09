#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 42
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 29
#define ALIAS_COUNT 0
#define TOKEN_COUNT 16
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 3
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 4

enum ts_symbol_identifiers {
  anon_sym_MATCH = 1,
  anon_sym_WHERE = 2,
  anon_sym_RETURN = 3,
  anon_sym_LPAREN = 4,
  anon_sym_COLON = 5,
  anon_sym_RPAREN = 6,
  anon_sym_DASH_LBRACK = 7,
  anon_sym_RBRACK_DASH_GT = 8,
  anon_sym_EQ = 9,
  anon_sym_COMMA = 10,
  sym_identifier = 11,
  sym_variable = 12,
  sym_label = 13,
  sym_relationship_type = 14,
  sym_string = 15,
  sym_query = 16,
  sym_match_clause = 17,
  sym_where_clause = 18,
  sym_return_clause = 19,
  sym_pattern = 20,
  sym_node = 21,
  sym_relationship = 22,
  sym_expression = 23,
  sym_comparison = 24,
  sym_return_items = 25,
  aux_sym_query_repeat1 = 26,
  aux_sym_pattern_repeat1 = 27,
  aux_sym_return_items_repeat1 = 28,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_MATCH] = "MATCH",
  [anon_sym_WHERE] = "WHERE",
  [anon_sym_RETURN] = "RETURN",
  [anon_sym_LPAREN] = "(",
  [anon_sym_COLON] = ":",
  [anon_sym_RPAREN] = ")",
  [anon_sym_DASH_LBRACK] = "-[",
  [anon_sym_RBRACK_DASH_GT] = "]->",
  [anon_sym_EQ] = "=",
  [anon_sym_COMMA] = ",",
  [sym_identifier] = "identifier",
  [sym_variable] = "variable",
  [sym_label] = "label",
  [sym_relationship_type] = "relationship_type",
  [sym_string] = "string",
  [sym_query] = "query",
  [sym_match_clause] = "match_clause",
  [sym_where_clause] = "where_clause",
  [sym_return_clause] = "return_clause",
  [sym_pattern] = "pattern",
  [sym_node] = "node",
  [sym_relationship] = "relationship",
  [sym_expression] = "expression",
  [sym_comparison] = "comparison",
  [sym_return_items] = "return_items",
  [aux_sym_query_repeat1] = "query_repeat1",
  [aux_sym_pattern_repeat1] = "pattern_repeat1",
  [aux_sym_return_items_repeat1] = "return_items_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_MATCH] = anon_sym_MATCH,
  [anon_sym_WHERE] = anon_sym_WHERE,
  [anon_sym_RETURN] = anon_sym_RETURN,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_DASH_LBRACK] = anon_sym_DASH_LBRACK,
  [anon_sym_RBRACK_DASH_GT] = anon_sym_RBRACK_DASH_GT,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [sym_identifier] = sym_identifier,
  [sym_variable] = sym_variable,
  [sym_label] = sym_label,
  [sym_relationship_type] = sym_relationship_type,
  [sym_string] = sym_string,
  [sym_query] = sym_query,
  [sym_match_clause] = sym_match_clause,
  [sym_where_clause] = sym_where_clause,
  [sym_return_clause] = sym_return_clause,
  [sym_pattern] = sym_pattern,
  [sym_node] = sym_node,
  [sym_relationship] = sym_relationship,
  [sym_expression] = sym_expression,
  [sym_comparison] = sym_comparison,
  [sym_return_items] = sym_return_items,
  [aux_sym_query_repeat1] = aux_sym_query_repeat1,
  [aux_sym_pattern_repeat1] = aux_sym_pattern_repeat1,
  [aux_sym_return_items_repeat1] = aux_sym_return_items_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_MATCH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_WHERE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RETURN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK_DASH_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_variable] = {
    .visible = true,
    .named = true,
  },
  [sym_label] = {
    .visible = true,
    .named = true,
  },
  [sym_relationship_type] = {
    .visible = true,
    .named = true,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [sym_query] = {
    .visible = true,
    .named = true,
  },
  [sym_match_clause] = {
    .visible = true,
    .named = true,
  },
  [sym_where_clause] = {
    .visible = true,
    .named = true,
  },
  [sym_return_clause] = {
    .visible = true,
    .named = true,
  },
  [sym_pattern] = {
    .visible = true,
    .named = true,
  },
  [sym_node] = {
    .visible = true,
    .named = true,
  },
  [sym_relationship] = {
    .visible = true,
    .named = true,
  },
  [sym_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_comparison] = {
    .visible = true,
    .named = true,
  },
  [sym_return_items] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_query_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_pattern_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_return_items_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_condition = 1,
  field_pattern = 2,
  field_return_items = 3,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_condition] = "condition",
  [field_pattern] = "pattern",
  [field_return_items] = "return_items",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 1},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_pattern, 1},
  [1] =
    {field_condition, 1},
  [2] =
    {field_return_items, 1},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(22);
      ADVANCE_MAP(
        '\'', 1,
        '(', 26,
        ')', 28,
        ',', 32,
        '-', 17,
        ':', 27,
        '=', 31,
        'M', 4,
        'R', 8,
        'W', 10,
        ']', 2,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(34);
      END_STATE();
    case 1:
      if (lookahead == '\'') ADVANCE(37);
      if (lookahead == '\\') ADVANCE(21);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 2:
      if (lookahead == '-') ADVANCE(3);
      END_STATE();
    case 3:
      if (lookahead == '>') ADVANCE(30);
      END_STATE();
    case 4:
      if (lookahead == 'A') ADVANCE(14);
      END_STATE();
    case 5:
      if (lookahead == 'C') ADVANCE(9);
      END_STATE();
    case 6:
      if (lookahead == 'E') ADVANCE(13);
      END_STATE();
    case 7:
      if (lookahead == 'E') ADVANCE(24);
      END_STATE();
    case 8:
      if (lookahead == 'E') ADVANCE(15);
      END_STATE();
    case 9:
      if (lookahead == 'H') ADVANCE(23);
      END_STATE();
    case 10:
      if (lookahead == 'H') ADVANCE(6);
      END_STATE();
    case 11:
      if (lookahead == 'N') ADVANCE(25);
      END_STATE();
    case 12:
      if (lookahead == 'R') ADVANCE(11);
      END_STATE();
    case 13:
      if (lookahead == 'R') ADVANCE(7);
      END_STATE();
    case 14:
      if (lookahead == 'T') ADVANCE(5);
      END_STATE();
    case 15:
      if (lookahead == 'T') ADVANCE(16);
      END_STATE();
    case 16:
      if (lookahead == 'U') ADVANCE(12);
      END_STATE();
    case 17:
      if (lookahead == '[') ADVANCE(29);
      END_STATE();
    case 18:
      if (lookahead == ']') ADVANCE(2);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(18);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(36);
      END_STATE();
    case 19:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(19);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(33);
      END_STATE();
    case 20:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(20);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(35);
      END_STATE();
    case 21:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(1);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_MATCH);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_WHERE);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_RETURN);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_DASH_LBRACK);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_RBRACK_DASH_GT);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(33);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_variable);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(34);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_label);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(35);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym_relationship_type);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(36);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym_string);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 19},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 19},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 18},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 19},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 20},
  [40] = {.lex_state = 20},
  [41] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_MATCH] = ACTIONS(1),
    [anon_sym_WHERE] = ACTIONS(1),
    [anon_sym_RETURN] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_DASH_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK_DASH_GT] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [sym_variable] = ACTIONS(1),
    [sym_string] = ACTIONS(1),
  },
  [1] = {
    [sym_query] = STATE(41),
    [sym_match_clause] = STATE(11),
    [aux_sym_query_repeat1] = STATE(11),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_MATCH] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 4,
    ACTIONS(9), 1,
      anon_sym_DASH_LBRACK,
    STATE(3), 1,
      aux_sym_pattern_repeat1,
    STATE(29), 1,
      sym_relationship,
    ACTIONS(7), 4,
      ts_builtin_sym_end,
      anon_sym_MATCH,
      anon_sym_WHERE,
      anon_sym_RETURN,
  [16] = 4,
    ACTIONS(9), 1,
      anon_sym_DASH_LBRACK,
    STATE(4), 1,
      aux_sym_pattern_repeat1,
    STATE(29), 1,
      sym_relationship,
    ACTIONS(11), 4,
      ts_builtin_sym_end,
      anon_sym_MATCH,
      anon_sym_WHERE,
      anon_sym_RETURN,
  [32] = 4,
    ACTIONS(15), 1,
      anon_sym_DASH_LBRACK,
    STATE(4), 1,
      aux_sym_pattern_repeat1,
    STATE(29), 1,
      sym_relationship,
    ACTIONS(13), 4,
      ts_builtin_sym_end,
      anon_sym_MATCH,
      anon_sym_WHERE,
      anon_sym_RETURN,
  [48] = 5,
    ACTIONS(20), 1,
      anon_sym_WHERE,
    ACTIONS(22), 1,
      anon_sym_RETURN,
    STATE(13), 1,
      sym_where_clause,
    STATE(27), 1,
      sym_return_clause,
    ACTIONS(18), 2,
      ts_builtin_sym_end,
      anon_sym_MATCH,
  [65] = 1,
    ACTIONS(24), 5,
      ts_builtin_sym_end,
      anon_sym_MATCH,
      anon_sym_WHERE,
      anon_sym_RETURN,
      anon_sym_DASH_LBRACK,
  [73] = 1,
    ACTIONS(26), 5,
      ts_builtin_sym_end,
      anon_sym_MATCH,
      anon_sym_WHERE,
      anon_sym_RETURN,
      anon_sym_DASH_LBRACK,
  [81] = 1,
    ACTIONS(28), 5,
      ts_builtin_sym_end,
      anon_sym_MATCH,
      anon_sym_WHERE,
      anon_sym_RETURN,
      anon_sym_DASH_LBRACK,
  [89] = 1,
    ACTIONS(13), 5,
      ts_builtin_sym_end,
      anon_sym_MATCH,
      anon_sym_WHERE,
      anon_sym_RETURN,
      anon_sym_DASH_LBRACK,
  [97] = 1,
    ACTIONS(30), 5,
      ts_builtin_sym_end,
      anon_sym_MATCH,
      anon_sym_WHERE,
      anon_sym_RETURN,
      anon_sym_DASH_LBRACK,
  [105] = 3,
    ACTIONS(5), 1,
      anon_sym_MATCH,
    ACTIONS(32), 1,
      ts_builtin_sym_end,
    STATE(12), 2,
      sym_match_clause,
      aux_sym_query_repeat1,
  [116] = 3,
    ACTIONS(34), 1,
      ts_builtin_sym_end,
    ACTIONS(36), 1,
      anon_sym_MATCH,
    STATE(12), 2,
      sym_match_clause,
      aux_sym_query_repeat1,
  [127] = 3,
    ACTIONS(22), 1,
      anon_sym_RETURN,
    STATE(30), 1,
      sym_return_clause,
    ACTIONS(39), 2,
      ts_builtin_sym_end,
      anon_sym_MATCH,
  [138] = 3,
    ACTIONS(43), 1,
      anon_sym_COMMA,
    STATE(15), 1,
      aux_sym_return_items_repeat1,
    ACTIONS(41), 2,
      ts_builtin_sym_end,
      anon_sym_MATCH,
  [149] = 3,
    ACTIONS(43), 1,
      anon_sym_COMMA,
    STATE(17), 1,
      aux_sym_return_items_repeat1,
    ACTIONS(45), 2,
      ts_builtin_sym_end,
      anon_sym_MATCH,
  [160] = 2,
    ACTIONS(49), 1,
      anon_sym_EQ,
    ACTIONS(47), 3,
      ts_builtin_sym_end,
      anon_sym_MATCH,
      anon_sym_RETURN,
  [169] = 3,
    ACTIONS(53), 1,
      anon_sym_COMMA,
    STATE(17), 1,
      aux_sym_return_items_repeat1,
    ACTIONS(51), 2,
      ts_builtin_sym_end,
      anon_sym_MATCH,
  [180] = 3,
    ACTIONS(56), 1,
      anon_sym_LPAREN,
    STATE(2), 1,
      sym_node,
    STATE(5), 1,
      sym_pattern,
  [190] = 3,
    ACTIONS(58), 1,
      anon_sym_COLON,
    ACTIONS(60), 1,
      anon_sym_RPAREN,
    ACTIONS(62), 1,
      sym_variable,
  [200] = 3,
    ACTIONS(64), 1,
      sym_identifier,
    STATE(21), 1,
      sym_expression,
    STATE(22), 1,
      sym_comparison,
  [210] = 1,
    ACTIONS(66), 3,
      ts_builtin_sym_end,
      anon_sym_MATCH,
      anon_sym_RETURN,
  [216] = 1,
    ACTIONS(47), 3,
      ts_builtin_sym_end,
      anon_sym_MATCH,
      anon_sym_RETURN,
  [222] = 1,
    ACTIONS(68), 3,
      ts_builtin_sym_end,
      anon_sym_MATCH,
      anon_sym_RETURN,
  [228] = 1,
    ACTIONS(51), 3,
      ts_builtin_sym_end,
      anon_sym_MATCH,
      anon_sym_COMMA,
  [234] = 2,
    ACTIONS(70), 1,
      sym_identifier,
    STATE(31), 1,
      sym_return_items,
  [241] = 2,
    ACTIONS(72), 1,
      anon_sym_COLON,
    ACTIONS(74), 1,
      anon_sym_RPAREN,
  [248] = 1,
    ACTIONS(39), 2,
      ts_builtin_sym_end,
      anon_sym_MATCH,
  [253] = 2,
    ACTIONS(76), 1,
      anon_sym_RBRACK_DASH_GT,
    ACTIONS(78), 1,
      sym_relationship_type,
  [260] = 2,
    ACTIONS(56), 1,
      anon_sym_LPAREN,
    STATE(9), 1,
      sym_node,
  [267] = 1,
    ACTIONS(80), 2,
      ts_builtin_sym_end,
      anon_sym_MATCH,
  [272] = 1,
    ACTIONS(82), 2,
      ts_builtin_sym_end,
      anon_sym_MATCH,
  [277] = 1,
    ACTIONS(84), 1,
      sym_identifier,
  [281] = 1,
    ACTIONS(86), 1,
      anon_sym_RPAREN,
  [285] = 1,
    ACTIONS(88), 1,
      sym_string,
  [289] = 1,
    ACTIONS(90), 1,
      anon_sym_RPAREN,
  [293] = 1,
    ACTIONS(92), 1,
      anon_sym_LPAREN,
  [297] = 1,
    ACTIONS(94), 1,
      anon_sym_LPAREN,
  [301] = 1,
    ACTIONS(96), 1,
      anon_sym_RBRACK_DASH_GT,
  [305] = 1,
    ACTIONS(98), 1,
      sym_label,
  [309] = 1,
    ACTIONS(100), 1,
      sym_label,
  [313] = 1,
    ACTIONS(102), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 16,
  [SMALL_STATE(4)] = 32,
  [SMALL_STATE(5)] = 48,
  [SMALL_STATE(6)] = 65,
  [SMALL_STATE(7)] = 73,
  [SMALL_STATE(8)] = 81,
  [SMALL_STATE(9)] = 89,
  [SMALL_STATE(10)] = 97,
  [SMALL_STATE(11)] = 105,
  [SMALL_STATE(12)] = 116,
  [SMALL_STATE(13)] = 127,
  [SMALL_STATE(14)] = 138,
  [SMALL_STATE(15)] = 149,
  [SMALL_STATE(16)] = 160,
  [SMALL_STATE(17)] = 169,
  [SMALL_STATE(18)] = 180,
  [SMALL_STATE(19)] = 190,
  [SMALL_STATE(20)] = 200,
  [SMALL_STATE(21)] = 210,
  [SMALL_STATE(22)] = 216,
  [SMALL_STATE(23)] = 222,
  [SMALL_STATE(24)] = 228,
  [SMALL_STATE(25)] = 234,
  [SMALL_STATE(26)] = 241,
  [SMALL_STATE(27)] = 248,
  [SMALL_STATE(28)] = 253,
  [SMALL_STATE(29)] = 260,
  [SMALL_STATE(30)] = 267,
  [SMALL_STATE(31)] = 272,
  [SMALL_STATE(32)] = 277,
  [SMALL_STATE(33)] = 281,
  [SMALL_STATE(34)] = 285,
  [SMALL_STATE(35)] = 289,
  [SMALL_STATE(36)] = 293,
  [SMALL_STATE(37)] = 297,
  [SMALL_STATE(38)] = 301,
  [SMALL_STATE(39)] = 305,
  [SMALL_STATE(40)] = 309,
  [SMALL_STATE(41)] = 313,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_query, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pattern, 1, 0, 0),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pattern, 2, 0, 0),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pattern_repeat1, 2, 0, 0),
  [15] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_pattern_repeat1, 2, 0, 0), SHIFT_REPEAT(28),
  [18] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_match_clause, 2, 0, 1),
  [20] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [22] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [24] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 2, 0, 0),
  [26] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 4, 0, 0),
  [28] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 3, 0, 0),
  [30] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_node, 5, 0, 0),
  [32] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_query, 1, 0, 0),
  [34] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_query_repeat1, 2, 0, 0),
  [36] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_query_repeat1, 2, 0, 0), SHIFT_REPEAT(18),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_match_clause, 3, 0, 1),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_return_items, 1, 0, 0),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_return_items, 2, 0, 0),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression, 1, 0, 0),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_return_items_repeat1, 2, 0, 0),
  [53] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_return_items_repeat1, 2, 0, 0), SHIFT_REPEAT(32),
  [56] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [58] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [60] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [62] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [64] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [66] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_where_clause, 2, 0, 2),
  [68] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comparison, 3, 0, 0),
  [70] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [72] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [74] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [76] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [78] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [80] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_match_clause, 4, 0, 1),
  [82] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_return_clause, 2, 0, 3),
  [84] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [86] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [88] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [90] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [92] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_relationship, 2, 0, 0),
  [94] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_relationship, 3, 0, 0),
  [96] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [98] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [100] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [102] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_cypher(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
