const NEWLINE = /\r?\n/;

module.exports = grammar({
  name: "cypher",

  extras: ($) => [$.comment, /\s/],

  rules: {
    source_file: ($) => repeat(choice($.comment, $.variable)),

    comment: ($) => token(seq("#", /.*/)),

    variable: ($) =>
      seq(field("name", $.identifier), "=", optional(field("value", $.value))),

    interpolated_variable: ($) =>
      choice(
        seq("$", $.identifier),
        seq("${", $.identifier, "}"),
        seq("${", $.identifier, ":-", $.identifier, "}"),
        seq("$(", $.shell_command, ")"),
      ),

    shell_command: ($) => /[^$()]+/,

    identifier: ($) => /[A-Z_][0-9a-zA-Z_]*/,

    value: ($) =>
      choice(
        $.string_interpolated,
        $.string_literal,
        $.url,
        $.bool,
        $.integer,
        $.raw_value,
      ),

    bool: ($) => choice("true", "false"),

    integer: ($) => /\d+/,

    string_interpolated: ($) =>
      seq('"', repeat(choice($._interpolated_content, $.escape_sequence)), '"'),

    _interpolated_content: ($) => choice(/[^"$\\]+/, $.interpolated_variable),

    string_literal: ($) =>
      seq("'", repeat(choice(/[^'\\]+/, $.escape_sequence)), "'"),

    escape_sequence: ($) => token(seq("\\", /[nrtfb"'\$\\]/)),

    url: ($) =>
      token(
        seq(
          /https?:\/\//,
          /[a-zA-Z0-9.-]+/,
          optional(seq(":", /\d+/)),
          optional(seq("/", /[^\s#]*/)),
          optional(seq("#", /[^\s]*/)),
        ),
      ),

    raw_value: ($) => token(prec(-1, /[^#=\n]+/)),
  },
});