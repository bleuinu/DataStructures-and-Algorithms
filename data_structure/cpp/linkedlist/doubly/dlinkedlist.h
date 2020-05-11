#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef int elem;

typedef struct node_t
{
	struct node_t *next;
	struct node_t *prev;
	elem data;
} Node;

typedef struct dlinkedlist_t
{
	// Sentinel nodes
	Node *dummy_head;
	Node *dummy_tail;
	size_t size;
} DLinkedList;

// public methods
DLinkedList* initializeList(void);
void pushFront(DLinkedList *list, elem data);
void pushBack(DLinkedList *list, elem data);
void popFront(DLinkedList *list);
void popBack(DLinkedList *list);
void insertAt(DLinkedList *list, int pos, elem data);
void removeAt(DLinkedList *list, int pos);
void destroy(DLinkedList *list);
void print(DLinkedList *list);

// private methods
static Node* createNode(elem data);
static inline void connectLink(Node *curr, Node *after);

