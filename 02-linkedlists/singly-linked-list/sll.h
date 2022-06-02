#pragma once

#include "node.h"

typedef struct SinglyLinkedList {
	ListNode *sentinel;
	int size;
} SLL;

SLL* init(void);
void _free(SLL **);

int size(SLL *);
_Bool empty(SLL *);
int value_at(SLL *, int);
int front(SLL *);
int back(SLL *);

void push_front(SLL *, int);
int pop_front(SLL *);
void push_back(SLL *, int);
int pop_back(SLL *);

void insert(SLL *, int, int);
void erase(SLL *, int);
_Bool remove_value(SLL *, int);

void reverse(SLL *);

void print(SLL *);
void print_from_n(SLL *, int);
