#include "maxheap.h"

int main(void)
{
	MaxHeap heap;
	heap.heap_size = 0;

	insert(&heap, 9);
	insert(&heap, 7);
	insert(&heap, 6);
	insert(&heap, 5);
	insert(&heap, 4);
	insert(&heap, 3);
	insert(&heap, 2);
	insert(&heap, 2);
	insert(&heap, 1);
	insert(&heap, 3);

	while(!IS_HEAP_EMTPY(heap.heap_size))
	{
		printf("%d\n", delete(&heap));
	}

	return 0;
}
