#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INF 0x7fffffff

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

/* Functions for Node */
static Node *node_alloc(int);

typedef struct {
    Node *head;
    Node *tail;
    int size;
} DoublyLinkedList;

/* Functions for inked list */
int front(DoublyLinkedList **);
int back(DoublyLinkedList **);
int nth_node_from_end(DoublyLinkedList **, int);

void insert(DoublyLinkedList **, int, int);
void push_front(DoublyLinkedList **, int);
void push_back(DoublyLinkedList **, int);
int pop_front(DoublyLinkedList **);
int pop_back(DoublyLinkedList **);
int value_at(DoublyLinkedList **, int);
void erase(DoublyLinkedList **, int);
void remove_value(DoublyLinkedList **, int);
void reverse(DoublyLinkedList **);

int size(DoublyLinkedList **);
_Bool empty(DoublyLinkedList **);
void init(DoublyLinkedList **);
void destroy(DoublyLinkedList **);
void print(DoublyLinkedList **);

int main(void) {
    unsigned seed = time(0);
    srand(seed);

    DoublyLinkedList *list;
    init(&list);

    for (int i = 0; i < 10; ++i) {
        int data = rand() % 100;
        switch (rand() % 2) {
            case 0:
                push_back(&list, data);
                break;
            case 1:
                push_front(&list, data);
                break;
        }
        print(&list);
    }

    destroy(&list);

    init(&list);
    push_front(&list, 17);
    push_back(&list, 71);
    for (int i = 0; i < 20; ++i) {
        int data = rand() % 100;
        int idx = data % 10;
        printf("inserting %d at %d\n", data, idx);
        insert(&list, idx, data);
        print(&list);
    }

    push_back(&list, 17);
    print(&list);

    reverse(&list);
    print(&list);

    while (size(&list) > 1) {
        erase(&list, 0);
        print(&list);
        if (size(&list) % 5 == 0) reverse(&list);
    }
    printf("removing value 17\n");
    remove_value(&list, 17);
    print(&list);

    destroy(&list);

    init(&list);
    for (int i = 0; i < 5; ++i) {
        push_back(&list, i + 1);
    }

    print(&list);

    for (int i = 0; i < 5; ++i) {
        printf("get index %d node from the end: %d\n", i,
               nth_node_from_end(&list, i));
    }
    printf("get index 10 node from the end: %d\n",
           nth_node_from_end(&list, 10));

    reverse(&list);
    print(&list);
    for (int i = 0; i < 5; ++i) {
        printf("get index %d node from the end: %d\n", i,
               nth_node_from_end(&list, i));
    }
    printf("get index 10 node from the end: %d\n",
           nth_node_from_end(&list, 10));

    destroy(&list);
    return 0;
}

