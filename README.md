# :mortar_board: CS300_DSA

Previous course work for CS300 (Data Structures & Algorithms) at SNHU. This repository contains C++ implementations and demo code created during the course to demonstrate core DSA concepts and practical problem solving.

---
### :clipboard: Features

* Clean, focused implementations and example drivers for:
  * Binary Search Tree operations and traversals
  * Hash map implementation (hashing and collision handling)
  * Vector-based sorting experiments (Quick Sort, Merge Sort)
  * ProjectTwo.cpp — a course/advisor lookup CLI used for the course project
* Educational code organized by assignment/topic for study and reuse

---
### :fireworks: Skills Displayed

* Data structures: BST, hash tables, arrays/vectors
* Algorithms: Quick Sort, Merge Sort, ordered traversal usage
* C++ fundamentals: classes/structs, pointers/references, STL containers, file I/O
* Software design: modular code, clear naming, input validation, CLI interaction
* Testing/debugging: small drivers, edge case handling, basic runtime checks

---
### :computer: How the code shows my ability

This codebase demonstrates practical understanding and use of:

* Binary Search Tree
  * Building node structures, insertion, search, deletion
  * Ordered traversals (in-order traversal to produce sorted output)
  * Using BST properties for efficient lookups and ordered listings

* Hash Map
  * Designing a hash function and managing buckets
  * Handling collisions (chaining or open addressing) and implementing basic map operations (insert/find/remove)
  * Demonstrating average-case O(1) lookup behavior and trade-offs versus ordered structures

* Vector Sorting Methods
  * Implementing and comparing Quick Sort and Merge Sort on std::vector data
  * Extracting unsorted data into vectors and using sorting when an ordered structure isn’t maintained incrementally
  * Showing algorithmic trade-offs and when to prefer sorting versus using ordered containers

These modules together show both theoretical understanding (complexities, trade-offs) and practical implementation skills (memory management, API design, testing).

---
## Project Two — Summary of Requirements
ProjectTwo is an advising-assistant CLI that implements the following behaviors:
* Load Data Structure
  * Prompt for and read a course data file
  * Parse course records and insert them into the chosen data structure

* Print Course List
  * Produce an alphanumeric list of all relevant courses (e.g., CS and math) — either via ordered structure traversal or by sorting a vector of courses

* Print Course
  * Given a courseNumber, print that course’s title and its prerequisites (course numbers and titles)

* Exit
  * Terminate the program

ProjectTwo emphasizes correct parsing, storing course objects with necessary fields (courseNumber, title, prerequisites), lookup functionality, and clean user interaction with input validation and error messages.

---
### :rose: Acknowledgements
Course: CS300 — Data Structures & Algorithms (SNHU)

Author: Dylan P. Harmon
