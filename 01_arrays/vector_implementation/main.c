#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INF 0x7FFFFFFF
#define TRUE 1
#define FALSE 0

#define DEFAULT_SIZE 16

typedef struct {
  int *arr;
  int capacity;
  int size;
} Vector;

// private function
static void resize(Vector *, int);

// public function
void init(Vector *);
void destroy(Vector *);

void push_back(Vector *, int);
int pop_back(Vector *);
void insert(Vector *, int, int);
int delete(Vector *, int);
void _remove(Vector *, int);
void prepend(Vector *, int);
int at(Vector *, int);
int find(Vector *, int);

int size(Vector *);
int capacity(Vector *);
_Bool is_empty(Vector *);
void print(Vector *);

int main(void) {
  unsigned seed = time(0);
  srand(seed);

  Vector vec;
  init(&vec);

  for(int i=0; i<25; ++i) {
    int data = rand() % 10;
    push_back(&vec, data);
    printf("push_back %d\n", data);
    print(&vec);
  }

  printf("is 5 in vector? index: %d\n", find(&vec, 5));
  printf("is 177 in vector? index: %d\n", find(&vec, 177));

  for(int i=0; i<5; ++i) {
    printf("popped %d\n", pop_back(&vec));
    print(&vec);
  }

  for(int i=0; i<10; ++i) {
    int index = rand() % capacity(&vec);
    int data = rand() % 10;
    printf("insert %d at index %d\n", data, index);
    insert(&vec, index, data);
    print(&vec);
  }

  printf("prepend 10\n");
  printf("push_back 11\n");
  printf("insert 12 at 2\n");
  prepend(&vec, 10);
  push_back(&vec, 11);
  insert(&vec, 2, 12);
  print(&vec);

  for(int i=0; i<5; ++i) {
    int idx = rand() % 10;
    printf("delete a value at index: %d -  %d\n", idx, delete(&vec, idx));
    print(&vec);
  }

  for(int i=0; i<5; ++i) {
    int data = rand() % 10;
    printf("remove %d\n", data);
    _remove(&vec, data);
    print(&vec);
  }

  destroy(&vec);

  return 0;
}

/******************************************************* 
 * resize - private function
 *
 * 1) Double the size if vector is full. 
 * 2) halve the size if the size is 1/4 of capacity. 
 ******************************************************/
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

void init(Vector *vec) {
  vec->capacity = DEFAULT_SIZE;
  vec->size = 0;
  vec->arr = (int *)(malloc(vec->capacity * sizeof(int)));

  for(int i=0; i<DEFAULT_SIZE; ++i) {
    (vec->arr)[i] = INF;
  }
}

void destroy(Vector *vec) {
  free(vec->arr);
  vec->arr = NULL;
  vec->size = 0;
  vec->capacity = 0;
}

void push_back(Vector *vec, int size) {
  // double the size if vector is full
  if(vec->size == vec->capacity) {
    resize(vec, vec->capacity << 1);
  }

  (vec->arr)[vec->size] = size;
  ++(vec->size);
}

int pop_back(Vector *vec) {
  if(is_empty(vec)) {
    printf(".... vector is empty\n");
    return -1;
  }

  // if size is 1/4 of capacity, halve the capacity
  int quart = vec->capacity / 4;
  if(vec->capacity > DEFAULT_SIZE && vec->size <= quart) {
    resize(vec, vec->capacity >> 1);
  }

  --(vec->size);
  int data = (vec->arr)[vec->size];
  (vec->arr)[vec->size] = INF;

  return data;
}

/******************************************************* 
 * index = zero-based (0, 1, 2, ...)
 ******************************************************/
void insert(Vector *vec, int idx, int data) {
  // double the size if vector is full
  if(vec->size == vec->capacity) {
    resize(vec, vec->capacity << 1);
  }

  if(idx == 0) {
    prepend(vec, data);
  } else if (idx >= vec->size) {
    push_back(vec, data);
  } else {
    ++(vec->size);
    for(int i=vec->size-1; i>idx; --i) {
      (vec->arr)[i] = (vec->arr)[i-1];
    }

    (vec->arr)[idx] = data;
  }
}

/******************************************************* 
 * index = zero-based (0, 1, 2, ...)
 ******************************************************/
int delete(Vector *vec, int idx) {
  if(idx >= vec->size) {
    return pop_back(vec);
  }

  int data = (vec->arr)[idx];

  for(int i=idx; i<vec->size; ++i) {
    (vec->arr)[i] = (vec->arr)[i+1];
  }

  --(vec->size);
  (vec->arr)[vec->size] = INF;
  
  return data;
}

void _remove(Vector *vec, int data) {
  if(is_empty(vec)) return;

  int p = 0;
  int *temp = (int *)(malloc(vec->capacity * sizeof(int)));
  for(int i=0; i<vec->size; ++i) {
    if((vec->arr)[i] != data) {
      temp[p] = (vec->arr)[i]; 
      ++p;
    }
  }

  vec->size = p;
  free(vec->arr);
  vec->arr = temp;

  // if size is 1/4 of capacity, halve the capacity
  int quart = vec->capacity / 4;
  if(vec->capacity > DEFAULT_SIZE && vec->size <= quart) {
    resize(vec, vec->capacity >> 1);
  }
}

void prepend(Vector *vec, int data) {
  // double the size if vector is full
  if(vec->size == vec->capacity) {
    resize(vec, vec->capacity << 1);
  }

  ++(vec->size);
  for(int i=(vec->size)-1; i>0; --i) {
    (vec->arr)[i] = (vec->arr)[i-1];
  }

  (vec->arr)[0] = data;
}

/******************************************************* 
 * index = zero-based (0, 1, 2, ...)
 ******************************************************/
int at(Vector *vec, int idx) {
  // out of bound
  if(idx >= vec->capacity || (vec->arr)[idx] == INF) {
    printf("....can't access index %d - overflow\n", idx);
    return -1;
  }

  return (vec->arr)[idx];
}

int find(Vector *vec, int data) {
  int idx = -1;

  for(int i=0; i<vec->size; ++i) {
    if((vec->arr)[i] == data) {
      idx = i;
      break;
    }
  }

  return idx;
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
    printf("%3d ", (vec->arr)[i]);   

    if((i+1)%10 == 0)  {
      printf("\n");
    }
  }
  printf("\n ---- size / capacity (%d / %d)\n\n", vec->size, vec->capacity);
}

