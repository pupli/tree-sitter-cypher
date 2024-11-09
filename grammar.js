/**
 * @file Tree sitter for Cypher
 * @author Hari Bantwal <hpai.bantwal@gmail.com>
 * @license MIT
 */

const NEWLINE = /\r?\n/;

module.exports = grammar({
  name: 'cypher',

  rules: {
    // Entry point
    query: $ => repeat($.match_clause),

    // Define MATCH clause
    match_clause: $ => seq(
      'MATCH',
      field('pattern', $.pattern),
      optional($.where_clause),
      optional($.return_clause)
    ),

    // Define WHERE clause
    where_clause: $ => seq(
      'WHERE',
      field('condition', $.expression)
    ),

    // Define RETURN clause
    return_clause: $ => seq(
      'RETURN',
      field('return_items', $.return_items)
    ),

    // Define Patterns (Nodes and Relationships)
    pattern: $ => seq(
      $.node,
      repeat(seq($.relationship, $.node))
    ),

    node: $ => seq(
      '(', 
      optional($.variable),
      optional(seq(':', $.label)),
      ')'
    ),

    relationship: $ => seq(
      '-[',
      optional($.relationship_type),
      ']->'
    ),

    // Expressions for properties and conditions
    expression: $ => choice(
      $.identifier,
      $.comparison
    ),

    // Define comparison expressions (e.g., n.name = 'Alice')
    comparison: $ => seq(
      $.identifier,
      '=',
      $.string
    ),

    // Return items (for RETURN clause)
    return_items: $ => sep1(',', $.identifier),

    // Tokens
    identifier: $ => /[a-zA-Z_][a-zA-Z0-9_]*/,
    variable: $ => /[a-z][a-zA-Z0-9_]*/,
    label: $ => /[A-Z][a-zA-Z0-9_]*/,
    relationship_type: $ => /[A-Z_][A-Z0-9_]*/,
    string: $ => /'([^'\\]|\\.)*'/,
  }
});

// Utility function to parse comma-separated items
function sep1(sep, rule) {
  return seq(rule, repeat(seq(sep, rule)));
}