/* Functions for Node Structure */
static Node *node_alloc(int data) {
    Node *new_node = (Node *)(malloc(sizeof(Node)));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

/* Functions for Linked List Structure */
int front(DoublyLinkedList **list) {
    if (!empty(list)) {
        return (*list)->head->data;
    }

    printf("[[ front -- List is empty. ]]\n");
    return INF;
}

int back(DoublyLinkedList **list) {
    if (!empty(list)) {
        return ((*list)->tail)->data;
    }

    printf("[[ back -- List is empty. ]]\n");
    return INF;
}

int nth_node_from_end(DoublyLinkedList **list, int index) {
    if (empty(list)) {
        printf("[[ nth_node_from_end -- list is empty ]]\n");
        return -1;
    }
    if (index > (*list)->size) {
        printf("[[ nth_node_from_end -- out of bound ]]\n");
        return -1;
    }

    Node *curr = (*list)->tail;
    for (int i = 0; i < index; ++i) {
        curr = curr->prev;
    }

    return curr->data;
}

void insert(DoublyLinkedList **list, int index, int value) {
    if (index < 0 || index > (*list)->size) {
        printf("[[ insert - Index out of bound ]] ");
        return;
    }
    if ((*list)->size == 0 || index == 0) {
        push_front(list, value);
    } else if (index == (*list)->size) {
        push_back(list, value);
    } else {
        Node *new_node = node_alloc(value);
        Node *curr = (*list)->head;
        for (int i = 1; i < index; ++i) {
            curr = curr->next;
        }

        new_node->prev = curr;
        new_node->next = curr->next;
        curr->next->prev = new_node;
        curr->next = new_node;
        ++((*list)->size);
    }
}

void push_front(DoublyLinkedList **list, int data) {
    if (empty(list)) {
        (*list)->tail = (*list)->head = node_alloc(data);
        (*list)->head->next = (*list)->tail;
        (*list)->tail->prev = (*list)->head;
    } else {
        Node *new_node = node_alloc(data);
        new_node->next = (*list)->head;
        (*list)->head->prev = new_node;
        (*list)->head = new_node;
    }

    ++((*list)->size);
}

void push_back(DoublyLinkedList **list, int data) {
    if (empty(list)) {
        (*list)->tail = (*list)->head = node_alloc(data);
        (*list)->head->next = (*list)->tail;
        (*list)->tail->prev = (*list)->head;
    } else {
        Node *new_node = node_alloc(data);
        (*list)->tail->next = new_node;
        new_node->prev = (*list)->tail;
        (*list)->tail = new_node;
    }

    ++((*list)->size);
}

int pop_front(DoublyLinkedList **list) {
    if (empty(list)) {
        printf("List is empty...");
        return -1;
    }

    if (size(list) == 1) {
        int data = (*list)->head->data;
        free((*list)->head);
        (*list)->head = (*list)->tail = NULL;
        (*list)->size = 0;
        return data;
    }

    int data = (*list)->head->data;
    (*list)->head = (*list)->head->next;
    free((*list)->head->prev);
    (*list)->head->prev = NULL;
    --((*list)->size);

    return data;
}

int pop_back(DoublyLinkedList **list) {
    if (empty(list)) {
        printf("List is empty...");
        return -1;
    }

    if (size(list) == 1) {
        int data = (*list)->head->data;
        free((*list)->head);
        (*list)->head = (*list)->tail = NULL;
        (*list)->size = 0;
        return data;
    }

    Node *curr = (*list)->tail;
    int data = curr->data;
    (*list)->tail = (*list)->tail->prev;
    (*list)->tail->next = NULL;
    free(curr);
    --((*list)->size);

    return data;
}

int value_at(DoublyLinkedList **list, int index) {
    if (index < 0 || index >= (*list)->size) {
        printf("[[ value_at -- Index out of bound ]]");
        return -1;
    }
    if (index == 0) {
        return front(list);
    }
    if (index == (*list)->size - 1) {
        return back(list);
    }

    Node *curr = (*list)->head;
    for (int i = 0; i < index; ++i) {
        curr = curr->next;
    }

    return curr->data;
}

void erase(DoublyLinkedList **list, int index) {
    if ((*list)->size == 1 || index == 0) {
        pop_front(list);
        return;
    }
    if (index == (*list)->size - 1) {
        pop_back(list);
        return;
    }

    Node *curr = (*list)->head;
    for (int i = 0; i < index; ++i) {
        curr = curr->next;
    }

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    free(curr);
    curr = NULL;
    --((*list)->size);
}

void remove_value(DoublyLinkedList **list, int value) {
    Node *curr = (*list)->head;

    while (curr && curr->data != value) {
        curr = curr->next;
    }

    if (!curr) {
        return;
    }
    if (curr == (*list)->head) {
        pop_front(list);
    } else {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        free(curr);
        --((*list)->size);
    }
}

void reverse(DoublyLinkedList **list) {
    printf("[[ reverse list ]]\n");
    Node *temp = NULL;
    Node *curr = (*list)->head;
    (*list)->tail = (*list)->head;
    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    if (temp != NULL) {
        (*list)->head = temp->prev;
    }
    (*list)->tail->next = NULL;
}

int size(DoublyLinkedList **list) { return (*list)->size; }

_Bool empty(DoublyLinkedList **list) { return (*list)->size == 0; }

void init(DoublyLinkedList **list) {
    *list = (DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
    (*list)->head = NULL;
    (*list)->tail = NULL;
    (*list)->size = 0;
}

void destroy(DoublyLinkedList **list) {
    printf("[[ destroying the list ]]\n");
    Node *curr = (*list)->head;
    while (curr && curr->next) {
        Node *temp = curr;
        curr = curr->next;
        free(temp);
    }
    if (curr) free(curr);
    (*list)->head = (*list)->tail = NULL;
    free(*list);
    *list = NULL;
}

void print(DoublyLinkedList **list) {
    Node *curr = (*list)->head;

    for (int i = 0; i < (*list)->size; ++i) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("   -- size(%d)   front(%d)    back(%d)\n", size(list), front(list),
           back(list));
}
