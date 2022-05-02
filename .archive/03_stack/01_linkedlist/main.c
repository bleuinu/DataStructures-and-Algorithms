#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

static Node* node_alloc(int);

typedef struct {
  Node *top;
} Stack;

void push(Stack *, int);
int pop(Stack *);
int top(Stack *);
_Bool empty(Stack *);
void print(Stack *);

int main(void) {
  Stack stack = {
    .top = NULL
  };

  push(&stack, 10);
  push(&stack, 20);
  push(&stack, 30);

  pop(&stack);

  top(&stack);

  print(&stack);

  return 0;
}

static Node* node_alloc(int value) {
  Node *new_node = (Node *)(malloc(sizeof(Node *)));
  new_node->data = value;
  return new_node;
}

void push(Stack *stack, int value) {
  printf("[[ %d pushed into stack ]]\n", value);
  if(empty(stack)) {
    stack->top = node_alloc(value);
  } else {
    Node *new_node = node_alloc(value);
    new_node->next = stack->top;
    stack->top = new_node;
  }
}

int pop(Stack *stack) {
  if(empty(stack)) {
    printf("[[ pop - stack is empty ]]\n");
    return -1;
  }

  Node *temp = stack->top;
  int data = temp->data;
  printf("[[ %d popped from stack ]]\n", data);

  if(temp->next == NULL) {
    free(temp);
    stack->top = NULL;
  } else {
    stack->top = temp->next;
    free(temp);
  }

  return data;
}

int top(Stack *stack) {
  if(empty(stack)) {
    return -1;
  }

  printf("[[ top element is %d ]]\n", stack->top->data);
  return stack->top->data;
}

_Bool empty(Stack *stack) {
  return stack->top == NULL;
}

void print(Stack *stack) {
  Node *curr = stack->top;
  while(curr != NULL) {
    printf("%d ", curr->data);
    curr = curr->next;
  }
  printf("\n");
}
