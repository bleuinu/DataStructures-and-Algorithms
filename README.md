## Data Structures and Algorithms

The original credit goes to the [coding-interview-university](https://github.com/jwasham/coding-interview-university).

---

## Table of Contents

- [Data Structures](#data-structures)
  - [Arrays](#arrays)
  - [Linked Lists](#linked-lists)
  - [Stack](#stack)
  - [Queue](#queue)
  - [Hash Table](#hash-table)
- [Trees](#trees)
  - [Binary Tree](#binary-tree)
  - [Binary Search Tree](#bst)
  - [Self Balancing BST](#self-balancing-bst)
  - [Heap, Priority Queue, Binary Heap](#heap)
- [Graph](#graph)
  - General Knowledge
    - directed & undirected graph
    - adjacency matrix & adjacency list
  - Traversals
  - Detect Cycles
  - Disjoint Set or Union-Find
- [Sorting](#sorts)
  - Bubble Sort
  - Selection Sort
  - Insertion Sort
  - Merge Sort
  - Quick Sort
  - Heap Sort
  - Counting Sort
- [Practice Problems](#practice-problems)

---

## Data Structures

<a id="arrays"></a>

<details>
<summary> Arrays </summary>
<ul>
		<li> 
      About Arrays: 
      <ul>
        <li>[ ] <a href="https://www.geeksforgeeks.org/introduction-to-arrays/">Introduction to Arrays</a></li>
        <li>[x] <a href="https://www.coursera.org/lecture/data-structures/arrays-OsBSF">Arrays (video)</a></li>
        <li>[x] <a href="https://www.coursera.org/lecture/data-structures/dynamic-arrays-EwbnV">Dynamic Arrays (video)</a></li>
        <li>[x] <a href="https://www.youtube.com/watch?v=1jtrQqYpt7g">Jagged Arrays</a></li>
      </ul>
    </li>
</ul>
<ul>
  <li> 
    [x] Implement a vector (mutable array with automatic resizing):
    <ul>
      <li>[x] size() - number of items</il>
      <li>[x] New raw data array with allocated memory (default = 16, or power of 2 - 16, 32, 64, ...)</il>
      <li>[x] capacity() - number of items it can hold</il>
      <li>[x] is_empty()</il>
      <li>[x] at(index) - returns item at given index, blows up if index out of bounds</il>
      <li>[x] push(item)</il>
      <li>[x] insert(index, item) - inserts item at index, shifts that index's value and trailing elements to the right</il>
      <li>[x] prepend(item) - inserts item at index 0</il>
      <li>[x] pop() - remove from end, return value</il>
      <li>[x] delete(index) - delete item at index, shifting all trailing elements left</il>
      <li>[x] remove(item) - looks for value and removes index holding it (even if in multiple places)</il>
      <li>[x] find(item) - looks for value and returns first index with that value, -1 if not found</il>
      <li>
        [x] resize(new_capacity) // private function
        <ul>
          <li>[x] when you reach capacity, resize to double the size</li>
          <li>[x] when popping an item, if size is 1/4 of capacity, resize to half</li>
        </ul>
      </il>
    </ul>
</ul>
<ul>
  <li>[x] Time
    <ul>
      <li>O(1) to add/remove at end (amortized for allocations for more space), index, or update</li>
      <li>(n) to insert/remove elsewhere</li>
    </ul>
  </li>
</ul>
<ul>
  <li>[x] Space
    <ul>
      <li>contiguous in memory, so proximity helps performance</li>
      <li>space needed = (array capacity, which is >= n) * size of item, but even if 2n, still O(n)</li>
    </ul>
  </li>
</ul>
</details>

<a id="linked-lists"></a>
<details>
<summary>Linked Lists</summary>
<ul>
  <li>[x] About Linked Lists:
    <ul>
      <li>[x] <a href="https://www.youtube.com/watch?v=HB7TcYklBHY">Singly Linked Lists Tutorial - What is a Linked List?</a></li>
      <li>[x] <a href="https://www.coursera.org/lecture/data-structures/singly-linked-lists-kHhgK">Singly Linked Lists (video)</a></li>
      <li>[x] <a href="https://archive.org/details/ucberkeley_webcast_htzJdKoEmO0">CS 61B - Linked Lists 1 (video)</a></li>
      <li>[x] <a href="https://archive.org/details/ucberkeley_webcast_-c4I3gFYe3w">CS 61B - Linked Lists 2 (video)</a></li>
      <li>[x] <a href="https://www.youtube.com/watch?v=QN6FPiD0Gzo">C code (video)</a> - just portions about Node struct and *memory allocation*.</li>
    </ul>
  </li>
</ul>
<ul>
  <li>[x] <a href="https://www.geeksforgeeks.org/linked-list-vs-array/?ref=lbp">Linked List vs Arrays</a>
    <ul>
      <li>[x] <a href="https://www.coursera.org/lecture/data-structures-optimizing-performance/core-linked-lists-vs-arrays-rjBs9">Core Linked Lists Vs Arrays (video)</a></li>
      <li>[x] <a href="https://www.coursera.org/lecture/data-structures-optimizing-performance/in-the-real-world-lists-vs-arrays-QUaUd">In The Real World Linked Lists Vs Arrays (video)</a></li>
    </ul>
  </li>
</ul>
<ul>
  <li>[x] Vector vs. List - <a href="https://www.youtube.com/watch?v=YQs6IC-vgmo)">why you should avoid linked lists (video)</a> -  (this is from <a href="https://youtu.be/m0H5bUPfwn8?t=2690">GoingNative 2012 - Day 1 - C++11 style</a>)</li>
  <li>[ ] <a href="https://www.eskimo.com/~scs/cclass/int/sx8.html">Pointers to Pointers</a> - for passing a pointer to a function that may change the address where that pointer points</li>
</ul>
<ul>
  <li>[x] Implement Singly-Linked List (with and without tail pointer)
    <ul>
      <li>[x] size() - returns number of data elements in list</li>
      <li>[x] empty() - bool returns true if empty</li>
      <li>[x] value_at(index) - returns the value of the nth item (starting at 0 for first)</li>
      <li>[x] push_front(value) - adds an item to the front of the list</li>
      <li>[x] pop_front() - remove front item and return its value</li>
      <li>[x] push_back(value) - adds an item at the end</li>
      <li>[x] pop_back() - removes end item and returns its value</li>
      <li>[x] front() - get value of front item</li>
      <li>[x] back() - get value of end item</li>
      <li>[x] insert(index, value) - insert value at index, so current item at that index is pointed to by new item at index</li>
      <li>[x] erase(index) - removes node at given index</li>
      <li>[x] value_n_from_end(n) - returns the value of the node at nth position from the end of the list</li>
      <li>[x] reverse() - reverses the list
        <ul>
          <li>implemented iteratively</li>
          <li>try doing it recursively</li>
        </ul>
      </li>
      <li>[x] remove_value(value) - removes the first item in the list with this value</li>
    </ul>
  </li>
    </ul>
  </li>
</ul>
<ul>
  <li>[x] Doubly-linked List:
  <ul>
    <li>[x] <a href="https://www.coursera.org/lecture/data-structures/doubly-linked-lists-jpGKD">Doubly Linked List (video)</a></li>
    <li>[x] (<b>Optional</b>) Implement Doubly-Linked List</li>
      <ul>
        <li>[x] push_front(value) - adds an item to the front of the list</li>
        <li>[x] pop_front() - remove front item and return its value</li>
        <li>[x] push_back(value) - adds an item at the end</li>
        <li>[x] pop_back() - removes end item and returns its value</li>
        <li>[x] insert(index, value) - insert value at index, so current item at that index is pointed to by new item at index</li>
        <li>[x] erase(index) - removes node at given index</li>
        <li>[x] value_n_from_end(n) - returns the value of the node at nth position from the end of the list</li>
        <li>[x] reverse() - reverses the list</li>
        <li>[x] remove_value(value) - removes the first item in the list with this value</li>
      </ul>
    </li>
  </ul>
</ul>
<ul>
  <li>[ ] XOR Linked List
    <ul>
      <li>[x] <a href="https://iq.opengenus.org/xor-linked-list/">XOR Linked List</a></li>
      <li> (<b>Optional</b>) Implement:
        <ul>
          <li>[ ] traverse - print all values in the list in forward direction</li>
          <li>[ ] push_front(value) - adds an item to the front of the list</li>
          <li>[ ] pop_front() - remove front item and return its value</li>
          <li>[ ] push_back(value) - adds an item at the end</li>
          <li>[ ] pop_back() - removes end item and returns its value</li>
          <li>[ ] front() - get value of front item</li>
          <li>[ ] back() - get value of end item</li>
          <li>[ ] insert(index, value) - insert value at index, so current item at that index is pointed to by new item at index</li>
        </ul>
      </li>
    </ul>
  </li>
</ul>
<ul>
  <li>[ ] Circular-Linked List (singly linked list)
    <ul>
      <li>[x] <a href="https://www.geeksforgeeks.org/circular-linked-list/?ref=lbp">Circular Linked List | Set 1 (Introduction and Applications</a></li>
      <li>[ ] (<b>Optional</b>) Implement a circular-linked list:
        <ul>
          <li>[ ] front() - get value of front item</li>
          <li>[ ] back() - get value of end item</li>
          <li>[ ] value_n_from_end(n) - returns the value of the node at nth position from the end of the list</li>
          <li>[ ] insert(index, value) - insert value at index, so current item at that index is pointed to by new item at index</li>
          <li>[ ] push_front(data) - adds an item to the front of the list</li>
          <li>[ ] pop_front() - remove front item and return its data</li>
          <li>[ ] push_back(data) - adds an item at the end</li>
          <li>[ ] pop_back() - removes end item and returns its data</li>
          <li>[ ] reverse() - reverses the list</li>
        </ul>
      </li>
    </ul>
  </li>
</ul>
</details>

<a id="stack"></a>
<details>
<summary>Stack</summary>
<ul>
  <li>[x] <a href="https://www.geeksforgeeks.org/stack-data-structure-introduction-program/">Stack Data Structure (Introduction and Program)</a></li>
  <li>[x] <a href="https://www.coursera.org/lecture/data-structures/stacks-UdKzQ">Stack (video)</a></li>
</ul>
<ul>
  <li>[x] Implement using a linked list:</li>
  <ul>
    <li>[x] push(data) - adds data at position top</li>
    <li>[x] pop() - returns data and removes recently added element (top)</li>
    <li>[x] peek() - returns data at top of the stack</li>
    <li>[x] empty()</li>
  </ul>
</ul>
<ul>
  <li>[ ] (<b>Optional</b>) Implement using a fixed-sized array - optional because it's trivial:</li>
  <ul>
    <li>[ ] push(data) - adds data at position top</li>
    <li>[ ] pop() - returns data and removes recently added element (top)</li>
    <li>[ ] peek() - returns data at top of the stack</li>
    <li>[ ] empty()</li>
    <li>[ ] full()</li>
  </ul>
</ul>
<ul>
  <li>[x] Cost:</li>
  <ul>
     <li>push: O(1) (amortized, linked list and array)</li>
     <li>pop: O(1) (linked list and array)</li>
     <li>top: O(1) (linked list and array)</li>
     <li>empty: O(1) (linked list and array)</li>
  </ul>
</ul>
</details>

<a id="queue"></a>
<details>
<summary>Queue</summary>
<ul>
  <li>[ ] <a href="https://www.geeksforgeeks.org/queue-set-1introduction-and-array-implementation/">Queue | Set 1 (Introduction and Array Implementation)</a></li>
  <li>[ ] <a href="https://www.geeksforgeeks.org/circular-queue-set-1-introduction-array-implementation/">Circular Queue (Ring Buffer)</a></li>
  <li>[ ] <a href="https://en.wikipedia.org/wiki/Circular_buffer">Circular buffer/FIFO</a></li>
</ul>
<ul>
  <li>[ ] Implement a queue</li>
    <ul>
      <li>[ ] using a linked-list (w/ tail pointer):</li>
      <ul>
        <li>[ ] enqueue(data) - adds data at position at tail</li>
        <li>[ ] dequeue() - returns data and removes least recently added element (front)</li>
        <li>[ ] empty()</li>
      </ul>
      <li>[ ] using a fixed-sized array:</li>
      <ul>
        <li>[ ] enqueue(data) - adds a data at the end of the list iff space is available</li>
        <li>[ ] dequeue() - returns data and removes least recently added element</li>
        <li>[ ] empty()</li>
        <li>[ ] full()</li>
      </ul>
    </ul>
</ul>
<ul>
  <li>[ ] (<b>Optional</b>) Implement a Circular Queue
    <ul>
      <li>[ ] enqueue(data) - adds data at position at tail</li>
      <li>[ ] dequeue() - returns data and removes least recently added element (front)</li>
      <li>[ ] empty()</li>
      <li>[ ] full()</li>
      <li>[ ] front() - gets the first element</li>
      <li>[ ] rear() - gets the last element</li>
    </ul>
  </li>
</ul>
<ul>
  <li>[ ] Cost:</li>
    <ul>
      <li>enqueue: O(1) (amortized, linked list and array)</li>
      <li>dequeue: O(1) (linked list and array)</li>
      <li>empty: O(1) (linked list and array)</li>
    </ul>
</ul>
</details>

<a id="hash-table"></a>
<details>
<summary>Hash Table</summary>
<ul>
  <li>[ ] <a href="https://www.educative.io/edpresso/what-is-hashing">What is hashing?</a></li>
  <ul>
    <li>what is hashing? collision? where is it used?</li>
    <li><a href="https://computersciencewiki.org/index.php/Hashing">Hashing</a></li>
  </ul>
</ul>
<ul>
  <li>[ ] <a href="https://en.wikibooks.org/wiki/A-level_Computing/AQA/Paper_1/Fundamentals_of_data_structures/Hash_tables_and_hashing">Fundamentals of data structures: Hashing</a></li>
    <ul>
      <li>[ ] Hashing tables</li>
      <li>[ ] Hashing Algorithms</li>
      <li>[ ] Collisions (open and closed addressing)</li>
    </ul>
</ul>
<ul>
  <li>videos:</li>
  <ul>
    <li>[ ] <a href="https://www.youtube.com/watch?v=0M_kIqhwbFo&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb&index=8">Hashing with Chaining (video)</a></li>
    <li>[ ] <a href="https://www.youtube.com/watch?v=BRO7mVIFt08&index=9&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb">Table Doubling, Karp-Rabin (video)</a></li>
    <li>[ ] <a href="https://www.youtube.com/watch?v=rvdJDijO2Ro&index=10&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb">Open Addressing, Cryptographic Hashing (video)</a></li>
    <li>[ ] <a href="https://www.youtube.com/watch?v=z0lJ2k0sl1g&list=PLUl4u3cNGP6317WaSNfmCvGym2ucw3oGp&index=11">(Advanced) Randomization: Universal & Perfect Hashing (video)</a></li>
    <li>[ ] <a href="https://www.youtube.com/watch?v=N0COwN14gt0&list=PL2B4EEwhKD-NbwZ4ezj7gyc_3yNrojKM9&index=4">(Advanced) Perfect hashing (video)</a></li>
  </ul>
</ul>
<ul>
  <li>online courses:</li>
    <ul>
      <li>[ ] <a href="https://www.coursera.org/lecture/data-structures-optimizing-performance/core-hash-tables-m7UuP">Core Hash Tables (video)</a></li>
      <li>[ ] <a href="https://www.coursera.org/learn/data-structures/home/week/4">Data Structures (video)</a></li>
      <li>[ ] <a href="https://www.coursera.org/lecture/data-structures/phone-book-problem-NYZZP">Phone Book Problem (video)</a></li>
      <li>distributed hash tables:</li>
      <ul>
        <li>[ ] <a href="https://www.coursera.org/lecture/data-structures/instant-uploads-and-storage-optimization-in-dropbox-DvaIb">Instant Uploads And Storage Optimization In Dropbox (video)</a></li>
        <li>[ ] <a href="https://www.coursera.org/lecture/data-structures/distributed-hash-tables-tvH8H">Distributed Hash Tables (video)</a></li>
      </ul>
    </ul>
</ul>
<ul>
  <li>[ ] Implement with array using linear probing</li>
  <ul>
    <li>[ ] hash(k, m) - m is size of hash table</li>
    <li>[ ] add(key, value) - if key already exists, update value</li>
    <li>[ ] exists(key)</li>
    <li>[ ] get(key)</li>
    <li>[ ] remove(key)</li>
    <li>extra resources: </li>
    <ul>
      <li><a href="https://www.sanfoundry.com/c-program-implement-hash-tables-linear-probing/">C Program to Implement Hash Tables with Linear Probing</a></li>
      <li> <a href="https://benhoyt.com/writings/hash-table-in-c/">How to implement a hash table (in C)</a></li>
    </ul>
  </ul>
</ul>
</details>

---

## Trees

<a id="tree"></a>
<details>
<summary>Tree - Fundamentals</summary>
<ul>
  <li>[ ] <a href="https://www.coursera.org/lecture/data-structures/trees-95qda">Series: Trees(video)</a></li>
  <ul>
    <li>basic tree construction</li>
    <li>traversals (Inorder, Preorder, Postorder))</li>
  </ul>
  <li>[ ] <a href="https://www.geeksforgeeks.org/binary-tree-set-2-properties/">Properties of binary tree</a></li>
  <li>[ ] <a href="https://www.geeksforgeeks.org/binary-tree-set-3-types-of-binary-tree/">Types of Binary Tree</a></li>
  <li>[ ] <a href="https://www.youtube.com/watch?v=uWL6FJhq5fM">BFS and DFS (video)</a></li>
  <li>[ ] <a href="https://www.geeksforgeeks.org/bfs-vs-dfs-binary-tree/">BFS vs DFS for Binary Tree</a></li>
</ul>
<ul>
  <li>BFS notes:</li>
  <ul>
    <li>level order (BFS, using queue)</li>
    <li>time complexity: O(n)</li>
    <li>space complexity: best: O(1), worst: O(n/2)=O(n)</li>
  </ul>
  <li>DFS notes:</li>
  <ul>
    <li>time complexity: O(n)</li>
    <li>space complexity:
      <ul>
          <li>best: O(log n) - avg. height of tree</li>
          <li>worst: O(n)</li>
      </ul>
    </li>
    <li>inorder (DFS: left, self, right)</li>
    <li>postorder (DFS: left, right, self)</li>
    <li>preorder (DFS: self, left, right)</li>
  </ul>
</ul>
</details>

<a id="bst"></a>
<details>
<summary>Binary Search Tree (BST)</summary>
<ul>
  <li>[ ] <a href="https://www.youtube.com/watch?v=x6At0nzX92o&index=1&list=PLA5Lqm4uh9Bbq-E0ZnqTIa8LRaL77ica6">BST Review (video)</a></li>
  <li>[ ] <a href="https://www.coursera.org/learn/data-structures/lecture/E7cXP/introduction">BST Introduction (video)</a></li>
  <li>C/C++: </li>
    <ul>
      <li>[ ] <a href="https://www.youtube.com/watch?v=COZK7NATh4k&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=28">Binary search tree - Implementation in C/C++ (video)</a></li>
      <li>[ ] <a href="https://www.youtube.com/watch?v=hWokyBoo0aI&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=29">BST implementation - memory allocation in stack and heap (video)</a></li>
      <li>[ ] <a href="https://www.youtube.com/watch?v=Ut90klNN264&index=30&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P">Find min and max element in a binary search tree (video)</a></li>
      <li>[ ] <a href="https://www.youtube.com/watch?v=_pnqMz5nrRs&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=31">Find height of a binary tree (video)</a></li>
      <li>[ ] <a href="https://www.youtube.com/watch?v=9RHO6jU--GU&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=32">Binary tree traversal - breadth-first and depth-first strategies (video)</a></li>
      <li>[ ] <a href="https://www.youtube.com/watch?v=86g8jAQug04&index=33&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P">Binary tree: Level Order Traversal (video)</a></li>
      <li>[ ] <a href="https://www.youtube.com/watch?v=gm8DUJJhmY4&index=34&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P">Binary tree traversal: Preorder, Inorder, Postorder (video)</a></li>
      <li>[ ] <a href="https://www.youtube.com/watch?v=yEwSGhSsT0U&index=35&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P">Check if a binary tree is binary search tree or not (video)</a></li>
    </ul>
</ul> 
<ul>
  <li>Deletion:</li>
  <ul>
      <li>Node to be deleted is the leaf: simply remove the node.</li>
      <li>Node to be deleted has only one child: copy the child to the node and delete the child node.</li>
      <li>Node to be deleted has two children: find **inorder successor** - the minimum value in the right child of the node.</li>
      <li><a href="https://www.youtube.com/watch?v=gcULXE7ViZw&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=36">Delete a node from Binary Search Tree (video)</a></li>
      <li><a href="https://www.youtube.com/watch?v=5cPbNCrdotA&index=37&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P">Inorder Successor in a binary search tree (video)</a></li>
  </ul>
</ul>
<ul>
  <li> [ ] Do research: Advantages of BST over Hash Table</li>
</ul>
<ul>
  <li>[ ] Implement BST:</li>
  <ul>
    <li>[ ] insert(data) - insert data into tree</li>
    <li>[ ] get_node_count() - get count of values stored</li>
    <li>[ ] print_values() - prints the values in the tree, from min to max</li>
    <li>[ ] delete_tree()</li>
    <li>[ ] is_in_tree() - returns true if given value exists in the tree</li>
    <li>[ ] get_height() - returns the height in nodes (single node's height is 1)</li>
    <li>[ ] get_min() - returns the minimum value stored in the tree</li>
    <li>[ ] get_max() - returns the maximum value stored in the tree</li>
    <li>[ ] is_binary_search_tree()</li>
    <li>[ ] delete_value()</li>
    <li>[ ] get_successor - returns next-highest value in tree after given value, -1 if none</li>
  </ul>
</u>
</details>

<a id="self-balancing-bst"></a>

<details>
<summary>Self Balancing BST</summary>
<ul>
  <li>[ ] AVL Tree </li>
    <ul>
      <li><a href="https://www.geeksforgeeks.org/avl-tree-set-1-insertion/">Insertion</a></li>
      <li><a href="https://www.geeksforgeeks.org/avl-tree-set-2-deletion/">Deletion</a></li>
      <li><a href="https://www.geeksforgeeks.org/avl-with-duplicate-keys/">AVL with duplicate values</a></li>
      <li><a href="https://www.cs.usfca.edu/~galles/visualization/AVLtree.html">visualization</a></li>
      <li>[ ] Implement</li>
      <ul>
        <li>functions to implement -> TBD</li>
      </ul>
    </ul>
</ul>
<ul>
  <li>[ ] Red Black Tree</li>
  <ul>
    <li><a href="https://www.geeksforgeeks.org/red-black-tree-set-1-introduction-2/">Introduction</a></li>
    <li><a href=">https://www.geeksforgeeks.org/red-black-tree-set-2-insert/">Insertion</a></li>
    <li><a href="https://www.geeksforgeeks.org/red-black-tree-set-3-delete-2/">Deletion</a></li>
    <li>[ ] Implement</li>
    <ul>
      <li>functions to implement -> TBD</li>
    </ul>
  </ul>
</ul>
</details>

<a id="heap"></a>
<details>
<summary>Heap</summary>
<ul>
  <li>Heap, Priority Queue, Binary Heap</li>
  <ul>
    <li><a href="https://en.wikipedia.org/wiki/Heap_(data_structure)">Heap</a></li>
    <li><a href="https://www.coursera.org/learn/data-structures/lecture/2OpTs/introduction">Introduction (video)</a></li>
    <li><a href="https://www.coursera.org/learn/data-structures/lecture/z3l9N/naive-implementations">Naive Implementations (video)</a></li>
    <li><a href="https://www.coursera.org/learn/data-structures/lecture/GRV2q/binary-trees">Binary Trees (video)</a></li>
    <li><a href="https://www.coursera.org/learn/data-structures/supplement/S5xxz/tree-height-remark">Tree Height Remark (video)</a></li>
    <li><a href="https://www.coursera.org/learn/data-structures/lecture/0g1dl/basic-operations">Basic Operations (video)</a></li>
    <li><a href="https://www.coursera.org/learn/data-structures/lecture/gl5Ni/complete-binary-trees">Complete Binary Trees (video)</a></li>
    <li><a href="https://www.coursera.org/learn/data-structures/lecture/HxQo9/pseudocode">Pseudocode (video)</a></li>
    <li><a href="https://youtu.be/odNJmw5TOEE?list=PLFDnELG9dpVxQCxuD-9BSy2E7BWY3t5Sm&t=3291">Heap Sort - jumps to start (video)</a></li>
    <li><a href="https://www.coursera.org/learn/data-structures/lecture/hSzMO/heap-sort">Heap Sort (video)</a></li>
    <li><a href="https://www.coursera.org/learn/data-structures/lecture/dwrOS/building-a-heap">Building a heap (video)</a></li>
    <li><a href="https://www.youtube.com/watch?v=B7hVxCmfPtM&index=4&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb">MIT: Heaps and Heap Sort (video)</a></li>
    <li><a href="https://archive.org/details/ucberkeley_webcast_yIUFT6AKBGE">CS 61B Lecture 24: Priority Queues (video)</a></li>
    <li><a href="https://www.youtube.com/watch?v=MiyLo8adrWw">Linear Time BuildHeap (max-heap)</a></li>
  </ul>
</ul>
<ul>
  <li>[ ] Implement a max-heap:</li>
  <ul>
    <li>[ ] insert</li>
    <li>[ ] sift_up - needed for insert</li>
    <li>[ ] get_max - returns the max item, without removing it</li>
    <li>[ ] get_size() - return number of elements stored</li>
    <li>[ ] is_empty() - returns true if heap contains no elements</li>
    <li>[ ] extract_max - returns the max item, removing it</li>
    <li>[ ] sift_down - needed for extract_max</li>
    <li>[ ] remove(x) - removes item at index x</li>
    <li>[ ] heapify - create a heap from an array of elements, needed for heap_sort</li>
    <li>[ ] heap_sort() - take an unsorted array and turn it into a sorted array in-place using a max heap or min heap</li>
  </ul>
</ul>
</details>

---

## Graph

<a id="graph"></a>
<details>
<summary>Graph</summary>
<ul>
  <li><a href="https://www.geeksforgeeks.org/graph-data-structure-and-algorithms/">GeeksforGeeks: Graph Data Structure</a></li>
  <li>4 basic ways to represent a graph in memory:</li>
  <ol>
    <li>objects and pointers</li>
    <li>adjacency matrix</li>
    <li>adjacency list</li>
    <li>adjacency map</li>
  </ol>
  <li>Know pros & cons of each representation</li>
  <li>BFS and DFS - know their computational complexity, their trade offs, and how to implement them in real code</li>
  <li>When asked a question, look for a graph-based solution first, then move on if none</li>
</ul>
<ul>
  <li>Traversals</li><a id="traversals"></a>
  <ul>
    <li>[ ] <a href="https://www.youtube.com/watch?v=oFVYVzlvk9c&t=14s&ab_channel=MITOpenCourseWare">Breadth-First Search (BFS)</a></li>
    <li>[ ] <a href="https://www.youtube.com/watch?v=IBfWDYSffUU&t=32s&ab_channel=MITOpenCourseWare">Depth-First Search (DFS)</a></li>
  </ul>
</ul>
<ul>
  <li>Skiena Lectures - great intro:</li>
  <ul>
    <li>[ ] <a href="https://www.youtube.com/watch?v=Sjk0xqWWPCc&list=PLOtl7M3yp-DX6ic0HGT0PUX_wiNmkWkXx&index=10">CSE373 2020 - Lecture 10 - Graph Data Structures (video)</a></li>
    <li>[ ] <a href="https://www.youtube.com/watch?v=ZTwjXj81NVY&list=PLOtl7M3yp-DX6ic0HGT0PUX_wiNmkWkXx&index=11">CSE373 2020 - Lecture 11 - Graph Traversal (video)</a></li>
    <li>[ ] <a href="https://www.youtube.com/watch?v=KyordYB3BOs&list=PLOtl7M3yp-DX6ic0HGT0PUX_wiNmkWkXx&index=12">CSE373 2020 - Lecture 12 - Depth First Search (video)</a></li>
    <li>[ ] <a href="https://www.youtube.com/watch?v=oolm2VnJUKw&list=PLOtl7M3yp-DX6ic0HGT0PUX_wiNmkWkXx&index=13">CSE373 2020 - Lecture 13 - Minimum Spanning Trees (video)</a></li>
    <li>[ ] <a href="https://www.youtube.com/watch?v=RktgPx0MarY&list=PLOtl7M3yp-DX6ic0HGT0PUX_wiNmkWkXx&index=14">CSE373 2020 - Lecture 14 - Minimum Spanning Trees (cont.) (video)</a></li>
    <li>[ ] <a href="https://www.youtube.com/watch?v=MUe5DXRhyAo&list=PLOtl7M3yp-DX6ic0HGT0PUX_wiNmkWkXx&index=15">CSE373 2020 - Lecture 15 - Graph Algorithms (cont. 2) (video)</a></li>
  </ul>
</ul>
<ul>
  <li>Graphs (review and more):</li>
  <ul>
    <li>[ ] <a href="https://www.youtube.com/watch?v=Aa2sqUhIn-E&index=15&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb">6.006 Single-Source Shortest Paths Problem (video)</a></li>
    <li>[ ] <a href="https://www.youtube.com/watch?v=NSHizBK9JD8&t=1731s&ab_channel=MITOpenCourseWare">6.006 Dijkstra (video)</a></li>
    <li>[ ] <a href="https://www.youtube.com/watch?v=f9cVS_URPc0&ab_channel=MITOpenCourseWare">6.006 Bellman-Ford (video)</a></li>
    <li>[ ] <a href="https://www.youtube.com/watch?v=CHvQ3q_gJ7E&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb&index=18">6.006 Speeding Up Dijkstra (video)</a></li>
    <li>[ ] <a href="https://www.youtube.com/watch?v=i_AQT_XfvD8&index=6&list=PLFDnELG9dpVxQCxuD-9BSy2E7BWY3t5Sm">Aduni: Graph Algorithms I - Topological Sorting, Minimum Spanning Trees, Prim's Algorithm - Lecture 6 (video)</a></li>
    <li>[ ] <a href="https://www.youtube.com/watch?v=ufj5_bppBsA&list=PLFDnELG9dpVxQCxuD-9BSy2E7BWY3t5Sm&index=7">Aduni: Graph Algorithms II - DFS, BFS, Kruskal's Algorithm, Union Find Data Structure - Lecture 7 (video)</a></li>
    <li>[ ] <a href="https://www.youtube.com/watch?v=DiedsPsMKXc&list=PLFDnELG9dpVxQCxuD-9BSy2E7BWY3t5Sm&index=8">Aduni: Graph Algorithms III: Shortest Path - Lecture 8 (video)</a></li>
    <li>[ ] <a href="https://www.youtube.com/watch?v=XIAQRlNkJAw&list=PLFDnELG9dpVxQCxuD-9BSy2E7BWY3t5Sm&index=9">Aduni: Graph Alg. IV: Intro to geometric algorithms - Lecture 9 (video)</a></li>
    <li>[ ] <a href="https://archive.org/details/ucberkeley_webcast_zFbq8vOZ_0k">CS 61B 2014: Weighted graphs (video)</a></li>
    <li>[ ] <a href="https://www.youtube.com/watch?v=tKwnms5iRBU&index=16&list=PLUl4u3cNGP6317WaSNfmCvGym2ucw3oGp">Greedy Algorithms: Minimum Spanning Tree (video)</a></li>
    <li>[ ] <a href="https://www.youtube.com/watch?v=RpgcYiky7uw">Strongly Connected Components Kosaraju's Algorithm Graph Algorithm (video)</a></li>
  </ul>
</ul>
<ul>
  <li>Full Coursera course: <a href="https://www.coursera.org/learn/algorithms-on-graphs/home/welcome"> Algorithms on Graphs </a></li>
</ul>
<ul>
  <li>[ ] Try implementing:</li>
  <ul>
    <li>[ ] DFS with adjacency list (recursive)</li>
    <li>[ ] DFS with adjacency list (iterative with stack)</li>
    <li>[ ] DFS with adjacency matrix (recursive)</li>
    <li>[ ] DFS with adjacency matrix (iterative with stack)</li>
    <li>[ ] BFS with adjacency list</li>
    <li>[ ] BFS with adjacency matrix</li>
    <li>[ ] Dijkstra algorithm - single-source shortest path</li>
    <li>[ ] minimum spanning tree</li>
    <ul>
      <li>DFS-based algorithms (see Aduni videos above):</li>
      <li>[ ] check for cycle (needed for topological sort, since we'll check for cycle before starting)</li>
      <li>[ ] topological sort</li>
      <li>[ ] count connected components in a graph</li>
      <li>[ ] list strongly connected components</li>
      <li>[ ] check for bipartite graph</li>
    </ul>
  </ul>
</ul>
<ul>
  <li>Detect Cycles</li>
  <ul>
    <li>[ ] <a href="https://www.geeksforgeeks.org/detect-cycle-in-a-graph/">Detect Cycle in a Directed Graph</a></li>
    <li>[ ] <a href="https://www.geeksforgeeks.org/detect-cycle-undirected-graph/">Detect Cycle in an Undirected Graph</a></li>
  </ul>
</ul>
<ul>
  <li>Disjoint Set</li>
  <ul>
    <li>[ ] <a href="https://www.geeksforgeeks.org/union-find/">Introduction</a></li>
    <li>[ ] <a href="https://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/">Union-Find Algorithm</a></li>
    <li>[ ] <a href="https://www.geeksforgeeks.org/union-find-algorithm-union-rank-find-optimized-path-compression/">Union-Find Algorithm - optimized path compression</a></li>
  </ul>
</ul>
</details>

---

## Sorting Algorithms

<a id="sorts"></a>
<details>
<summary>Sorting</summary>
<ul>
  <li>Stability in sorting algorithms ("Is Quicksort stable?")</li>
  <li>[ ] <a href="https://en.wikipedia.org/wiki/Sorting_algorithm#Stability">Sorting Algorithm Stability</a></li>
  <li>[ ] <a href="http://stackoverflow.com/questions/1517793/stability-in-sorting-algorithms">Stability In Sorting Algorithms</a></li>
  <li>[ ] <a href="http://www.geeksforgeeks.org/stability-in-sorting-algorithms/">Stability In Sorting Algorithms</a></li>
  <li>[ ] <a href="http://homepages.math.uic.edu/~leon/cs-mcs401-s08/handouts/stability.pdf">Sorting Algorithms - Stability</a></li>
  <li>Which algorithms can be used on linked lists? Which on arrays? Which on both?</li>
  <ul>
    <li>[ ] <a href="http://www.geeksforgeeks.org/merge-sort-for-linked-list/">Merge Sort For Linked List</a></li>
  </ul>
</ul>
<ul>
  <li>[ ] <a href="https://www.youtube.com/watch?v=P00xJgWzz2c&index=1&list=PL89B61F78B552C1AB">Bubble Sort (video)</a></li>
  <ul>
    <li><a href="https://www.youtube.com/watch?v=ni_zk257Nqo&index=7&list=PL89B61F78B552C1AB">analyzing bubble sort (video)</a></li>
    <li>Time complexity: O(n^2)</li>
    <li>Space Complexity: O(1)</li>
    <li>stable</li>
  </ul>
</ul>
<ul>
  <li>[ ] <a href="https://www.youtube.com/watch?v=6nDMgr0-Yyo&index=8&list=PL89B61F78B552C1AB">Selection Sort (video)</a></li>
  <ul>
    <li>Time complexity: O(n^2)</li>
    <li>Space Complexity: O(1)</li>
    <li>not stable</li>
  </ul>
</ul>
<ul>
  <li>[ ] <a href="https://www.youtube.com/watch?v=c4BRHC7kTaQ&index=2&list=PL89B61F78B552C1AB">Insertion Sort (video)</a></li>
  <ul>
    <li>Time complexity: O(n^2)</li>
    <li>Space Complexity: O(1)</li>
    <li>stable</li>
  </ul>
</ul>
<ul>
  <li>[ ] <a href="https://www.youtube.com/watch?v=GCae1WNvnZM&index=3&list=PL89B61F78B552C1AB">Merge Sort (video)</a></li>
  <ul>
    <li>Time complexity: O(nlogn)</li>
    <li>Space Complexity: O(n)</li>
    <li>stable</li>
  </ul>
</ul>
<ul>
  <li>[ ] <a href="https://www.youtube.com/watch?v=y_G9BkAm6B8&index=4&list=PL89B61F78B552C1AB">Quick Sort (video)</a></li>
  <ul>
    <li>Time complexity: O(nlogn)</li>
    <li>Space Complexity: O(log n)</li>
    <li>not stable</li>
  </ul>
</ul>
<ul>
  <li>[ ] <a href="https://www.geeksforgeeks.org/heap-sort/">Heap Sort</a></li>
  <ul>
    <li>Time complexity: O(nlogn)</li>
    <li>Space Complexity: O(1)</li>
    <li>not stable</li>
  </ul>
</ul>
<ul>
  <li>[ ] <a href="https://www.geeksforgeeks.org/counting-sort/">Counting Sort</a></li>
  <ul>
  <li>Time complexity: O(n + k), k = max non-negative value</li>
  <li>Space Complexity: O(k)</li>
  </ul>
</ul>
</details>

---

## Practice Problems

|  #  | Tags           |              |       Problems Set       | Easy | Medium | Hard | BOJ Problems |
| :-: | :------------- | :----------- | :----------------------: | :--: | :----: | :--: | :----------: |
| 01  | Data Structure | Arrays       |   [View](./01-arrays)    |  12  |   1    |  2   |      0       |
| 02  | Data Structure | Linked Lists | [View](./02-linkedlists) |  10  |   5    |  3   |      0       |
| 03  | Data Structure | Stack        |    [View](./03-stack)    |  4   |   6    |  4   |      10      |

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
