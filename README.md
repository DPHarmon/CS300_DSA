📖 CS300_DSA

Previous course upload CS300 at SNHU. This course is titled Data Structures and Algorithms. This repository contains code created in C++ during the course.

✨ Features
Implementations and demos for classic data structures and algorithms used in CS300:
Binary Search Tree operations and traversals
Hash map assignment (hashing, collisions, basic map API)
Vector sorting algorithms and experiments (Quick Sort and Merge Sort)
Additional C++ sample/project file ProjectTwo.cpp


Educational code organized by assignment/topic directories for study and reuse — designed to show understanding of how basic data structures and algorithms work.


🗂️ Repository Structure (complete top-level)

BinarySearchTree/ — C++ implementation(s) related to binary search trees. Expect: node definitions, BST insert/search/delete, traversal functions (in-order, pre-order, post-order), sample driver/tests.Purpose: Demonstrate BST concepts, operations, and typical algorithmic complexities; used for course assignments or demos.


Hash_Map_Assignment/ — C++ implementation(s) for a hash map assignment.Purpose: Implement hash table design (hash function, buckets, collision resolution such as chaining or open addressing), API (insert, find, remove), and possibly tests/performance measurements.


VectorSorting_New/ — Sorting-related C++ code using std::vector or custom arrays, likely including implementations of common sorting algorithms (Quick Sort, Merge Sort) and benchmarking.Purpose: Implement and compare sorting algorithms using vector containers and provide example usage.


ProjectTwo.cpp — Standalone C++ source file for Project Two.Purpose: Project-specific executable code that implements the advisor-course lookup application described in the Project Two rubric. Inspect the file to determine exact input format and prompts.


README.md — repository README (this file).


🔗 Flow Chart (component interaction, simplified)BinarySearchTree/       Hash_Map_Assignment/       VectorSorting_New/       |                       |                          |       +------- common APIs / data containers (std::vector, nodes, structs) -------+                                                   |                                            ProjectTwo.cpp (uses one or more modules)                                                   |                                               User / TestsEach directory contains a self-contained module (BST, HashMap, Sorting). ProjectTwo.cpp implements the advising assistant CLI and likely uses the chosen data structure to store course objects. Drivers in each folder exercise that module.
📖 Project Two — Guidelines & How This Implementation Maps to the RubricCompetency: Demonstrate ability to develop code using algorithms and data structures to solve basic programming problems.This repository’s ProjectTwo.cpp (Project Two) implements the advising-assistant CLI described in the rubric. The intended mapping to rubric requirements:
Input
Prompts user for a course data filename.
Reads the file and parses course records into course objects.
Stores course objects in the chosen data structure.




Menu
Presents a CLI menu with these options:
Load Data Structure — load course data from the specified file into the data structure.
Print Course List — print an alphanumeric (lexicographic) list of all courses in the Computer Science department (including math courses).
Print Course — prompt for a courseNumber and print that course’s title and its prerequisites (courseNumbers and titles).
Exit — terminate the program.






Loading Data Structure
Reads entries from the input file into memory as course objects and inserts them into the selected data structure, preserving needed fields (courseNumber, title, prerequisites).




Course List
Sorts course objects alphanumerically (lowest → highest) and prints the sorted list to display. Sorting is implemented either by ordered traversal of an ordered structure or by extracting to a vector and applying Quick Sort / Merge Sort.




Course Information
Prompts user for courseNumber.
Looks up the course object in the data structure and prints the course title and the prerequisites (both courseNumbers and titles).




Industry Standard Best Practices
Input validation and error messages for invalid input (bad filename, invalid menu choice, course not found).
Inline comments and clear naming conventions to improve readability.
Modular functions with clear responsibilities.




🛠️ Skills DisplayedThis repository demonstrates the following practical skills and concepts learned and applied in the DSA course:
Data structures
Binary Search Trees: node structure, insertion, search, deletion, ordered traversals
Hash Tables: hash functions, collision handling (chaining/open addressing), basic map operations (insert/find/remove)
Arrays/Vectors: using std::vector for dynamic arrays and intermediate storage




Algorithms
Sorting algorithms: Quick Sort and Merge Sort implementations and usage
Algorithm selection: when to use ordered structures vs. sorting on-demand
Complexity awareness: understanding time/space trade-offs for operations (search, insert, sort)




C++ language & standard library
Object representation for domain models (course objects/classes/structs)
Memory management fundamentals (pointers, references where applicable)
Use of STL containers (vectors, possibly lists/arrays) and algorithms




Software design & engineering practices
Modular code organization and separation of concerns
Clear function responsibilities and reusable code blocks
Input validation and user-facing error handling
Inline documentation and readable naming conventions




File I/O & CLI programming
Parsing structured text data from files into program objects
Building simple command-line menus and handling user interaction




Testing & debugging habits
Writing small drivers/examples to exercise data-structure operations
Basic runtime checks and handling of edge cases (missing files, empty inputs, not-found lookups)




