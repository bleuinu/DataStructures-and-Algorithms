/****************************
 * Date: Feb 2, 2019
 * At  : Copa Vida
 **************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "pqueue.h"

int main(void)
{
	unsigned seed = time(0);
	srand(seed);

	PQueue *pq = NewPriorityQueue();

	for(int i=0; i<5; ++i)
	{
		int data = rand() % 100;
		int priority = data;
		Push(pq, data, priority);

		Print(pq);
		printf("highest:%d   smallest:%d  size: %d\n\n", GetHighestPriority(pq), GetSmallestPriority(pq), GetSize(pq));
	}

	for(int i=0; i<3; ++i)
	{
		Print(pq);
		//		DeleteNthNode(pq, 1);
		Pop(pq);
		Print(pq);
		printf("size: %d\n\n", GetSize(pq));
	}

	DeleteNthNode(pq, 5);

	for(int i=0; i<3; ++i)
	{
		int data = rand() % 100;
		int priority = data;
		Push(pq, data, priority);

		Print(pq);
		printf("highest:%d   smallest:%d  size: %d\n\n", GetHighestPriority(pq), GetSmallestPriority(pq), GetSize(pq));
	}

	DestroyList(pq);

	return 0;
}
