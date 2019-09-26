#include <stdio.h>

#include "queue.h"

#define SIZE 10

int main(void)
{
	Queue myqueue;

	init(&myqueue);

	for(int i=0; i<SIZE+1; ++i)
	{
		enqueue(&myqueue, i+1);
		display(&myqueue);
	}
	
	for(int i=0; i<SIZE+2; ++i) 
	{
		printf("front: %d      rear: %d\n", front(&myqueue), rear(&myqueue));
		dequeue(&myqueue);
	}

	destroy(&myqueue);

	return 0;
}
