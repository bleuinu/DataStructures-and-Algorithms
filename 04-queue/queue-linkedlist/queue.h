#pragma once

#include "node.h"

typedef struct Queue {
	Node *front;
	Node *back;
	int size;
} Queue;

Queue* init(void);
void _free(Queue **);
void print(Queue *);

void enqueue(Queue *, int);
void dequeue(Queue *);
int front(Queue *);
_Bool empty(Queue *);
