#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "stack.h"

#define SIZE 10

int main(void)
{
	unsigned seed = time(0);
	srand(seed);

	Stack stk;

	init(&stk);
	printf("is stack empty? %d\n", isEmpty(&stk));
	printf("stack size: %d\n\n", size(&stk));

	for(int i=0; i<10; ++i)
	{
		int data = rand() % 100 + 1;
		printf("Push: %d\n", data);
		push(&stk, data);
		printf("is stack empty? %d\n", isEmpty(&stk));
		printf("stack size:     %d\n", size(&stk));
		printf("top:            %d\n\n", top(&stk));
	}

	while(!isEmpty(&stk))
	{
		printf("pop: %d\n", top(&stk));
		pop(&stk);
	}

	destroy(&stk);

	return 0;
}
