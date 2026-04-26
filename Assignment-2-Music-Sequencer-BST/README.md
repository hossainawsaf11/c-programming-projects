# Music Sequencer using Binary Search Trees

## Overview
This project implements the core data structure of a music sequencer using a Binary Search Tree (BST). Each node represents a musical note, uniquely identified by its timing within a song.

## Data Representation
Each note contains:
- Frequency (pitch)
- Bar number
- Index within bar (0.0 to 1.0)

Key used for BST:
key = (10.0 * bar) + index


This ensures all notes are uniquely ordered in time.

## Core Functionality

### BST Operations
- Node creation and insertion
  - Inserts notes while maintaining BST ordering

- Search
  - Locates notes using computed key

- Deletion (all cases implemented)
  - Leaf node
  - One child
  - Two children (in-order successor replacement)

- Tree Traversals
  - In-order (chronological playback order)
  - Pre-order
  - Post-order

- Memory Management
  - Full BST deletion and memory cleanup

### Sequencer Features
- Playlist generation
  - Traverses BST to produce ordered sequence of notes

- Reverse Song
  - Reorders notes so playback occurs in reverse time

- Harmonize Function
  - For each note:
    - Adds a new note shifted in frequency (k semitones)
    - Shifts timing by a specified amount
  - Effectively generates layered sound

## Key Skills
Binary search trees, recursion, tree traversal, pointer manipulation, memory management, algorithmic problem solving
