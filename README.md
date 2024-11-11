# tree-sitter-cypher

A Tree-sitter parser for the Cypher query language, based on the [Cypher Style Guide](https://opencypher.org/resources) and the [openCypher grammar](https://github.com/opencypher/openCypher/tree/master/tools/grammar). This parser is designed for syntax highlighting and editor support, such as integration with a Zed extension.

---

## Table of Contents
- [Overview](#overview)
- [Installation and Setup](#installation-and-setup)
- [Updating `grammar.js` with Cypher Grammar](#updating-grammarjs-with-cypher-grammar)
- [Running Tree-sitter Commands](#running-tree-sitter-commands)
- [Pushing to GitHub](#pushing-to-github)
- [Creating a Zed Extension](#creating-a-zed-extension)

---

## Overview

This project implements a Tree-sitter parser for Cypher, the query language for Neo4j, following [openCypher standards](https://github.com/opencypher/openCypher) and the [Cypher Style Guide](https://opencypher.org/resources).

## Installation and Setup

To start, make sure you have Node.js and npm installed, as Tree-sitter uses npm for setup. You’ll also need the Tree-sitter CLI tool, which can be installed via npm.

### Step 1: Install Node.js and npm

Download and install [Node.js](https://nodejs.org/), which includes npm.

### Step 2: Install Tree-sitter CLI

Install the Tree-sitter CLI globally:
```bash
npm install -g tree-sitter-cli
```


### Step 3: Create the Project Directory

Create a new directory for the Tree-sitter parser:

```bash
mkdir tree-sitter-cypher
cd tree-sitter-cypher
```

### Step 4: Initialize the Tree-sitter Project

Run the following command to initialize your Tree-sitter project. This creates a grammar.js file and package.json:

```bash
tree-sitter init
```

### Step 5: Updating grammar.js with Cypher Grammar

## Step 6 Updating `grammar.js` with Cypher Grammar

The grammar for Cypher can be derived from openCypher’s official resources:

- Refer to the [openCypher grammar](https://github.com/opencypher/openCypher/tree/master/tools/grammar) for details on Cypher syntax.
- Follow the [Cypher Style Guide](https://opencypher.org/resources) to ensure that your `grammar.js` aligns with Cypher’s conventions for readability and consistency.

Update `grammar.js` to define Cypher-specific constructs such as `MATCH`, `WHERE`, `RETURN`, and nodes/relationships. For example, here’s a sample snippet:

```javascript
module.exports = grammar({
  name: 'cypher',
  rules: {
      cypher: ($) => seq($.statement, optional(';')),
      statement: ($) => $.query,
      query: $ => choice($.regular_query, $.standalone_call)
      ...
  }  

});
```

## Step 7: Running Tree-sitter Commands

Once `grammar.js` is updated, you can use the following commands to generate, build, and test your parser.

### Generate the Parser

```bash
tree-sitter generate
```

### Build the Parser

```bash
tree-sitter build
```

## Step 8: Push to GitHub



## Creating a Zed Extension

To use this Tree-sitter parser in a Zed extension for syntax highlighting and other features, refer to the [cypher project on GitHub](https://github.com/pupli/cypher).

For more information on creating Zed extensions, refer to the [official Zed documentation](https://zed.dev/docs/extensions).




















