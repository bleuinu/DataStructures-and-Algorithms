#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef int elem;

typedef struct node_t
{
	struct node_t *next;
	elem data;
} Node;

typedef struct slinkedlist_t
{
	// Sentinel nodes
	Node *dummy_head;
	Node *dummy_tail;
	size_t size;
} SLinkedList;

// public methods
SLinkedList* initializeList(void);
void pushFront(SLinkedList *list, elem data);
void pushBack(SLinkedList *list, elem data);
void popFront(SLinkedList *list);
void popBack(SLinkedList *list);
void insertAt(SLinkedList *list, int pos, elem data);
void removeAt(SLinkedList *list, int pos);
void destroy(SLinkedList *list);
void print(SLinkedList *list);

// private methods
static Node* createNode(elem data);
static inline void connectLink(Node *curr, Node *after);

