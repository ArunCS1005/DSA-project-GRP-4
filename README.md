# DSA Project

This project implements a graph-based system with various functionalities such as graph initialization, editing, PageRank calculation, and keyword extraction from node descriptions.

## Features

- **Graph Initialization**: Create a graph by manually inputting nodes and their descriptions or by loading from a file.
- **Graph Editing**: Add nodes, add edges, and remove edges from the graph.
- **PageRank Calculation**: Calculate the PageRank of nodes based on their connections and keywords.
- **Keyword Extraction**: Extract keywords from node descriptions, ignoring common words.

## File Structure

- `dsa_project.cpp`: Main source code file containing the implementation of the graph and its functionalities.
- `hello.txt`, `hi.txt`, `kattahuabanda.txt`: Sample text files for loading graph data.
- `.vscode/`: Configuration files for Visual Studio Code.
  - `c_cpp_properties.json`: C/C++ properties configuration.
  - `launch.json`: Debug configuration.
  - `settings.json`: General settings.
  - `tasks.json`: Build tasks configuration.

## How to Build

To build the project, use the provided task in Visual Studio Code:

1. Open the command palette (`Ctrl+Shift+P`).
2. Select `Tasks: Run Build Task`.
3. Choose `C/C++: g++.exe build active file`.

Alternatively, you can build the project using the following command:

```sh
g++ -fdiagnostics-color=always -g [dsa_project.cpp](http://_vscodecontentref_/1) -o [dsa_project.exe](http://_vscodecontentref_/2)
