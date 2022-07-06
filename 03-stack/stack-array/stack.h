#pragma once

#define SIZE 16

typedef struct Stack {
	int arr[SIZE];
	int item;
	int size;
} Stack;

Stack* init(void);
void print(Stack *);

void push(Stack *, int);
void pop(Stack *);
int peek(Stack *);
_Bool is_full(Stack *);
_Bool is_empty(Stack *);
