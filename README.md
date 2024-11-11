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
