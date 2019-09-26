/******************************************************************************
 *                                   pqueue.c
 ******************************************************************************
 * Priority Queue array implementation file
 *
 * By: Jii Myoi
 * @ : Geisel
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "pqueue.h"

void Insert(PriorityQueue *pq, int data, int priority)
{
	if(pq->size == pq->capacity)
	{
		printf("queue is full ...\n");
		return;
	}

	size_t index = pq->size;
	pq->pqueue[index].data = data;
	pq->pqueue[index].priority = priority;
	pq->size++;
}

int GetHighestPriority(PriorityQueue const * const pq)
{
	int data = pq->pqueue[0].data;

	// find the data with highest priority
	for(size_t index = 1; index < pq->size; ++index)
	{
		int temp = pq->pqueue[index].data;

		if(data < temp)
		{
			data = temp;
		}
	}

	return data;
}

void DeleteHighestPriority(PriorityQueue *pq)
{
	if(pq->size == 0)
	{
		printf("queue is empty...\n");
		return;
	}

	int maxIndex = 0;
	int data = pq->pqueue[0].data;

	// find the data with highest priority
	for(size_t index = 1; index < pq->size; ++index)
	{
		int temp = pq->pqueue[index].data;
		if(data < temp)
		{
			data = temp;
			maxIndex = index;
		}
	}

	// Shift every data (from where the highest priority data is)
	// one place to the left
	for(size_t index = maxIndex; index < pq->size-1; ++index)
	{
		pq->pqueue[index] = pq->pqueue[index+1];
	}

	pq->size--;
}

void Init(PriorityQueue *pq, const size_t CAPACITY)
{
	pq->capacity = CAPACITY;
	pq->size = 0;
	pq->pqueue = malloc(sizeof(Node) * CAPACITY);
	return;
}

void Print(PriorityQueue * const pq)
{
	if(pq->size == 0)
	{
		printf("queue is empty...\n");
		return;
	}

	const size_t size = pq->size;

	for(size_t index = 0; index < size; ++index)
	{
		printf("%d ", pq->pqueue[index].data);
	}

	printf("\n");
}

_Bool IsEmpty(PriorityQueue const * const pq)
{
	return pq->size == 0;
}

void DeallocMemory(PriorityQueue *pq)
{
	free(pq->pqueue);
}
