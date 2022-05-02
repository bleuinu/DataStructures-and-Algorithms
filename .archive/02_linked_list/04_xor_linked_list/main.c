#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INF 0x7fffffff

typedef struct Node {
    int data;
    struct Node *xpn;  // XOR of address(previous) and address(next)
} Node;

/* Functions for Node */
static Node *node_alloc(int);

typedef struct {
    Node *head;
    Node *tail;
    int size;
} XORLinkedList;

/* Functions for inked list */
/* private */
inline static uint64_t addr(Node *node) { return (uint64_t)(node); }
inline static Node* xor(Node * x, Node *y) {
    return (Node *)(addr(x) ^ addr(y));
} 
static void destroy(XORLinkedList *);

/* public */
void insert(XORLinkedList *, int, int);
void push_front(XORLinkedList *, int);
void push_back(XORLinkedList *, int);
int pop_front(XORLinkedList *);
int pop_back(XORLinkedList *);
inline static int front(XORLinkedList *);
inline static int back(XORLinkedList *);

/* Helper functions */
inline static _Bool empty(XORLinkedList *list) { return list->size == 0; }
inline static int size(XORLinkedList *list) { return list->size; }
void print(XORLinkedList *);

int main(void) {
    unsigned seed = time(0);
    srand(seed);

    XORLinkedList list = {.head = NULL, .size = 0};

    insert(&list, 0, 1);
    insert(&list, 1, 2);
    insert(&list, 0, 3);
    print(&list);
    insert(&list, 1, 4);
    print(&list);

    for (int i = 0; i < 5; ++i) {
        int data = rand() % 100;
        push_front(&list, data);
        print(&list);
    }

    for (int i = 0; i < 5; ++i) {
        int data = rand() % 100;
        push_back(&list, data);
        print(&list);
    }

    for (int i = 0; i < 5; ++i) {
        switch (rand() % 2) {
            case 0:
                pop_back(&list);
                break;
            case 1:
                pop_front(&list);
        }
        print(&list);
    }

    for (int i = 0; i < 5; ++i) {
        int data = rand() % 100;
        switch (rand() % 2) {
            case 0:
                push_back(&list, data);
                break;
            case 1:
                push_front(&list, data);
        }
        print(&list);
    }

    destroy(&list);
    printf("size: %d\n", size(&list));
    print(&list);
    
    return 0;
}

/***********************************************
 *  Functions for Node Structure
 * ********************************************/
static Node *node_alloc(int data) {
    Node *new_node = (Node *)(malloc(sizeof(Node)));
    new_node->data = data;
    new_node->xpn = 0;

    return new_node;
}

/***********************************************
 *  Functions for Linked List Structure
 * ********************************************/
static void destroy(XORLinkedList *list) {
    Node *curr = list->head;
    Node *prev = NULL;
    Node *next = NULL;
    
    while (curr != NULL) {
        next = xor(prev, curr->xpn);
        prev = curr;
        free(curr);
        --(list->size);
        curr = next;
    }
}

void insert(XORLinkedList *list, int index, int data) {
    if (index < 0 || index > list->size) {
        printf("[[ insert -- invalid index ]]\n");
        return;
    }
    if (index == 0 || empty(list)) {
        push_front(list, data);
    } else if (index == list->size) {
        push_back(list, data);
    } else {
        printf("[[ insert -- %d at index %d]]\n", data, index);
        Node *curr = list->head;
        Node *prev = NULL;
        Node *next = NULL;
        Node *new_node = node_alloc(data);

        for (int i = 1; i < index; ++i) {
            next = xor(prev, curr->xpn);
            prev = curr;
            curr = next;
        }
        next = xor(prev, curr->xpn);

        Node *temp = xor(curr->xpn, next);
        curr->xpn = xor(temp, new_node);

        if (next != NULL) {
            // Update pointer of next
            next->xpn = xor(new_node, xor(next->xpn, curr));
        }
        new_node->xpn = xor(curr, next);

        ++(list->size);
    }
}

void push_front(XORLinkedList *list, int data) {
    printf("[[ push_front: data(%d)]]\n", data);
    Node *new_node = node_alloc(data);
    new_node->xpn = list->head;

    if (empty(list)) {
        list->head = new_node;
        list->tail = list->head;
    } else {
        list->head->xpn = xor(new_node, list->head->xpn);
        list->head = new_node;
    }

    ++(list->size);
}

void push_back(XORLinkedList *list, int data) {
    printf("[[ push_back: data(%d)]]\n", data);
    if (empty(list)) {
        push_front(list, data);
        return;
    }

    Node *new_node = node_alloc(data);
    new_node->xpn = list->tail;
    list->tail->xpn = xor(list->tail->xpn, new_node);
    list->tail = new_node;

    ++(list->size);
}

int pop_front(XORLinkedList *list) {
    Node *curr = list->head;
    Node *prev = NULL;
    Node *next = NULL;

    if (empty(list)) {
        printf("[[ pop_front - list is empty ]]\n");
        return -1;
    }

    int data = curr->data;
    printf("[[ pop_front - pop %d]]\n", data);
    next = xor(prev, curr->xpn);
    prev = curr;
    curr = next;

    list->head = curr;
    list->head->xpn = xor(prev, curr->xpn);
    free(prev);

    --(list->size);
    return data;
}

int pop_back(XORLinkedList *list) {
    Node *curr = list->tail;
    Node *prev = NULL;
    Node *next = NULL;

    if (empty(list)) {
        printf("[[ pop_back - list is empty ]]\n");
        return -1;
    }

    int data = list->tail->data;
    printf("[[ pop_back - pop %d]]\n", data);
    Node *prev_tail = curr->xpn;
    prev_tail->xpn = xor(prev_tail->xpn, list->tail);
    free(list->tail);
    list->tail = prev_tail;

    --(list->size);
    return data;
}

inline static int front(XORLinkedList *list) {
    return (list->size == 0) ? -1 : list->head->data;
}
inline static int back(XORLinkedList *list) {
    return (list->size == 0) ? -1 : list->tail->data;
}

void print(XORLinkedList *list) {
    if (!list || empty(list)) return;
    Node *curr = list->head;
    Node *prev = NULL;
    Node *next = NULL;

    while (curr != NULL) {
        printf("%d ", curr->data);

        next = xor(prev, curr->xpn);
        prev = curr;
        curr = next;
    }
    printf(" -- front(%d)   back(%d)\n", front(list), back(list));
}