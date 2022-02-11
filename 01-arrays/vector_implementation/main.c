#include <stdio.h>
#include <stdlib.h>

#define INF 0x7FFFFFFF
#define TRUE 1
#define FALSE 0

#define DEFAULT_SIZE 16

typedef struct {
  int *arr;
  int capacity;
  int size;
} Vector;

// public function
void init(Vector *);
int size(Vector *);
int capacity(Vector *);
_Bool is_empty(Vector *);
void print(Vector *);

void push(Vector *, int);
int pop(Vector *);
int at(Vector *, int);

// private function
static void resize(Vector *, int);

int main(void) {
  Vector vec;

  init(&vec);
  printf("number of items: %d\n", size(&vec));
  printf("number of items it can hold: %d\n", capacity(&vec));
  printf("is it empty?: %d\n", is_empty(&vec));
  printf("size at index 0: %d\n", at(&vec, 0));
  printf("size at index 1: %d\n", at(&vec, 1));
  printf("size at index 20: %d\n\n", at(&vec, 20));

  for(int i=0; i<25; ++i) {
    push(&vec, i);
    printf("push %d\n", i);
    print(&vec);
  }

  for(int i=0; i<30; ++i) {
    printf("popped %d\n", pop(&vec));
    print(&vec);
  }

  push(&vec, 17);
  printf("push %d\n", 17);
  print(&vec);

  free(vec.arr);
  return 0;
}

void init(Vector *vec) {
  vec->capacity = DEFAULT_SIZE;
  vec->size = 0;
  vec->arr = (int *)(malloc(vec->capacity * sizeof(int)));

  for(int i=0; i<DEFAULT_SIZE; ++i) {
    (vec->arr)[i] = INF;
  }
}

int size(Vector *vec) {
  return vec->size;
}

int capacity(Vector *vec) {
  return vec->capacity;
}

_Bool is_empty(Vector *vec) {
  return vec->size == 0;
}

void print(Vector *vec) {
  for(int i=0; i<vec->size; ++i) {
    printf("%d ", (vec->arr)[i]);   
  }
  printf(" --- size / capacity (%d / %d)\n", vec->size, vec->capacity);
}

int at(Vector *vec, int idx) {
  // out of bound
  if(idx >= vec->capacity || (vec->arr)[idx] == INF) {
    printf("....can't access index %d - overflow\n", idx);
    return -1;
  }

  return (vec->arr)[idx];
}

void push(Vector *vec, int size) {
  // double the size if vector is full
  if(vec->size == vec->capacity) {
    resize(vec, vec->capacity << 1);
  }

  (vec->arr)[vec->size] = size;
  ++(vec->size);
}

int pop(Vector *vec) {
  if(is_empty(vec)) {
    printf(".... vector is empty\n");
    return -1;
  }

  // if size is 1/4 of capacity, resize to half
  int quart = vec->capacity / 4;
  if(vec->capacity > DEFAULT_SIZE && vec->size <= quart) {
    resize(vec, vec->capacity >> 1);
  }

  --(vec->size);
  int data = (vec->arr)[vec->size];
  (vec->arr)[vec->size] = INF;

  return data;
}

static void resize(Vector *vec, int capacity) {
  vec->capacity = capacity;
  int *temp = (int *)(malloc(vec->capacity * sizeof(int)));

  // copy over size
  for(int i=0; i<vec->size; ++i) {
    temp[i] = (vec->arr)[i];
  }

  free(vec->arr);

  vec->arr = temp;
}
