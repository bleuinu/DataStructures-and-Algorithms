#pragma once

#include "node.h"

typedef struct Stack {
	Node *top;
	int size;
} Stack;

Stack* init(void);
void _free(Stack **);
void print(Stack *);

void push(Stack *, int);
void pop(Stack *);
int peek(Stack *);
_Bool is_empty(Stack *);
