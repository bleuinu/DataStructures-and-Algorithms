#include <stdio.h>
#include <stdlib.h>

#define DEFAULT 8 

typedef struct {
  int *arr;
  int capacity;
  int size;
} Stack;

void push(Stack *, int);
int pop(Stack *);
int top(Stack *);
_Bool empty(Stack *);
_Bool full(Stack *);
void print(Stack *);

int main(void) {
  Stack stack = {
    .arr = (int *)(malloc(sizeof(int) * DEFAULT)),
    .capacity = DEFAULT,
    .size = 0
  };

  push(&stack, 10);
  push(&stack, 20);
  push(&stack, 30);

  pop(&stack);

  top(&stack);

  print(&stack);

  return 0;
}

void push(Stack *stack, int value) {
  if(full(stack)) {
    printf("[[ push - stack is full ]]\n");
    return;
  }

  printf("[[ %d pushed into stack ]]\n", value);
  (stack->arr)[stack->size] = value;
  ++(stack->size);
}

int pop(Stack *stack) {
  if(empty(stack)) {
    printf("[[ pop - stack is empty ]]\n");
    return -1;
  }

  int data = (stack->arr)[stack->size - 1];
  printf("[[ %d popped from stack ]]\n", data);
  --(stack->size);

  return data;
}

int top(Stack *stack) {
  if(empty(stack)) {
    printf("[[ top - stack is empty ]]\n");
    return -1;
  }

  printf("[[ top element is %d ]]\n", (stack->arr)[0]);
  return (stack->arr)[0];
}

_Bool empty(Stack *stack) {
  return stack->size == 0;
}

_Bool full(Stack *stack) {
  return stack->size == stack->capacity;
}

void print(Stack *stack) {
  for(int i=0; i<stack->size; ++i) {
    printf("%d ", (stack->arr)[i]);
  }
  printf("\n");
}
