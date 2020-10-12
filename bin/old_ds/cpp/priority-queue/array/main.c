#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "pqueue.h"

int main(void)
{
	unsigned seed = time(0);
	srand(seed);

	PriorityQueue mypq;
	const size_t SIZE = 10;
	Init(&mypq, SIZE);

	printf("        INSERT\n");
	for(int i=0; i<10; ++i)
	{
		int data = rand() % 100 + 1;
		int priority = data;

		Insert(&mypq, data, priority);
		Print(&mypq);

		printf("max: %d\n\n", GetHighestPriority(&mypq));
	}

	printf("       DELETE\n");
	while(!IsEmpty(&mypq))
	{
		Print(&mypq);
		printf("pop: %d\n\n", GetHighestPriority(&mypq));
		DeleteHighestPriority(&mypq);
	}

	Print(&mypq);
	DeallocMemory(&mypq);

	return 0;
}
