## Linked List 

Linked list is a linear data structure like arrays, but thery are not stored contiguously in memory; data are linked using pointers.

## Why use Linked Lists?
The size is fixed in arrays and we need to know the upper limit in advance to look up data, insert data, traverse, etc...

Also it's costly to insert or delete an element because we first need to shift all existing elements to create a space for insert or remove existing space for delete to do the operation.

## Advantages of Linked List
1. The size is dynamic. 
2. Easier insert and delete.

## Disadvantages of Linked List
1. No random access. We must traverse from the head node and use a pointer to traverse.
2. Extra memory for the pointer itself that references the next node.
3. No cache friendly.

## Linked List Structures
### Singly Linked List
```c
struct Node {
    int data;
    struct Node *next;
}
```

### Doubly Linked List
```c
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}
```