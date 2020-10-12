/********************************************************************
 *                              queue.h
 ********************************************************************
 * Implementation file for the array based queue
 * 
 * By  : Jii Myoi
 * Date: 2018-12-10 14:49
 * @   : Geisel 4F
 *******************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "queue.h"

void init(Queue *q)
{
	q->queue = malloc(sizeof(*(q->queue)) * 10);
	q->capacity = 10;
	q->size = 0;
}

void enqueue(Queue *q, elem data)
{
	if(q->size >= q->capacity)
	{
		printf("Queue is full\n");
		return;
	}

	q->queue[q->size] = data;
	++(q->size);
}

void dequeue(Queue *q)
{
	if(q->size < 1)
	{
		printf("Queue is empty\n");
		return;
	}

	--(q->size);
}

elem front(const Queue * const q)
{
	if(q->size <= 0)
	{
		return -1;
	}

	return (q->queue)[0];
}

elem rear(const Queue * const q)
{
	if(q->size <= 0)
	{
		return -1;
	}
	return (q->queue)[q->size-1];
}

void destroy(Queue *q)
{
	q->size = 0;
	free(q->queue);
}

void display(const Queue * const q)
{
	int size = q->size;

	for(int i=0; i<size-1; ++i)
	{
		printf("%d -> ", (q->queue)[i]);
	}

	printf("%d\n", (q->queue)[size-1]);
}
