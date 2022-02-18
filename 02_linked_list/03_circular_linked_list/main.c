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
  Node *last;
  int size;
} CircularLinkedList;

/* Functions for inked list */
int front(CircularLinkedList **);
int back(CircularLinkedList **);
int nth_node_from_end(CircularLinkedList **, int);

void insert(CircularLinkedList **, int, int);
void push_front(CircularLinkedList **, int);
void push_back(CircularLinkedList **, int);
int pop_front(CircularLinkedList **);
int pop_back(CircularLinkedList **);
int value_at(CircularLinkedList **, int);
void erase(CircularLinkedList **, int);
void reverse(CircularLinkedList **);

int size(CircularLinkedList **);
_Bool empty(CircularLinkedList **);
void init(CircularLinkedList **);
void destroy(CircularLinkedList **);
void print(CircularLinkedList **);

int main(void) {
  unsigned seed = time(0);
  srand(seed);

  CircularLinkedList *list;
  init(&list);
  push_back(&list, 1);
  push_back(&list, 2);
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
    printf("last:%d   last->next: %d\n", list->last->data,
        list->last->next->data);
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

  reverse(&list);
  print(&list);

  while (size(&list) > 1) {
    erase(&list, 0);
    print(&list);
    if (size(&list) % 5 == 0) reverse(&list);
  }

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
int front(CircularLinkedList **list) {
  if (!empty(list)) {
    return (*list)->last->next->data;
  }

  printf("[[ front -- List is empty. ]]\n");
  return INF;
}

int back(CircularLinkedList **list) {
  if (!empty(list)) {
    return ((*list)->last)->data;
  }

  printf("[[ back -- List is empty. ]]\n");
  return INF;
}

int nth_node_from_end(CircularLinkedList **list, int index) {
  if (empty(list)) {
    printf("[[ nth_node_from_end -- list is empty ]]\n");
    return -1;
  }
  if (index > (*list)->size) {
    printf("[[ nth_node_from_end -- out of bound ]]\n");
    return -1;
  }

  int cnt = (*list)->size - index;
  Node *curr = (*list)->last->next;
  for (int i = 1; i < cnt; ++i) {
    curr = curr->next;
  }

  return curr->data;
}

void insert(CircularLinkedList **list, int index, int value) {
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
    Node *curr = (*list)->last->next;
    for (int i = 1; i < index; ++i) {
      curr = curr->next;
    }

    new_node->next = curr->next;
    curr->next = new_node;
    ++((*list)->size);
  }
}

void push_front(CircularLinkedList **list, int data) {
  if (empty(list)) {
    (*list)->last = node_alloc(data);
    (*list)->last->next = (*list)->last;
  } else {
    Node *new_node = node_alloc(data);
    new_node->next = (*list)->last->next;
    (*list)->last->next = new_node;
  }

  ++((*list)->size);
}

void push_back(CircularLinkedList **list, int data) {
  push_front(list, data);
  (*list)->last = (*list)->last->next;
}

int pop_front(CircularLinkedList **list) {
  if (empty(list)) {
    printf("[[ pop_front - List is empty... ]]");
    return -1;
  }

  if (size(list) == 1) {
    int data = (*list)->last->data;
    free((*list)->last);
    (*list)->last = NULL;
    (*list)->size = 0;
    return data;
  }

  Node *temp = (*list)->last->next;
  (*list)->last->next = temp->next;
  int data = temp->data;
  free(temp);
  --((*list)->size);

  return data;
}

int pop_back(CircularLinkedList **list) {
  if (empty(list)) {
    printf("List is empty...");
    return -1;
  }

  if (size(list) == 1) {
    int data = (*list)->last->data;
    free((*list)->last);
    (*list)->last = NULL;
    (*list)->size = 0;
    return data;
  }

  Node *curr = (*list)->last->next;
  while (curr->next != (*list)->last) {
    curr = curr->next;
  }
  int data = curr->next->data;
  free(curr->next);
  curr->next = NULL;
  (*list)->last = curr;
  --((*list)->size);

  return data;
}

int value_at(CircularLinkedList **list, int index) {
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

  Node *curr = (*list)->last->next;
  for (int i = 0; i < index; ++i) {
    curr = curr->next;
  }

  return curr->data;
}

void erase(CircularLinkedList **list, int index) {
  if ((*list)->size == 1 || index == 0) {
    pop_front(list);
    return;
  }
  if (index == (*list)->size - 1) {
    pop_back(list);
    return;
  }

  Node *curr = (*list)->last->next;
  for (int i = 1; i < index; ++i) {
    curr = curr->next;
  }

  Node *temp = curr->next->next;
  free(curr->next);
  curr->next = temp;
  --((*list)->size);
}

void reverse(CircularLinkedList **list) {
  printf("[[ reverse list ]]\n");
  Node *head = (*list)->last->next;

  Node *curr = head;
  Node *prev = NULL;
  Node *next = NULL;

  do {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  } while (curr != head);

  (*list)->last = curr;
  (*list)->last->next = prev;
}

int size(CircularLinkedList **list) { return (*list)->size; }

_Bool empty(CircularLinkedList **list) { return (*list)->size == 0; }

void init(CircularLinkedList **list) {
  *list = (CircularLinkedList *)malloc(sizeof(CircularLinkedList));
  (*list)->last = NULL;
  (*list)->size = 0;
}

void destroy(CircularLinkedList **list) {
  printf("[[ destroying the list ]]\n");
  Node *curr = (*list)->last->next;
  while (curr->next != (*list)->last) {
    Node *temp = curr;
    curr = curr->next;
    free(temp);
  }
  free((*list)->last);
  (*list)->size = 0;
  (*list)->last = NULL;
  free(*list);
  *list = NULL;
}

void print(CircularLinkedList **list) {
  Node *curr = (*list)->last->next;

  for (int i = 0; i < (*list)->size; ++i) {
    printf("%d ", curr->data);
    curr = curr->next;
  }
  printf("   -- size(%d)   front(%d)    back(%d)\n", size(list), front(list),  back(list));
}
