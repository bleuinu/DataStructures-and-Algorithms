#pragma once

#include "node.h"

typedef struct DoublyLinkedList {
	ListNode *dummy_head;
	ListNode *dummy_tail;
	int size;
} DLL;

DLL* init(void);
void _free(DLL **);

int size(DLL *);
_Bool empty(DLL *);
int value_at(DLL *, int);
int front(DLL *);
int back(DLL *);

void push_front(DLL *, int);
int pop_front(DLL *);
void push_back(DLL *, int);
int pop_back(DLL *);

void insert(DLL *, int, int);
void erase(DLL *, int);
_Bool remove_value(DLL *, int);

void reverse(DLL *);

void print(DLL *);
void print_from_n(DLL *, int);
