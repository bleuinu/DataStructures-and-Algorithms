#include "minheap.h"

int main(void)
{
	MinHeap heap;
	heap.heap_size = 0;

	insertMin(&heap, 1);
	insertMin(&heap, 4);
	insertMin(&heap, 2);
	insertMin(&heap, 7);
	insertMin(&heap, 5);
	insertMin(&heap, 3);
	insertMin(&heap, 3);
	insertMin(&heap, 7);
	insertMin(&heap, 8);
	insertMin(&heap, 9);

	while(!HEAP_EMPTY(heap.heap_size))
	{
		printf("%d\n", deleteMin(&heap));
	}

	return 0;
}
