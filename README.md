## Data Structures and Algorithms 

The original credit goes to the [coding-interview-university](https://github.com/jwasham/coding-interview-university).

---

## Table of Contents
- [Data Structures](#data-structures)
  + [Arrays](#arrays)
  + [Linked Lists](#linked-lists)
  + [Stack](#stack)
  + [Queue](#queue)
  + [Hash Table](#hash-table)
- [Trees](#trees) 
  + [Binary Tree](#binary-tree)
  + [Binary Search Tree](#binary-search-tree)
  + [Self Balancing BST](#self-balancing-bst)
  + [Heap, Priority Queue, Binary Heap](#heap)
- [Graph](#graph) 
  + General Knowledge
    + directed & undirected graph
    + adjacency matrix & adjacency list
  + [Traversals](#traversals)
  + [Detect Cycles](#detect-cycles)
  + [Disjoint Set or Union-Find](#disjoint-set)
- [Sorting](#sorting)
  + bubble sort
  + selection sort
  + insertion sort
  + merge sort
  + quick sort
  + heap sort
  + counting sort
- [Practice Problems](#practice-problems)
---

## Data Structures
- ### Arrays
  - [ ] About Arrays:
    - [ ] [Introduction to Arrays](https://www.geeksforgeeks.org/introduction-to-arrays/)
    - [x] [Arrays (video)](https://www.coursera.org/lecture/data-structures/arrays-OsBSF)
    - [x] [Dynamic Arrays (video)](https://www.coursera.org/lecture/data-structures/dynamic-arrays-EwbnV)
    - [x] [Jagged Arrays (video)](https://www.youtube.com/watch?v=1jtrQqYpt7g)
  - [x] Implement a vector (mutable array with automatic resizing):
    - [x] size() - number of items
    - [x] New raw data array with allocated memory (default = 16, or power of 2 - 16, 32, 64, ...)
    - [x] capacity() - number of items it can hold
    - [x] is_empty()
    - [x] at(index) - returns item at given index, blows up if index out of bounds
    - [x] push(item)
    - [x] insert(index, item) - inserts item at index, shifts that index's value and trailing elements to the right
    - [x] prepend(item) - inserts item at index 0
    - [x] pop() - remove from end, return value
    - [x] delete(index) - delete item at index, shifting all trailing elements left
    - [x] remove(item) - looks for value and removes index holding it (even if in multiple places)
    - [x] find(item) - looks for value and returns first index with that value, -1 if not found
    - [x] resize(new_capacity) // private function
      - [x] when you reach capacity, resize to double the size
      - [x] when popping an item, if size is 1/4 of capacity, resize to half
  - [x] Time
    - O(1) to add/remove at end (amortized for allocations for more space), index, or update
    - O(n) to insert/remove elsewhere
  - [x] Space
    - contiguous in memory, so proximity helps performance
    - space needed = (array capacity, which is >= n) * size of item, but even if 2n, still O(n)

- ### Linked Lists
  - [x] About Linked Lists:
    - [x] [Singly Linked Lists Tutorial - What is a Linked List?](https://www.youtube.com/watch?v=HB7TcYklBHY)
    - [x] [Singly Linked Lists (video)](https://www.coursera.org/lecture/data-structures/singly-linked-lists-kHhgK)
    - [x] [CS 61B - Linked Lists 1 (video)](https://archive.org/details/ucberkeley_webcast_htzJdKoEmO0)
    - [x] [CS 61B - Linked Lists 2 (video)](https://archive.org/details/ucberkeley_webcast_-c4I3gFYe3w)
    - [x] [C code (video)](https://www.youtube.com/watch?v=QN6FPiD0Gzo) - just portions about *Node struct* and *memory allocation*.
  - [x] [Linked List vs Arrays](https://www.geeksforgeeks.org/linked-list-vs-array/?ref=lbp)
    - [x] [Core Linked Lists Vs Arrays (video)](https://www.coursera.org/lecture/data-structures-optimizing-performance/core-linked-lists-vs-arrays-rjBs9)
    - [x] [In The Real World Linked Lists Vs Arrays (video)](https://www.coursera.org/lecture/data-structures-optimizing-performance/in-the-real-world-lists-vs-arrays-QUaUd)
  - [x] Vector vs. List - [why you should avoid linked lists (video)](https://www.youtube.com/watch?v=YQs6IC-vgmo) (this is from [GoingNative 2012 - Day 1 - C++11 style](https://youtu.be/m0H5bUPfwn8?t=2690))
  - [ ] [Pointers to Pointers](https://www.eskimo.com/~scs/cclass/int/sx8.html) - for passing a pointer to a function that may change the address where that pointer points
  - [x] Implement Singly-Linked List (with and without tail pointer)
    - [x] size() - returns number of data elements in list
    - [x] empty() - bool returns true if empty
    - [x] value_at(index) - returns the value of the nth item (starting at 0 for first)
    - [x] push_front(value) - adds an item to the front of the list
    - [x] pop_front() - remove front item and return its value
    - [x] push_back(value) - adds an item at the end
    - [x] pop_back() - removes end item and returns its value
    - [x] front() - get value of front item
    - [x] back() - get value of end item
    - [x] insert(index, value) - insert value at index, so current item at that index is pointed to by new item at index
    - [x] erase(index) - removes node at given index
    - [x] value_n_from_end(n) - returns the value of the node at nth position from the end of the list
    - [x] reverse() - reverses the list
      - implemented iteratively
      - try doing it recursively
    - [x] remove_value(value) - removes the first item in the list with this value
  - [x] Doubly-linked List:
    - [x] [Doubly Linked List (video)](https://www.coursera.org/lecture/data-structures/doubly-linked-lists-jpGKD)
    - [x] (**Optional**) Implement Doubly-Linked List
      - [x] push_front(value) - adds an item to the front of the list
      - [x] pop_front() - remove front item and return its value
      - [x] push_back(value) - adds an item at the end
      - [x] pop_back() - removes end item and returns its value
      - [x] insert(index, value) - insert value at index, so current item at that index is pointed to by new item at index
      - [x] erase(index) - removes node at given index
      - [x] value_n_from_end(n) - returns the value of the node at nth position from the end of the list
      - [x] reverse() - reverses the list
      - [x] remove_value(value) - removes the first item in the list with this value
  - [ ] XOR Linked List
    - [x] [XOR Linked List](https://iq.opengenus.org/xor-linked-list/)
    - (**Optional**) Implement:
      - [ ] traverse - print all values in the list in forward direction
      - [ ] push_front(value) - adds an item to the front of the list
      - [ ] pop_front() - remove front item and return its value
      - [ ] push_back(value) - adds an item at the end
      - [ ] pop_back() - removes end item and returns its value
      - [ ] front() - get value of front item
      - [ ] back() - get value of end item
      - [ ] insert(index, value) - insert value at index, so current item at that index is pointed to by new item at index
  - [ ] Circular-Linked List (singly linked list)
    - [x] [Circular Linked List | Set 1 (Introduction and Applications)](https://www.geeksforgeeks.org/circular-linked-list/?ref=lbp)
    - [ ] (**Optional**) Implement a circular-linked list:
      - [ ] front() - get value of front item
      - [ ] back() - get value of end item
      - [ ] value_n_from_end(n) - returns the value of the node at nth position from the end of the list
      - [ ] insert(index, value) - insert value at index, so current item at that index is pointed to by new item at index
      - [ ] push_front(data) - adds an item to the front of the list
      - [ ] pop_front() - remove front item and return its data
      - [ ] push_back(data) - adds an item at the end
      - [ ] pop_back() - removes end item and returns its data
      - [ ] reverse() - reverses the list

- ### Stack
  - [x] [Stack Data Structure (Introduction and Program)](https://www.geeksforgeeks.org/stack-data-structure-introduction-program/)
  - [x] [Stack (video)](https://www.coursera.org/lecture/data-structures/stacks-UdKzQ)
  - [x] Implement using a linked list:
    - [x] push(data) - adds data at position top
    - [x] pop() - returns data and removes recently added element (top)
    - [x] peek() - returns data at top of the stack
    - [x] empty()
  - [ ] (**Optional**) Implement using a fixed-sized array - optional because it's trivial:
    - [ ] push(data) - adds data at position top
    - [ ] pop() - returns data and removes recently added element (top)
    - [ ] peek() - returns data at top of the stack
    - [ ] empty()
    - [ ] full()
  - [x] Cost:
    - push: O(1) (amortized, linked list and array)
    - pop: O(1) (linked list and array)
    - top: O(1) (linked list and array)
    - empty: O(1) (linked list and array)

- ### Queue
  - [ ] [Queue | Set 1 (Introduction and Array Implementation)](https://www.geeksforgeeks.org/queue-set-1introduction-and-array-implementation/)
  - [ ] [Circular Queue (Ring Buffer)](https://www.geeksforgeeks.org/circular-queue-set-1-introduction-array-implementation/)
  - [ ] [Circular buffer/FIFO](https://en.wikipedia.org/wiki/Circular_buffer)
  - [ ] Implement a queue
    - [ ] using a linked-list (w/ tail pointer):
      - [ ] enqueue(data) - adds data at position at tail
      - [ ] dequeue() - returns data and removes least recently added element (front)
      - [ ] empty()
    - [ ] using a fixed-sized array:
      - [ ] enqueue(data) - adds a data at the end of the list iff space is available
      - [ ] dequeue() - returns data and removes least recently added element
      - [ ] empty()
      - [ ] full()
  - [ ] (**Optional**) Implement a Circular Queue
    - [ ] enqueue(data) - adds data at position at tail
    - [ ] dequeue() - returns data and removes least recently added element (front)
    - [ ] empty()
    - [ ] full()
    - [ ] front() - gets the first element
    - [ ] rear() - gets the last element
  - [ ] Cost:
    - enqueue: O(1) (amortized, linked list and array)
    - dequeue: O(1) (linked list and array)
    - empty: O(1) (linked list and array)

- ### Hash table
    - [ ] [What is hashing?](https://www.educative.io/edpresso/what-is-hashing)
      - what is hashing? collision? where is it used?
      - [Hashing](https://computersciencewiki.org/index.php/Hashing)
    - [ ] [Fundamentals of data structures: Hashing](https://en.wikibooks.org/wiki/A-level_Computing/AQA/Paper_1/Fundamentals_of_data_structures/Hash_tables_and_hashing)
      - [ ] Hashing tables
      - [ ] Hashing Algorithms
      - [ ] Collisions (open and closed addressing)
  - videos:
    - [ ] [Hashing with Chaining (video)](https://www.youtube.com/watch?v=0M_kIqhwbFo&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb&index=8)
    - [ ] [Table Doubling, Karp-Rabin (video)](https://www.youtube.com/watch?v=BRO7mVIFt08&index=9&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb)
    - [ ] [Open Addressing, Cryptographic Hashing (video)](https://www.youtube.com/watch?v=rvdJDijO2Ro&index=10&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb)
    - [ ] [(Advanced) Randomization: Universal & Perfect Hashing (video)](https://www.youtube.com/watch?v=z0lJ2k0sl1g&list=PLUl4u3cNGP6317WaSNfmCvGym2ucw3oGp&index=11)
    - [ ] [(Advanced) Perfect hashing (video)](https://www.youtube.com/watch?v=N0COwN14gt0&list=PL2B4EEwhKD-NbwZ4ezj7gyc_3yNrojKM9&index=4)
  - online courses:
    - [ ] [Core Hash Tables (video)](https://www.coursera.org/lecture/data-structures-optimizing-performance/core-hash-tables-m7UuP)
    - [ ] [Data Structures (video)](https://www.coursera.org/learn/data-structures/home/week/4)
    - [ ] [Phone Book Problem (video)](https://www.coursera.org/lecture/data-structures/phone-book-problem-NYZZP)
      - distributed hash tables:
        - [ ] [Instant Uploads And Storage Optimization In Dropbox (video)](https://www.coursera.org/lecture/data-structures/instant-uploads-and-storage-optimization-in-dropbox-DvaIb)
        - [ ] [Distributed Hash Tables (video)](https://www.coursera.org/lecture/data-structures/distributed-hash-tables-tvH8H)
  - [ ] Implement with array using linear probing
    - [ ] hash(k, m) - m is size of hash table
    - [ ] add(key, value) - if key already exists, update value
    - [ ] exists(key)
    - [ ] get(key)
    - [ ] remove(key)
    - extra resources: 
      - [C Program to Implement Hash Tables with Linear Probing](https://www.sanfoundry.com/c-program-implement-hash-tables-linear-probing/)
      - [How to implement a hash table (in C)](https://benhoyt.com/writings/hash-table-in-c/)

---

## Trees

- ### Tree - Fundamentals
  - [ ] [Series: Trees(video)](https://www.coursera.org/lecture/data-structures/trees-95qda)
    - basic tree construction
    - traversals ([[Inorder Traversal|Inorder]] | [[Preorder Traversal|Preorder]] | [[Postorder Traversal|Postorder]])
  - [ ] [Properties of binary tree](https://www.geeksforgeeks.org/binary-tree-set-2-properties/)
  - [ ] [Types of Binary Tree](https://www.geeksforgeeks.org/binary-tree-set-3-types-of-binary-tree/)
  - [ ] [BFS and DFS (video)](https://www.youtube.com/watch?v=uWL6FJhq5fM)
  - [ ] [BFS vs DFS for Binary Tree](https://www.geeksforgeeks.org/bfs-vs-dfs-binary-tree/)
  - BFS notes:
    - level order (BFS, using queue)
    - time complexity: O(n)
    - space complexity: best: O(1), worst: O(n/2)=O(n)
  - DFS notes:
    - time complexity: O(n)
    - space complexity:
        best: O(log n) - avg. height of tree
        worst: O(n)
    - inorder (DFS: left, self, right)
    - postorder (DFS: left, right, self)
    - preorder (DFS: self, left, right)

- ### Binary search tree (BST)
  - [ ] [BST Review (video)](https://www.youtube.com/watch?v=x6At0nzX92o&index=1&list=PLA5Lqm4uh9Bbq-E0ZnqTIa8LRaL77ica6)
  - [ ] [BST Introduction (video)](https://www.coursera.org/learn/data-structures/lecture/E7cXP/introduction)
  - C/C++: 
    - [ ] [Binary search tree - Implementation in C/C++ (video)](https://www.youtube.com/watch?v=COZK7NATh4k&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=28)
    - [ ] [BST implementation - memory allocation in stack and heap (video)](https://www.youtube.com/watch?v=hWokyBoo0aI&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=29)
    - [ ] [Find min and max element in a binary search tree (video)](https://www.youtube.com/watch?v=Ut90klNN264&index=30&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P)
    - [ ] [Find height of a binary tree (video)](https://www.youtube.com/watch?v=_pnqMz5nrRs&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=31)
    - [ ] [Binary tree traversal - breadth-first and depth-first strategies (video)](https://www.youtube.com/watch?v=9RHO6jU--GU&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=32)
    - [ ] [Binary tree: Level Order Traversal (video)](https://www.youtube.com/watch?v=86g8jAQug04&index=33&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P)
    - [ ] [Binary tree traversal: Preorder, Inorder, Postorder (video)](https://www.youtube.com/watch?v=gm8DUJJhmY4&index=34&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P)
    - [ ] [Check if a binary tree is binary search tree or not (video)](https://www.youtube.com/watch?v=yEwSGhSsT0U&index=35&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P)
    - Deletion: 
      - Node to be deleted is the leaf: simply remove the node.
      - Node to be deleted has only one child: copy the child to the node and delete the child node.
      - Node to be deleted has two children: find **inorder successor** - the minimum value in the right child of the node.
      - [Delete a node from Binary Search Tree (video)](https://www.youtube.com/watch?v=gcULXE7ViZw&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=36)
      - [Inorder Successor in a binary search tree (video)](https://www.youtube.com/watch?v=5cPbNCrdotA&index=37&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P)
    - [ ] do research: Advantages of BST over Hash Table
    - [ ] Implement BST:
      - [ ] insert(data) - insert data into tree
      - [ ] get_node_count() - get count of values stored
      - [ ] print_values() - prints the values in the tree, from min to max
      - [ ] delete_tree()
      - [ ] is_in_tree() - returns true if given value exists in the tree
      - [ ] get_height() - returns the height in nodes (single node's height is 1)
      - [ ] get_min() - returns the minimum value stored in the tree
      - [ ] get_max() - returns the maximum value stored in the tree
      - [ ] is_binary_search_tree()
      - [ ] delete_value()
      - [ ] get_successor - returns next-highest value in tree after given value, -1 if none

- ### Self Balancing BST
  - [ ] AVL Tree 
    - [Insertion](https://www.geeksforgeeks.org/avl-tree-set-1-insertion/)
    - [Deletion](https://www.geeksforgeeks.org/avl-tree-set-2-deletion/)
    - [AVL with duplicate values](https://www.geeksforgeeks.org/avl-with-duplicate-keys/)
    - [visualization](https://www.cs.usfca.edu/~galles/visualization/AVLtree.html)
    - [ ] Implement
      - functions to implement -> TBD
  - [ ] Red Black Tree
    - [Introduction](https://www.geeksforgeeks.org/red-black-tree-set-1-introduction-2/)
    - [Insertion](https://www.geeksforgeeks.org/red-black-tree-set-2-insert/)
    - [Deletion](https://www.geeksforgeeks.org/red-black-tree-set-3-delete-2/)
    - [ ] Implement
      - functions to implement -> TBD
  
- ### Heap
  - Heap, Priority Queue, Binary Heap
	- [Heap](https://en.wikipedia.org/wiki/Heap_(data_structure))
	- [Introduction (video)](https://www.coursera.org/learn/data-structures/lecture/2OpTs/introduction)
	- [Naive Implementations (video)](https://www.coursera.org/learn/data-structures/lecture/z3l9N/naive-implementations)
	- [Binary Trees (video)](https://www.coursera.org/learn/data-structures/lecture/GRV2q/binary-trees)
	- [Tree Height Remark (video)](https://www.coursera.org/learn/data-structures/supplement/S5xxz/tree-height-remark)
	- [Basic Operations (video)](https://www.coursera.org/learn/data-structures/lecture/0g1dl/basic-operations)
	- [Complete Binary Trees (video)](https://www.coursera.org/learn/data-structures/lecture/gl5Ni/complete-binary-trees)
	- [Pseudocode (video)](https://www.coursera.org/learn/data-structures/lecture/HxQo9/pseudocode)
	- [Heap Sort - jumps to start (video)](https://youtu.be/odNJmw5TOEE?list=PLFDnELG9dpVxQCxuD-9BSy2E7BWY3t5Sm&t=3291)
	- [Heap Sort (video)](https://www.coursera.org/learn/data-structures/lecture/hSzMO/heap-sort)
	- [Building a heap (video)](https://www.coursera.org/learn/data-structures/lecture/dwrOS/building-a-heap)
	- [MIT: Heaps and Heap Sort (video)](https://www.youtube.com/watch?v=B7hVxCmfPtM&index=4&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb)
	- [CS 61B Lecture 24: Priority Queues (video)](https://archive.org/details/ucberkeley_webcast_yIUFT6AKBGE)
	- [Linear Time BuildHeap (max-heap)](https://www.youtube.com/watch?v=MiyLo8adrWw)
  - [ ] Implement a max-heap:
    - [ ] insert
    - [ ] sift_up - needed for insert
    - [ ] get_max - returns the max item, without removing it
    - [ ] get_size() - return number of elements stored
    - [ ] is_empty() - returns true if heap contains no elements
    - [ ] extract_max - returns the max item, removing it
    - [ ] sift_down - needed for extract_max
    - [ ] remove(x) - removes item at index x
    - [ ] heapify - create a heap from an array of elements, needed for heap_sort
    - [ ] heap_sort() - take an unsorted array and turn it into a sorted array in-place using a max heap or min heap

---

## [Graph](https://www.geeksforgeeks.org/graph-data-structure-and-algorithms/)
  - 4 basic ways to represent a graph in memory:
    - objects and pointers
    - adjacency matrix
    - adjacency list
    - adjacency map
  - Know pros & cons of each representation
  - BFS and DFS - know their computational complexity, their trade offs, and how to implement them in real code
  - When asked a question, look for a graph-based solution first, then move on if none
  - ### Traversals
    - [ ] [Breadth-First Search](https://www.youtube.com/watch?v=oFVYVzlvk9c&t=14s&ab_channel=MITOpenCourseWare)
    - [ ] [Depth-First Search](https://www.youtube.com/watch?v=IBfWDYSffUU&t=32s&ab_channel=MITOpenCourseWare)
  - ### Skiena Lectures - great intro:
    - [ ] [CSE373 2020 - Lecture 10 - Graph Data Structures (video)](https://www.youtube.com/watch?v=Sjk0xqWWPCc&list=PLOtl7M3yp-DX6ic0HGT0PUX_wiNmkWkXx&index=10)
    - [ ] [CSE373 2020 - Lecture 11 - Graph Traversal (video)](https://www.youtube.com/watch?v=ZTwjXj81NVY&list=PLOtl7M3yp-DX6ic0HGT0PUX_wiNmkWkXx&index=11)
    - [ ] [CSE373 2020 - Lecture 12 - Depth First Search (video)](https://www.youtube.com/watch?v=KyordYB3BOs&list=PLOtl7M3yp-DX6ic0HGT0PUX_wiNmkWkXx&index=12)
    - [ ] [CSE373 2020 - Lecture 13 - Minimum Spanning Trees (video)](https://www.youtube.com/watch?v=oolm2VnJUKw&list=PLOtl7M3yp-DX6ic0HGT0PUX_wiNmkWkXx&index=13)
    - [ ] [CSE373 2020 - Lecture 14 - Minimum Spanning Trees (con't) (video)](https://www.youtube.com/watch?v=RktgPx0MarY&list=PLOtl7M3yp-DX6ic0HGT0PUX_wiNmkWkXx&index=14)
    - [ ] [CSE373 2020 - Lecture 15 - Graph Algorithms (con't 2) (video)](https://www.youtube.com/watch?v=MUe5DXRhyAo&list=PLOtl7M3yp-DX6ic0HGT0PUX_wiNmkWkXx&index=15)
  - ### Graphs (review and more):
    - [ ] [6.006 Single-Source Shortest Paths Problem (video)](https://www.youtube.com/watch?v=Aa2sqUhIn-E&index=15&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb)
    - [ ] [6.006 Dijkstra (video)](https://www.youtube.com/watch?v=NSHizBK9JD8&t=1731s&ab_channel=MITOpenCourseWare)
    - [ ] [6.006 Bellman-Ford (video)](https://www.youtube.com/watch?v=f9cVS_URPc0&ab_channel=MITOpenCourseWare)
    - [ ] [6.006 Speeding Up Dijkstra (video)](https://www.youtube.com/watch?v=CHvQ3q_gJ7E&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb&index=18)
    - [ ] [Aduni: Graph Algorithms I - Topological Sorting, Minimum Spanning Trees, Prim's Algorithm - Lecture 6 (video)](https://www.youtube.com/watch?v=i_AQT_XfvD8&index=6&list=PLFDnELG9dpVxQCxuD-9BSy2E7BWY3t5Sm)
    - [ ] [Aduni: Graph Algorithms II - DFS, BFS, Kruskal's Algorithm, Union Find Data Structure - Lecture 7 (video)](https://www.youtube.com/watch?v=ufj5_bppBsA&list=PLFDnELG9dpVxQCxuD-9BSy2E7BWY3t5Sm&index=7)
    - [ ] [Aduni: Graph Algorithms III: Shortest Path - Lecture 8 (video)](https://www.youtube.com/watch?v=DiedsPsMKXc&list=PLFDnELG9dpVxQCxuD-9BSy2E7BWY3t5Sm&index=8)
    - [ ] [Aduni: Graph Alg. IV: Intro to geometric algorithms - Lecture 9 (video)](https://www.youtube.com/watch?v=XIAQRlNkJAw&list=PLFDnELG9dpVxQCxuD-9BSy2E7BWY3t5Sm&index=9)
    - [ ] [CS 61B 2014: Weighted graphs (video)](https://archive.org/details/ucberkeley_webcast_zFbq8vOZ_0k)
    - [ ] [Greedy Algorithms: Minimum Spanning Tree (video)](https://www.youtube.com/watch?v=tKwnms5iRBU&index=16&list=PLUl4u3cNGP6317WaSNfmCvGym2ucw3oGp)
    - [ ] [Strongly Connected Components Kosaraju's Algorithm Graph Algorithm (video)](https://www.youtube.com/watch?v=RpgcYiky7uw)
  - ### Full Coursera Course:  
    - [Algorithms on Graphs (video)](https://www.coursera.org/learn/algorithms-on-graphs/home/welcome)
  - [ ] Try implementing:
    - [ ] DFS with adjacency list (recursive)
    - [ ] DFS with adjacency list (iterative with stack)
    - [ ] DFS with adjacency matrix (recursive)
    - [ ] DFS with adjacency matrix (iterative with stack)
    - [ ] BFS with adjacency list
    - [ ] BFS with adjacency matrix
    - [ ] Dijkstra algorithm - single-source shortest path
    - [ ] minimum spanning tree
      - DFS-based algorithms (see Aduni videos above):
      - [ ] check for cycle (needed for topological sort, since we'll check for cycle before starting)
      - [ ] topological sort
      - [ ] count connected components in a graph
      - [ ] list strongly connected components
      - [ ] check for bipartite graph
  - ### Detect Cycles
    - [ ] [Detect Cycle in a Directed Graph](https://www.geeksforgeeks.org/detect-cycle-in-a-graph/)
    - [ ] [Detect Cycle in an Undirected Graph](https://www.geeksforgeeks.org/detect-cycle-undirected-graph/)
  - ### Disjoint Set
    - [ ] [Introduction](https://www.geeksforgeeks.org/union-find/)
    - [ ] [Union-Find Algorithm](https://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/)
    - [ ] [Union-Find Algorithm - optimized path compression](https://www.geeksforgeeks.org/union-find-algorithm-union-rank-find-optimized-path-compression/)

---

## Sorting
- [ ] Stability in sorting algorithms ("Is Quicksort stable?")
  - [ ] [Sorting Algorithm Stability](https://en.wikipedia.org/wiki/Sorting_algorithm#Stability)
  - [ ] [Stability In Sorting Algorithms](http://stackoverflow.com/questions/1517793/stability-in-sorting-algorithms)
  - [ ] [Stability In Sorting Algorithms](http://www.geeksforgeeks.org/stability-in-sorting-algorithms/)
  - [ ] [Sorting Algorithms - Stability](http://homepages.math.uic.edu/~leon/cs-mcs401-s08/handouts/stability.pdf)
- Which algorithms can be used on linked lists? Which on arrays? Which on both?
  - [ ] [Merge Sort For Linked List](http://www.geeksforgeeks.org/merge-sort-for-linked-list/)
- [ ] [Bubble Sort (video)](https://www.youtube.com/watch?v=P00xJgWzz2c&index=1&list=PL89B61F78B552C1AB)
  - [analyzing bubble sort (video)](https://www.youtube.com/watch?v=ni_zk257Nqo&index=7&list=PL89B61F78B552C1AB)
  - Time complexity: O(n^2)
  - Space Complexity: O(1)
  - stable
- [ ] [Selection Sort (video)](https://www.youtube.com/watch?v=6nDMgr0-Yyo&index=8&list=PL89B61F78B552C1AB)
  - Time complexity: O(n^2)
  - Space Complexity: O(1)
  - not stable
- [ ] [Insertion Sort (video)](https://www.youtube.com/watch?v=c4BRHC7kTaQ&index=2&list=PL89B61F78B552C1AB)
  - Time complexity: O(n^2)
  - Space Complexity: O(1)
  - stable
- [ ] [Merge Sort (video)](https://www.youtube.com/watch?v=GCae1WNvnZM&index=3&list=PL89B61F78B552C1AB)
  - Time complexity: O(n log n)
  - Space Complexity: O(n)
  - stable
- [ ] [Quick Sort (video)](https://www.youtube.com/watch?v=y_G9BkAm6B8&index=4&list=PL89B61F78B552C1AB)
  - Time complexity: O(n log n)
  - Space Complexity: O(log n)
  - not stable
- [ ] [Heap Sort](https://www.geeksforgeeks.org/heap-sort/)
  - Time complexity: O(n log n)
  - Space Complexity: O(1)
  - not stable
- [ ] [Counting Sort](https://www.geeksforgeeks.org/counting-sort/)
  - Time complexity: O(n + k), k = max non-negative value
  - Space Complexity: O(k)

---

## Practice Problems
| #    |  Tags  |       | Problems Set | Easy | Medium | Hard |
| :--: | :---- | :--- | :---------:  | :----: | :---: | :----: |
| 01 | Data Structure | Arrays | [View](./01-arrays) | 12 | 1 | 2 |
| 02 | Data Structure | Linked Lists | [View](./02-linkedlists) | 10 | 5 | 3 | 
| 03 | Data Structure | Stack| [View](./03-linkedlists) | 4 | 6 | 4 | 


<!--
- [ ] 우선순위 큐 (Priority Queue)
- [ ] 트리 (Tree) 
- [ ] 이진 트리 (Binary Tree) 
- [ ] 이진 탐색 트리 (Binary Search Tree; BST) 
- [ ] 해시 (Hash)
- [ ] 최소 힙 (Min Heap) 
- [ ] 최대 힙 (Max Heap)
- [ ] 자가균형 이진 탐색 트리 (Self-balancing BST)
  + [ ] AVL트리 (Adelson-Velskii/Landis Tree; AVL Tree)
  + [ ] 레드-블랙 트리 (Red-Black Tree)
  + [ ] B-트리 (B-Tree)
  + [ ] 트립 (Treap, Tree + Heap)
- [ ] 무방향/방향 그래프 (Undirected/Dirceted Graph)
  + [ ] 인접 리스트 (Adjacency List)
  + [ ] 인접 행렬 (Adjacency Matrix) 
- [ ] 세그먼트 트리 (Segment Tree)

## Algorithm
- [ ] 시간 복잡도 (Time Complexity)
- [ ] 공간 복잡도 (Space Complexity)
- [ ] 선형 탐색 (Linear Search)
- [ ] 이진 탐색 (Binary Search)
- [ ] 정렬 (Sorting)
  + [ ] 삽입 정렬 (Insertion Sort)
  + [ ] 병합 정렬 (Merge Sort)
  + [ ] 퀵 정렬 (Quick Sort)
  + [ ] 힙 정렬 (Heap Sort)
  + [ ] 계수 정렬 (Counting Sort)
  + [ ] 기수 정렬 (Radix Sort)
  + [ ] 위상 정렬 (Topology Sort)
---
- [ ] 깊이 우선 탐색 (Depth First Search, DFS)
- [ ] 너비 우선 탐색 (Breadth First Search, BFS)
- [ ] 브루트포스 (Brute-force)
- [ ] 그리디 (Greedy)
- [ ] 기초 다이나믹 프로그래밍 (Basic level Dynamic Programming, DP)
- [ ] 비트 마스크 (Bit Mask)
---
- [ ] 분할 정복 (Divide and Conquer)
- [ ] 중급 다이나믹 프로그래밍 (Intermediate level DP)
- [ ] 최단 경로 (Shortest Path)
  + [ ] 다익스트라 (Dijkstra)
  + [ ] 벨만포드 (Bellman-Ford)
  + [ ] 플로이드-와샬 (Floyd-Worshall)
- [ ] 최소 신장 트리 (Minimum Spanning Tree)
  + [ ] 크루스칼 (Kruskal)
  + [ ] 프림 (Prim)
- [ ] 트리
  + [ ] 인덱스 트리 (Indexed tree)
  + [ ] 펜윅 트리, 바이너리 인덱스 트리 (Fenwick Tree; Binary Indexed Tree)
- [ ] 최소 공통 조상 (Lowest Common Ancestor, LCA)
- [ ] 유니온-파인드, 서로소 집합 (Union-Find, Disjoint Set)
---
- [ ] 라인 스위핑 (Line Sweeping)
- [ ] 네트워크 플로우 (Network Flow)
- [ ] 이분 매칭 (Bipartite Matching)
- [ ] KMP 문자열 매칭 (Knute-Morris-Pratt, KMP)
- [ ] 라빈-카프 (Rabin-Karp)
- [ ] 접미사 배열 (Suffix Array)
- [ ] Longest Common Prefix, LCP
- [ ] 아호 코라식 (Aho-Corasick)
- [ ] 단절점과 단절선 (Articulation Point and Bridge)
- [ ] 강한 결합 요소 (Strongly Connected Component, SCC)
- [ ] 구간 쿼리
  + [ ] SQRT Decomposition
  + [ ] Heavy-Light Decomposition
- [ ] 스플레이 트리 ([Splay Tree](https://cubelover.tistory.com/10))
- [ ] 고속 푸리에 변환 (Fast Fourier Transform, FFT)
- [ ] Link Cut Tree, LCT

## ETC
- [x] GCD: Euclidean Algorithm (유클리드 호제법) [🔗](https://github.com/yuueu/ds-algo/tree/main/archive/etc/euclidean/)
- [x] Morris Traversal (threaded binary tree) [🔗](https://github.com/yuueu/ds-algo/tree/main/archive/etc/morris-traversal/)
- [x] Primality Test (소수 판별하기) [🔗](https://github.com/yuueu/ds-algo/tree/main/archive/etc/prime/)
- [x] Prime Factorization (소인수분해) [🔗](https://github.com/yuueu/ds-algo/tree/main/archive/etc/prime-factorization/)
- [x] Sieve of Eratosthenes (에라토스테네스의 체) [🔗](https://github.com/yuueu/ds-algo/tree/main/archive/etc/eratosthenes) -->
