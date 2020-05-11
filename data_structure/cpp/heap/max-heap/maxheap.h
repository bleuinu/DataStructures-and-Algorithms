#include <stdio.h>

#define MAX_ELEMENT 200

#define IS_HEAP_EMTPY(size) (size == 0)

typedef struct heap_t
{
	int heap[MAX_ELEMENT];
	int heap_size;
} MaxHeap;

void insert(MaxHeap *h, int item)
{
	int i = (h->heap_size)++;

	while((i!=0) && (item > h->heap[(i-1)/2]))
	{
		// swap current with the parent
		h->heap[i] = h->heap[(i-1)/2];
		// go up one level
		i = (i-1)/2;
	}
	
	// insert new item
	h->heap[i] = item;
}

int delete(MaxHeap *h)
{
	int parent, child;
	int item, temp;

	// store the current max
	item = h->heap[0];

	// use the last element to recreate the heap
	temp = h->heap[(h->heap_size)--];
	parent = 0;
	child = 1;

	while(child <= h->heap_size)
	{
		// search current parent's max child
		if((h->heap[child]) < h->heap[child+1])
		{
			++child;
		}

		// stop the loop if last element is greater than the max child
		if(temp >= h->heap[child])
		{
			break;
		}

		// step down
		h->heap[parent] = h->heap[child];
		parent = child;
		child = child * 2 + 1;
	}

	h->heap[parent] = temp;
	return item;
}
