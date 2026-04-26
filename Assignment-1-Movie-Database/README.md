# Movie Review Database (Linked Lists)

## Overview
Implemented a dynamic movie review database in C using custom structs and singly linked lists to manage structured data and support query operations.

## System Design
The system models:
- Movies (title, studio, year, box office, score)
- Cast members (name, salary)
- Relationships using linked structures

## Core Functionality

### Data Structure Implementation
- Designed compound data types (`MovieReview`, `CastList`, `ReviewNode`)
- Managed hierarchical relationships using nested linked lists

### Linked List Operations
- Insertion with duplicate detection
- Deletion with proper memory cleanup
- Traversal and aggregation
- Full list deallocation

### Query & Processing
- Search by composite key (title, studio, year)
- Filtering by studio and score thresholds
- Aggregation of box office totals

### Advanced Logic
- Sorted linked list by title
- Maintained cast list sorted by salary
- Computed average earnings per actor (`whosTheStar`)

## Key Skills
Linked lists, pointers, memory management, data modeling, algorithm design
