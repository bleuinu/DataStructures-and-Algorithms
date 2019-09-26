#include <stdio.h>

#define MAX_ELEMENT 200 /* max heap size + 1*/
#define HEAP_FULL(n) ((n) == MAX_ELEMENT - 1)
#define HEAP_EMPTY(n) (!(n))

typedef struct
{
	int key;
} element;

typedef struct heap_t
{
	element heap[MAX_ELEMENT];
	int heap_size;
} MinHeap;

void insertMin(MinHeap *h, int item)
{
	if(HEAP_FULL(h->heap_size))
	{
		fprintf(stderr, "The heap is full.\n");
		return;
	}

	int i = ++(h->heap_size); // increment heap size by 1

	// if i != 1, (i)'s parent is located on [i/2]
	while((i != 1) && (item < h->heap[i>>1].key))
	{
		// exchange i_th node and its parent
		h->heap[i] = h->heap[i>>1];
		// go up one level
		i >>= 1;
	}
	h->heap[i].key = item; // insert new node
}

int deleteMin(MinHeap *h)
{
	int parent, child;
	int item, temp;

	if(HEAP_EMPTY(h->heap_size))
	{
		fprintf(stderr, "The heap is empty.\n");
		return -1;
	}

	// store the current max 
	item = h->heap[1].key;

	// use the last element to recreate the heap
	temp = h->heap[(h->heap_size)--].key;
	parent = 1;
	child = 2;
	while(child <= h->heap_size)
	{
		// search current parent's max child
		if((child < h->heap_size) && (h->heap[child].key) > h->heap[child+1].key)
		{
			++child;
		}
		// stop the loop if last element is greater than the max child
		if(temp <= h->heap[child].key)
		{
			break;
		}

		// step down
		h->heap[parent] = h->heap[child];
		parent = child;
		child <<= 1;
	}
	h->heap[parent].key = temp;
	return item;
}
