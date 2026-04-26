# Music Sequencer using Binary Search Trees

## Overview
Built a time-based music sequencing engine using a Binary Search Tree (BST), where each node represents a musical note ordered by its playback position.

## Data Representation
Each note stores:
- Frequency (pitch)
- Bar (time segment)
- Index within bar

Unique ordering key:
key = (10.0 * bar) + index

## Core Functionality

### BST Implementation
- Node insertion maintaining strict ordering
- Search using computed key
- Full deletion logic:
  - Leaf nodes
  - Nodes with one child
  - Nodes with two children (in-order successor)

### Traversals
- In-order → chronological playback
- Pre-order / Post-order → structural inspection

### Memory Management
- Recursive deletion of entire tree

## Sequencer Features
- Playlist generation via traversal
- Reverse song transformation
- Harmonization:
  - Inserts shifted notes in frequency (k semitones)
  - Adjusts timing offset

## Key Skills
BSTs, recursion, tree algorithms, pointer manipulation, memory management