❤️ AcknowledgementsCourse: CS300 — Data Structures & Algorithms (SNHU).Author: DPHarmon — repository owner and sole contributor on main.
If you want the README to include exact file formats, sample input, or sample program output derived from ProjectTwo.cpp, I can update it after inspecting that file.How do you like this response?can you output a markdown file from that reponse?📖 CS300_DSA
Previous course upload CS300 at SNHU. This course is titled Data Structures and Algorithms. This repository contains code created in C++ during the course.
✨ Features
Implementations and demos for classic data structures and algorithms used in CS300:
Binary Search Tree operations and traversals
Hash map assignment (hashing, collisions, basic map API)
Vector sorting algorithms and experiments (Quick Sort and Merge Sort)
Additional C++ sample/project file ProjectTwo.cpp


Educational code organized by assignment/topic directories for study and reuse — designed to show understanding of how basic data structures and algorithms work.


🗂️ Repository Structure (complete top-level)
BinarySearchTree/ — C++ implementation(s) related to binary search trees. Expect: node definitions, BST insert/search/delete, traversal functions (in-order, pre-order, post-order), sample driver/tests.Purpose: Demonstrate BST concepts, operations, and typical algorithmic complexities; used for course assignments or demos.


Hash_Map_Assignment/ — C++ implementation(s) for a hash map assignment.Purpose: Implement hash table design (hash function, buckets, collision resolution such as chaining or open addressing), API (insert, find, remove), and possibly tests/performance measurements.


VectorSorting_New/ — Sorting-related C++ code using std::vector or custom arrays, likely including implementations of common sorting algorithms (Quick Sort, Merge Sort) and benchmarking.Purpose: Implement and compare sorting algorithms using vector containers and provide example usage.


ProjectTwo.cpp — Standalone C++ source file for Project Two.Purpose: Project-specific executable code that implements the advisor-course lookup application described in the Project Two rubric. Inspect the file to determine exact input format and prompts.


README.md — repository README (this file).


🔗 Flow Chart (component interaction, simplified)BinarySearchTree/       Hash_Map_Assignment/       VectorSorting_New/       |                       |                          |       +------- common APIs / data containers (std::vector, nodes, structs) -------+                                                   |                                            ProjectTwo.cpp (uses one or more modules)                                                   |                                               User / TestsEach directory contains a self-contained module (BST, HashMap, Sorting). ProjectTwo.cpp implements the advising assistant CLI and likely uses the chosen data structure to store course objects. Drivers in each folder exercise that module.
📖 Project Two — Guidelines & How This Implementation Maps to the RubricCompetency: Demonstrate ability to develop code using algorithms and data structures to solve basic programming problems.This repository’s ProjectTwo.cpp (Project Two) implements the advising-assistant CLI described in the rubric. The intended mapping to rubric requirements:
Input
Prompts user for a course data filename.
Reads the file and parses course records into course objects.
Stores course objects in the chosen data structure.




Menu
Presents a CLI menu with these options:
Load Data Structure — load course data from the specified file into the data structure.
Print Course List — print an alphanumeric (lexicographic) list of all courses in the Computer Science department (including math courses).
Print Course — prompt for a courseNumber and print that course’s title and its prerequisites (courseNumbers and titles).
Exit — terminate the program.






Loading Data Structure
Reads entries from the input file into memory as course objects and inserts them into the selected data structure, preserving needed fields (courseNumber, title, prerequisites).




Course List
Sorts course objects alphanumerically (lowest → highest) and prints the sorted list to display. Sorting is implemented either by ordered traversal of an ordered structure or by extracting to a vector and applying Quick Sort / Merge Sort.




Course Information
Prompts user for courseNumber.
Looks up the course object in the data structure and prints the course title and the prerequisites (both courseNumbers and titles).




Industry Standard Best Practices
Input validation and error messages for invalid input (bad filename, invalid menu choice, course not found).
Inline comments and clear naming conventions to improve readability.
Modular functions with clear responsibilities.




🛠️ Skills DisplayedThis repository demonstrates the following practical skills and concepts learned and applied in the DSA course:
Data structures
Binary Search Trees: node structure, insertion, search, deletion, ordered traversals
Hash Tables: hash functions, collision handling (chaining/open addressing), basic map operations (insert/find/remove)
Arrays/Vectors: using std::vector for dynamic arrays and intermediate storage




Algorithms
Sorting algorithms: Quick Sort and Merge Sort implementations and usage
Algorithm selection: when to use ordered structures vs. sorting on-demand
Complexity awareness: understanding time/space trade-offs for operations (search, insert, sort)




C++ language & standard library
Object representation for domain models (course objects/classes/structs)
Memory management fundamentals (pointers, references where applicable)
Use of STL containers (vectors, possibly lists/arrays) and algorithms




Software design & engineering practices
Modular code organization and separation of concerns
Clear function responsibilities and reusable code blocks
Input validation and user-facing error handling
Inline documentation and readable naming conventions




File I/O & CLI programming
Parsing structured text data from files into program objects
Building simple command-line menus and handling user interaction




Testing & debugging habits
Writing small drivers/examples to exercise data-structure operations
Basic runtime checks and handling of edge cases (missing files, empty inputs, not-found lookups)




❤️ AcknowledgementsCourse: CS300 — Data Structures & Algorithms (SNHU).Author: DPHarmon — repository owner and sole contributor on main.
