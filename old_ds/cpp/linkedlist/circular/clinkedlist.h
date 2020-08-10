#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef int elem;

typedef struct node_t
{
	struct node_t *next;
	elem data;
} Node;

typedef struct clinkedlist_t
{
	Node *head;
	Node *tail;
	size_t size;
} CLinkedList;

// public methods
CLinkedList* initializeList(void);
void pushFront(CLinkedList *list, elem data);
void pushBack(CLinkedList *list, elem data);
void popFront(CLinkedList *list);
void popBack(CLinkedList *list);
void insertAt(CLinkedList *list, int pos, elem data);
void removeAt(CLinkedList *list, int pos);
void destroy(CLinkedList *list);
void print(CLinkedList *list);

// private methods
static Node* createNode(elem data);
