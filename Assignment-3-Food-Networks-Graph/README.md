# Food Networks using Graphs and Recursion

## Overview
This project models ingredient relationships as a graph using an adjacency matrix. It analyzes how ingredients co-occur in recipes and uses recursive traversal to explore relationships and suggest substitutions.

## Graph Representation
- Nodes: Ingredients
- Edges: Frequency of co-occurrence in recipes
- Structure: Adjacency matrix A[i][j]

Each value represents how often two ingredients appear together.

## Core Functionality

### Basic Operations
- `print_ingredients()`
  - Displays list of all ingredients

- `ingredient_index(name)`
  - Maps ingredient name to matrix index

### Graph Traversal
- `related_ingredients(...)`
  - Finds directly connected ingredients

- `related_k_dist(...)`
  - Recursively finds ingredients within k steps
  - Explores graph depth-wise

### Advanced Traversal
- `related_with_restrictions(...)`
  - Finds related ingredients while excluding certain nodes
  - Avoids paths passing through restricted ingredients

### Application Logic
- Ingredient substitution
  - Suggests replacements based on graph relationships

### Testing Strategy
- Developed and validated using both small and large adjacency matrices
- Verified recursive correctness through controlled test cases

## Key Skills
Graphs, adjacency matrices, recursion, depth-first traversal, search algorithms, algorithm design
