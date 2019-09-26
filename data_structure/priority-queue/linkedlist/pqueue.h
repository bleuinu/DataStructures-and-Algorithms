#pragma once

/****************************
 * Date: Feb 2, 2019
 * At  : Copa Vida
 **************************/

#include <stdio.h>
#include <stdlib.h>

#include "pnode.h"

typedef _Bool bool;

typedef struct PriorityQueue
{
	Node *head;
	Node *tail;
	int size;
} PQueue;

/* constructor */
Node* NewNode(const Element data, const int priority);
PQueue* NewPriorityQueue(void);

/* destructor */
void DestroyList(PQueue *pq);

/* list modifier */
void Push(PQueue *pq, const Element data, const int priority);
void Pop(PQueue *pq);
void DeleteNthNode(PQueue *pq, const int n);

/* list access */
void Print(const PQueue *pq);
bool IsEmpty(const PQueue *pq);
int GetSize(const PQueue *pq);
Element GetHighestPriority(const PQueue *pq);
Element GetSmallestPriority(const PQueue *pq);

/* helper functions */
static void ConnectNode(Node *work, Node *curr);
static void Delete(PQueue *pq, Node *remove);
static void DisconnectNode(Node *curr);
