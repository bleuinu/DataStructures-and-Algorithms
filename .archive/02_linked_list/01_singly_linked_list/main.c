#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INF 0x7fffffff

typedef struct Node {
    int data;
    struct Node *next;
} Node;

/* Functions for Node */
static Node *node_alloc(int);

typedef struct {
    Node *head;
    Node *tail;
    int size;
} SinglyLinkedList;

/* Functions for inked list */
int front(SinglyLinkedList **);
int back(SinglyLinkedList **);
int nth_node_from_end(SinglyLinkedList **, int);

void insert(SinglyLinkedList **, int, int);
void push_front(SinglyLinkedList **, int);
void push_back(SinglyLinkedList **, int);
int pop_front(SinglyLinkedList **);
int pop_back(SinglyLinkedList **);
int value_at(SinglyLinkedList **, int);
void erase(SinglyLinkedList **, int);
void remove_value(SinglyLinkedList **, int);
void reverse(SinglyLinkedList **);

int size(SinglyLinkedList **);
_Bool empty(SinglyLinkedList **);
void init(SinglyLinkedList **);
void destroy(SinglyLinkedList **);
void print(SinglyLinkedList **);

int main(void) {
    unsigned seed = time(0);
    srand(seed);

    SinglyLinkedList *list;
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

    return new_node;
}

/* Functions for Linked List Structure */
int front(SinglyLinkedList **list) {
    if (!empty(list)) {
        return (*list)->head->data;
    }

    printf("[[ front -- List is empty. ]]\n");
    return INF;
}

int back(SinglyLinkedList **list) {
    if (!empty(list)) {
        return ((*list)->tail)->data;
    }

    printf("[[ back -- List is empty. ]]\n");
    return INF;
}

int nth_node_from_end(SinglyLinkedList **list, int index) {
    if (empty(list)) {
        printf("[[ nth_node_from_end -- list is empty ]]\n");
        return -1;
    }
    if (index > (*list)->size) {
        printf("[[ nth_node_from_end -- out of bound ]]\n");
        return -1;
    }

    int cnt = (*list)->size - index;
    Node *curr = (*list)->head;
    for (int i = 1; i < cnt; ++i) {
        curr = curr->next;
    }

    return curr->data;
}

void insert(SinglyLinkedList **list, int index, int value) {
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

        new_node->next = curr->next;
        curr->next = new_node;
        ++((*list)->size);
    }
}

void push_front(SinglyLinkedList **list, int data) {
    if (empty(list)) {
        (*list)->tail = (*list)->head = node_alloc(data);
        (*list)->head->next = (*list)->tail;
    } else {
        Node *new_node = node_alloc(data);
        new_node->next = (*list)->head;
        (*list)->head = new_node;
    }

    ++((*list)->size);
}

void push_back(SinglyLinkedList **list, int data) {
    if (empty(list)) {
        (*list)->tail = (*list)->head = node_alloc(data);
        (*list)->head->next = (*list)->tail;
    } else {
        Node *new_node = node_alloc(data);
        (*list)->tail->next = new_node;
        (*list)->tail = new_node;
    }

    ++((*list)->size);
}

int pop_front(SinglyLinkedList **list) {
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

    Node *temp = (*list)->head;
    (*list)->head = (*list)->head->next;
    int data = temp->data;
    free(temp);
    --((*list)->size);

    return data;
}

int pop_back(SinglyLinkedList **list) {
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

    Node *curr = (*list)->head;
    while (curr->next != (*list)->tail) {
        curr = curr->next;
    }
    int data = curr->next->data;
    free(curr->next);
    curr->next = NULL;
    (*list)->tail = curr;
    --((*list)->size);

    return data;
}

int value_at(SinglyLinkedList **list, int index) {
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

void erase(SinglyLinkedList **list, int index) {
    if ((*list)->size == 1 || index == 0) {
        pop_front(list);
        return;
    }
    if (index == (*list)->size - 1) {
        pop_back(list);
        return;
    }

    Node *curr = (*list)->head;
    for (int i = 1; i < index; ++i) {
        curr = curr->next;
    }

    Node *temp = curr->next->next;
    free(curr->next);
    curr->next = temp;
    --((*list)->size);
}

void remove_value(SinglyLinkedList **list, int value) {
    Node *curr = (*list)->head;
    Node *prev = curr;

    while (curr && curr->data != value) {
        prev = curr;
        curr = curr->next;
    }

    if (!curr) {
        return;
    }
    if (curr == prev) {
        pop_front(list);
    } else if (prev->next == curr) {
        prev->next = curr->next;
        free(curr);
        --((*list)->size);
    }
}

void reverse(SinglyLinkedList **list) {
    printf("[[ reverse list ]]\n");
    Node *temp = (*list)->head;
    Node *curr = (*list)->head;
    Node *prev = NULL;
    Node *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    (*list)->head = prev;
    (*list)->tail = temp;
}

int size(SinglyLinkedList **list) { return (*list)->size; }

_Bool empty(SinglyLinkedList **list) { return (*list)->size == 0; }

void init(SinglyLinkedList **list) {
    *list = (SinglyLinkedList *)malloc(sizeof(SinglyLinkedList));
    (*list)->head = NULL;
    (*list)->tail = NULL;
    (*list)->size = 0;
}

void destroy(SinglyLinkedList **list) {
    printf("[[ destroying the list ]]\n");
    while ((*list)->head) {
        Node *temp = (*list)->head;
        (*list)->head = (*list)->head->next;
        free(temp);
    }
    free((*list)->head);
    (*list)->size = 0;
    (*list)->head = (*list)->tail = NULL;
    free(*list);
    *list = NULL;
}

void print(SinglyLinkedList **list) {
    Node *curr = (*list)->head;

    for (int i = 0; i < (*list)->size; ++i) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("   -- size(%d)   front(%d)    back(%d)\n", size(list), front(list),
           back(list));
}
