#pragma once

/******************************************************************************
 *                                   pqueue.h
 ******************************************************************************
 * Priority Queue array Specification file
 *
 * By: Jii Myoi
 * @ : Geisel
******************************************************************************/

typedef struct Node
{
	int data;
	int priority;
} Node;

typedef struct PriorityQueue
{
	int capacity;
	int size;
	Node *pqueue;
} PriorityQueue;

/********************************************************************
* Inserts data to the container
*
* precondition : container exists
* postcondition: container contains new data
 *******************************************************************/
void Insert(PriorityQueue *, int, int);

/********************************************************************
* Returns data with the highest priority
*
* precondition : container exists
* postcondition: a data with highest priority is returned
 *******************************************************************/
int GetHighestPriority(PriorityQueue const * const);

/********************************************************************
* Removes data with the highest priority
*
* precondition : container exists
* postcondition: a data with highest priority is removed
 *******************************************************************/
void DeleteHighestPriority(PriorityQueue *);

/********************************************************************
* Create a container
*
* precondition : none
* postcondition: new memory is allocated for the container
 *******************************************************************/
void Init(PriorityQueue *, const size_t);

/********************************************************************
* Prints every data in the container
*
* precondition : container exists
* postcondition: every data in the container is printed to the screen
 *******************************************************************/
void Print(PriorityQueue * const);

/********************************************************************
* Check whether the underlying container is empty or not
*
* precondition : container exists
* postcondition: return true if the container is empty, else false
 *******************************************************************/
_Bool IsEmpty(PriorityQueue const * const);

/********************************************************************
* Inserts data to the container
*
* precondition : container exists
* postcondition: container destroyed and memory is deallocated
 *******************************************************************/
void DeallocMemory(PriorityQueue *);
