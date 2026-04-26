
# Movie Review Database (Linked Lists in C)

## Overview
This project implements a movie review database in C using custom compound data types and singly linked lists. The system stores, manages, and queries movie data, simulating a basic data management application.

## Data Structures
- `CastList`: Linked list storing cast member name and salary
- `MovieReview`: Struct storing title, studio, year, box office, score, and cast list
- `ReviewNode`: Linked list node containing a MovieReview

## Core Functionality

### Linked List Operations
- `newMovieReviewNode(...)`
  - Allocates memory and initializes a new movie review node

- `insertMovieReview(...)`
  - Inserts a new review at the head of the list
  - Prevents duplicate entries using search

- `deleteMovieReview(...)`
  - Removes a movie from the list and frees memory

- `deleteReviewList(...)`
  - Frees the entire linked list

### Search & Query
- `findMovieReview(...)`
  - Searches list by title, studio, and year

- `queryReviewsByStudio(...)`
  - Filters and prints movies from a given studio

- `queryReviewsByScore(...)`
  - Returns movies above a given score threshold

### Updates & Aggregation
- `updateMovieReview(...)`
  - Updates box office and score for a specific movie

- `countReviews(...)`
  - Counts total number of nodes in the list

- `printMovieReviews(...)`
  - Prints all reviews and returns total box office

### Advanced Features
- `sortReviewsByTitle(...)`
  - Sorts linked list alphabetically

- `insertCastMember(...)`
  - Inserts cast members sorted by salary (descending)

- `whosTheStar(...)`
  - Computes average movie earnings per actor and identifies the top performer

## Key Skills
Linked lists, dynamic memory allocation, structs, pointer manipulation, data processing, algorithm design
