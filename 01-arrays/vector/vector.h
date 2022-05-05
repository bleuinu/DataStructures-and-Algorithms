#pragma once 

typedef struct vector {
	int *arr;
	int size;
	int capacity;
} vector;

static void resize(vector *, int);

void init(vector **);
void _free(vector **);

inline int size(vector *);
inline int capacity(vector *);
_Bool is_empty(vector *);
void print(vector *);

int find(vector *, int);
int at(vector *, int);
void remove_all(vector *, int);

void push(vector *, int);
void insert(vector *, int, int);
void prepend(vector *, int);

int pop(vector *);
int delete_at(vector *, int);
