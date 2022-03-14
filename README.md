## Data Structures and Algorithms 

The original credit goes to the [coding-interview-university](https://github.com/jwasham/coding-interview-university).

I added and removed some parts to make it more suitable for myself to study (e.g. added implementations for doubly and circular-linked list, using different resources, etc...).

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
  + [Heap](#heap)
  + [Priority Queue](#priority-queue)
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
---

## Data Structures
- ### [Arrays](https://www.geeksforgeeks.org/array-data-structure/)
    - [x] [Introduction](https://www.geeksforgeeks.org/introduction-to-arrays/)
    - [x] Implement a vector (mutable array with automatic resizing) - [my implementation](./01_arrays/vector_implementation/main.c):
      - [x] New raw data array with allocated memory (default = 16, or power of 2 - 16, 32, 64, ...)
      - [x] size() - number of items
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
    - [Practice problems on Arrays](https://practice.geeksforgeeks.org/topics/Array/)
      - [Find minimum and maximum element in an array](https://practice.geeksforgeeks.org/problems/find-minimum-and-maximum-element-in-an-array4428/1/?category[]=Arrays&category[]=Arrays&problemStatus=unsolved&page=1&query=category[]ArraysproblemStatusunsolvedpage1category[]Arrays)
      - [Game with nos](https://practice.geeksforgeeks.org/problems/game-with-nos3123/1/?category[]=Arrays&category[]=Arrays&page=1&query=category[]Arrayspage1category[]Arrays)
      - [Play With OR](https://practice.geeksforgeeks.org/problems/play-with-or5515/1/?category[]=Arrays&category[]=Arrays&page=1&query=category[]Arrayspage1category[]Arrays)
      - [C++ Arrays (Sum of array) | Set 1](https://practice.geeksforgeeks.org/problems/c-arrays-sum-of-array-set-14805/1/?category[]=Arrays&category[]=Arrays&page=1&query=category[]Arrayspage1category[]Arrays)
      - [Cyclically rotate an array by one](https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1/?category[]=Arrays&category[]=Arrays&problemStatus=unsolved&page=1&query=category[]ArraysproblemStatusunsolvedpage1category[]Arrays)
      - [Display longest name](https://practice.geeksforgeeks.org/problems/display-longest-name0853/1/?category[]=Arrays&category[]=Arrays&problemStatus=unsolved&page=1&query=category[]ArraysproblemStatusunsolvedpage1category[]Arrays)
      - [Ishaan Loves Chocolates](https://practice.geeksforgeeks.org/problems/ishaan-loves-chocolates2156/1/?category[]=Arrays&category[]=Arrays&problemStatus=unsolved&page=1&query=category[]ArraysproblemStatusunsolvedpage1category[]Arrays)
      - [Number of Occurrence](https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1/?category[]=Arrays&category[]=Arrays&problemStatus=unsolved&page=2&query=category[]ArraysproblemStatusunsolvedpage2category[]Arrays)
      - [Count of smaller elements](https://practice.geeksforgeeks.org/problems/count-of-smaller-elements5947/1/?category[]=Arrays&category[]=Arrays&problemStatus=unsolved&page=1&query=category[]ArraysproblemStatusunsolvedpage1category[]Arrays)
      - [Total count](https://practice.geeksforgeeks.org/problems/total-count2415/1/?category[]=Arrays&category[]=Arrays&problemStatus=unsolved&page=2&query=category[]ArraysproblemStatusunsolvedpage2category[]Arrays)

- ### [Linked Lists](https://www.geeksforgeeks.org/data-structures/linked-list/)
    - [x] [Introduction](https://www.geeksforgeeks.org/linked-list-set-1-introduction/?ref=lbp)
    - [x] [Linked List vs Arrays](https://www.geeksforgeeks.org/linked-list-vs-array/?ref=lbp)
    - [x] Vector vs. List - [why you should avoid linked lists (video)](https://www.youtube.com/watch?v=YQs6IC-vgmo)
    - [x] [Pointers to Pointers](https://www.eskimo.com/~scs/cclass/int/sx8.html)
    - [x] Implement Singly-Linked List (with tail pointer) - [my implementation](./02_linked_list/01_singly_linked_list/main.c):
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
      - [x] remove_value(value) - removes the first item in the list with this value
      - Practice problems
        - [Count nodes of linked list](https://practice.geeksforgeeks.org/problems/count-nodes-of-linked-list/1/?category[]=Linked%20List&category[]=Linked%20List&page=1&query=category[]Linked%20Listpage1category[]Linked%20List)
        - [Linked List Length Even or Odd?](https://practice.geeksforgeeks.org/problems/linked-list-length-even-or-odd/1/?category[]=Linked%20List&category[]=Linked%20List&problemStatus=unsolved&page=1&query=category[]Linked%20ListproblemStatusunsolvedpage1category[]Linked%20List)
        - [Identical Linked Lists](https://practice.geeksforgeeks.org/problems/identical-linked-lists/1/?category[]=Linked%20List&category[]=Linked%20List&problemStatus=unsolved&page=1&query=category[]Linked%20ListproblemStatusunsolvedpage1category[]Linked%20List)
        - [Linked List Insertion](https://practice.geeksforgeeks.org/problems/linked-list-insertion-1587115620/1/?page=1&difficulty[]=-2&difficulty[]=-1&status[]=unsolved&category[]=Linked%20List&sortBy=submissions#)
        - [Print Linked List](https://practice.geeksforgeeks.org/problems/print-linked-list-elements/1/?page=1&difficulty[]=-2&difficulty[]=-1&status[]=unsolved&category[]=Linked%20List&sortBy=submissions)
        - [Node at a given index](https://practice.geeksforgeeks.org/problems/node-at-a-given-index-in-linked-list/1/?page=1&difficulty[]=-2&difficulty[]=-1&status[]=unsolved&category[]=Linked%20List&sortBy=submissions)
        - [Insert in Middle of Linked List](https://practice.geeksforgeeks.org/problems/insert-in-middle-of-linked-list/1/?page=1&difficulty[]=-2&difficulty[]=-1&status[]=unsolved&category[]=Linked%20List&sortBy=submissions#)
    - [x] Doubly-linked List - [my implementation](./02_linked_list/02_doubly_linked_list/main.c):
      - [x] [Introduction](https://www.geeksforgeeks.org/doubly-linked-list/)
      - [x] push_front(value) - adds an item to the front of the list
      - [x] pop_front() - remove front item and return its value
      - [x] push_back(value) - adds an item at the end
      - [x] pop_back() - removes end item and returns its value
      - [x] insert(index, value) - insert value at index, so current item at that index is pointed to by new item at index
      - [x] erase(index) - removes node at given index
      - [x] value_n_from_end(n) - returns the value of the node at nth position from the end of the list
      - [x] reverse() - reverses the list
      - [x] remove_value(value) - removes the first item in the list with this value
    - [x] XOR Linked List - [my implementation](./02_linked_list/04_xor_linked_list/main.c)
      - [x] [A Memory Efficient Doubly Linked List | Part 1](https://www.geeksforgeeks.org/xor-linked-list-a-memory-efficient-doubly-linked-list-set-1/)
      - Implement:
      - [x] traverse - print all values in the list in forward direction
      - [x] push_front(value) - adds an item to the front of the list
      - [x] pop_front() - remove front item and return its value
      - [x] push_back(value) - adds an item at the end
      - [x] pop_back() - removes end item and returns its value
      - [x] front() - get value of front item
      - [x] back() - get value of end item
      - [x] insert(index, value) - insert value at index, so current item at that index is pointed to by new item at index
    - [x] Circular-Linked List (singly linked list) - [my implementation](./02_linked_list/03_circular_linked_list/main.c):
      - [x] [Introduction](https://www.geeksforgeeks.org/circular-linked-list/?ref=lbp)
      - [x] front() - get value of front item
      - [x] back() - get value of end item
      - [x] value_n_from_end(n) - returns the value of the node at nth position from the end of the list
      - [x] insert(index, value) - insert value at index, so current item at that index is pointed to by new item at index
      - [x] push_front(data) - adds an item to the front of the list
      - [x] pop_front() - remove front item and return its data
      - [x] push_back(data) - adds an item at the end
      - [x] pop_back() - removes end item and returns its data
      - [x] reverse() - reverses the list
      - Practice problems
        - [Check if a circular linked list](https://practice.geeksforgeeks.org/problems/circular-linked-list/1/?page=1&difficulty[]=-2&difficulty[]=-1&status[]=unsolved&category[]=Linked%20List&sortBy=submissions)

- ### [Stack](https://www.geeksforgeeks.org/stack-data-structure)
  - [x] [Introduction](https://www.geeksforgeeks.org/stack-data-structure-introduction-program/)
  - [x] Implement using linked-list ([my implementation](./03_stack/01_linkedlist/main.c)): 
    - [x] push(data) - adds data at position top
    - [x] pop() - returns data and removes recently added element (top)
    - [x] peek() - returns data at top of the stack
    - [x] empty()
  - [x] Implement using fixed-sized array ([my implementation](./03_stack/02_array/main.c)):
    - [x] push(data) - adds data at position top
    - [x] pop() - returns data and removes recently added element (top)
    - [x] peek() - returns data at top of the stack
    - [x] empty()
    - [x] full()
  - [x] Cost:
    - push: O(1) (amortized, linked list and array)
    - pop: O(1) (linked list and array)
    - empty: O(1) (linked list and array)
  - [Practice problems on Stack](https://practice.geeksforgeeks.org/topics/Stack/)
    - [Implement stack using array](https://practice.geeksforgeeks.org/problems/implement-stack-using-array/1/?page=1&status[]=unsolved&category[]=Stack&sortBy=submissions#)
    - [Implement stack using linked list](https://practice.geeksforgeeks.org/problems/implement-stack-using-linked-list/1/?page=1&status[]=unsolved&category[]=Stack&sortBy=submissions)
    - [Get minimum element from stack](https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1/?page=1&category[]=Stack&sortBy=submissions#)
    - [Parenthesis checker](https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1/?page=1&category[]=Stack&sortBy=submissions)
    - [Reverse a string using stack](https://practice.geeksforgeeks.org/problems/reverse-a-string-using-stack/1/?page=2&status[]=unsolved&category[]=Stack&sortBy=submissions)
- ### [Queue](https://www.geeksforgeeks.org/queue-data-structure/)
  - [x] [Introduction](https://www.geeksforgeeks.org/queue-set-1introduction-and-array-implementation/)
  - [x] [Circular Queue (Ring Buffer)](https://www.geeksforgeeks.org/circular-queue-set-1-introduction-array-implementation/)
  - [x] Implement a circular queue - [my implementation](./04_queue/01_circular_queue/main.c) : 
    - [x] enqueue(data) - adds data at position at tail
    - [x] dequeue() - returns data and removes least recently added element (front)
    - [x] empty()
    - [x] full()
    - [x] front() - gets the first element
    - [x] rear() - gets the last element
  - [x] Cost:
    - enqueue: O(1) (amortized, linked list and array)
    - dequeue: O(1) (linked list and array)
    - empty: O(1) (linked list and array)
  - [Practice problems on Queue](https://practice.geeksforgeeks.org/topics/Queue/)
    - [Queue using two stacks](https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1/?page=1&difficulty[]=0&status[]=unsolved&category[]=Queue&sortBy=submissions#)
    - [Stack using two queues](https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1/?page=1&difficulty[]=0&status[]=unsolved&category[]=Queue&sortBy=submissions)
    - [Reverse first K elements of queue](https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1/?page=1&difficulty[]=0&status[]=unsolved&category[]=Queue&sortBy=submissions)

- ### [Hash table](https://www.geeksforgeeks.org/hashing-data-structure/)
    - [x] [Introduction](https://www.educative.io/edpresso/what-is-hashing)
      - what is hashing? collision? where is it used?
      - extra [resource](https://computersciencewiki.org/index.php/Hashing)
    - [x] [Fundamentals of data structures: Hashing](https://en.wikibooks.org/wiki/A-level_Computing/AQA/Paper_1/Fundamentals_of_data_structures/Hash_tables_and_hashing)
      - [x] Hashing tables
      - [x] Hashing Algorithms
      - [x] Collisions (open and closed addressing)
    - [x] Implement with array using linear probing
      - hash(k, m) - m is size of hash table
      - add(key, value) - if key already exists, update value
      - exists(key)
      - get(key)
      - remove(key)
      - resources: [1](https://www.sanfoundry.com/c-program-implement-hash-tables-linear-probing/), [2](https://benhoyt.com/writings/hash-table-in-c/)
    - [Practice problems on Hashing](https://practice.geeksforgeeks.org/topics/hashing/)
      - https://leetcode.com/problems/two-sum/  
      - https://leetcode.com/problems/linked-list-cycle/
---

## Trees

- ### [Binary Tree](https://www.geeksforgeeks.org/binary-tree-data-structure/)
    - [x] [Introduction](https://www.geeksforgeeks.org/binary-tree-set-1-introduction/)
    - [x] [Properties](https://www.geeksforgeeks.org/binary-tree-set-2-properties/)
    - [x] [Types of Binary Tree](https://www.geeksforgeeks.org/binary-tree-set-3-types-of-binary-tree/)
    - [x] [BFS(breadth-first search) and DFS(depth-first search)](https://www.geeksforgeeks.org/bfs-vs-dfs-binary-tree/)
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
    - [Practice problem on Binary Tree](https://practice.geeksforgeeks.org/topics/Tree/)
      - Inorder Traversal
      - Preorder Traversal
      - Postorder Traversal
      - Count Leaves in Binary Tree
      - Minimum element in BST
      - Size of Binary Tree
      - Height of Heap
      - Sum of Binary Tree
      - Count Non-Leaf Nodes in Tree

- ### [Binary search tree](https://www.geeksforgeeks.org/binary-search-tree-data-structure/)
    - [x] [Searching & Insertion](https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/)
    - [ ] [Deletion](https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/)
    - Deletion Notes: 
      - Node to be deleted is the leaf: simply remove the node.
      - Node to be deleted has only one child: copy the child to the node and delete the child node.
      - Node to be deleted has two children: find **inorder successor**
        - inorder successor - the minimum value in the right child of the node.
    - [ ] [Handling duplicate values in BST](https://www.geeksforgeeks.org/how-to-handle-duplicates-in-binary-search-tree/)
    - [ ] [Advantages of BST over Hash Table](https://www.geeksforgeeks.org/advantages-of-bst-over-hash-table/)
    - [ ] Implement:
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
  - [Practice problems on BST](https://practice.geeksforgeeks.org/topics/Binary%20Search%20Tree/?ref=taocp)

- ### Self Balancing BST
  - AVL Tree 
    - [Insertion](https://www.geeksforgeeks.org/avl-tree-set-1-insertion/)
    - [Deletion](https://www.geeksforgeeks.org/avl-tree-set-2-deletion/)
    - [AVL with duplicate values](https://www.geeksforgeeks.org/avl-with-duplicate-keys/)
    - [visualization](https://www.cs.usfca.edu/~galles/visualization/AVLtree.html)
  - Red Black Tree
    - [Introduction](https://www.geeksforgeeks.org/red-black-tree-set-1-introduction-2/)
    - [Insertion](https://www.geeksforgeeks.org/red-black-tree-set-2-insert/)
    - [Deletion](https://www.geeksforgeeks.org/red-black-tree-set-3-delete-2/)
  
- ### [Heap](https://www.geeksforgeeks.org/heap-data-structure/)
    - Resources
      - [ ] [Array representation of Binary Heap](https://www.geeksforgeeks.org/array-representation-of-binary-heap/)
      - [ ] [Binary Heap](https://www.geeksforgeeks.org/binary-heap/)
      - [ ] [How to build min and max heaps](https://www.educative.io/blog/data-structure-heaps-guide)
    - [ ] Implement a max-heap:
      - [ ] max_heapify - rearranges the elements in the heap to maintain the max heap property.
      - [ ] insert(data) - adds data to a heap
      - [ ] remove_max(data) - removes max data in a heap 
      - [ ] extract - returns the data and remove it from the heap
      - [ ] is_empty() - returns true if heap contains no elements
      - [ ] get_size() - returns the size of the heap
      - [ ] get_max() - returns the max item, without removing it
    - [ ] Implement a min-heap:
      - [ ] min_heapify - rearranges the elements in the heap to maintain the min heap property.
      - [ ] min() - returns the min item, without removing it
      - [ ] remove_min(data) - removes min data in a heap 
  - [Practice problems on Heap](https://practice.geeksforgeeks.org/explore/?category%5B%5D=Heap&page=1&category%5B%5D=Heap)


- ### Priority Queue
  - [ ] [Introduction](https://www.geeksforgeeks.org/priority-queue-set-1-introduction/?ref=lbp)
  - [ ] Implement using linked-list:
    - [ ] push(data) - inserts new data into the queue.
    - [ ] pop() - removes the element with the highest priority from the queue.
    - [ ] peek() - gets the highest priority element in the queue without removing it from the queue.
    - Cost notes:
      - enqueue - O(n)
      - dequeue - O(1)
      - peek - O(1)
  - [ ] Implement using fixed-size array:
    - [ ] enqueue(data) - inserts new data into the queue.
    - [ ] dequeue() - removes the element with the highest priority from the queue.
    - [ ] peek() - gets the highest priority element in the queue without removing it from the queue.
    - Cost notes:
      - enqueue - O(1)
      - dequeue - O(n)
      - peek - O(n)
  - [ ] Implement using Binary Heap - max heap:
    - [ ] insert(p) - Inserts a new element with priority p.
    - [ ] extractMax() - Extracts an element with maximum priority.
    - [ ] remove(i) - Removes an element pointed by an iterator i.
    - [ ] getMax() - Returns an element with maximum priority.
    - [ ] changePriority(i, p) - Changes the priority of an element pointed by i to p.
    - Cost notes:
      - enqueue - O(log n)
      - dequeue - O(log n)
      - peek - O(1)

---

## [Graph](https://www.geeksforgeeks.org/graph-data-structure-and-algorithms/)
  - [Graph and its representations](https://www.geeksforgeeks.org/graph-and-its-representations/)
  - ### Traversals
    - [Breadth First Search](https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/)
    - [Depth First Search](https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/)
    - [Iterative Depth First Search](https://www.geeksforgeeks.org/iterative-depth-first-traversal/)
  - [ ] Try implementing:
    - [ ] DFS with adjacency list (recursive)
    - [ ] DFS with adjacency list (iterative with stack)
    - [ ] DFS with adjacency matrix (recursive)
    - [ ] DFS with adjacency matrix (iterative with stack)
    - [ ] BFS with adjacency list
    - [ ] BFS with adjacency matrix
    - [ ] Dijkstra algorithm - single-source shortest path
  - ### Detect Cycles
    - [ ] [Detect Cycle in a Directed Graph](https://www.geeksforgeeks.org/detect-cycle-in-a-graph/)
    - [ ] [Detect Cycle in an Undirected Graph](https://www.geeksforgeeks.org/detect-cycle-undirected-graph/)
  - ### Disjoint Set
    - [ ] [Introduction](https://www.geeksforgeeks.org/union-find/)
    - [ ] [Union-Find Algorithm](https://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/)
    - [ ] [Union-Find Algorithm - optimized path compression](https://www.geeksforgeeks.org/union-find-algorithm-union-rank-find-optimized-path-compression/)
  - [Practice problems on Graph](https://practice.geeksforgeeks.org/topics/Graph/?ref=taocp)

---

## Sorting
- [ ] [Bubble Sort](https://www.geeksforgeeks.org/bubble-sort/)
  - Time complexity: O(n^2)
  - Space Complexity: O(1)
  - stable
- [ ] [Selection Sort](https://www.geeksforgeeks.org/selection-sort/)
  - Time complexity: O(n^2)
  - Space Complexity: O(1)
  - not stable
- [ ] [Insertion Sort](https://www.geeksforgeeks.org/insertion-sort/)
  - Time complexity: O(n^2)
  - Space Complexity: O(1)
  - stable
- [ ] [Merge Sort](https://www.geeksforgeeks.org/merge-sort/)
  - Time complexity: O(n log n)
  - Space Complexity: O(n)
  - stable
- [ ] [Quick Sort](https://www.geeksforgeeks.org/quick-sort/)
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
