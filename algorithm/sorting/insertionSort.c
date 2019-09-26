#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

/*
	best = avg = worst = O(n^2)
 */
void insertionSort(int arr[])
{
	for(int i=1; i<SIZE; ++i)
	{
		int index = i;
		int key = arr[index];

		while(index > 0 && key < arr[index-1])
		{
			arr[index] = arr[index-1];
			--index;
		}

		arr[index] = key;
	}
}

void print(int arr[])
{
	for(int i=0; i<SIZE; ++i)
	{
		printf("%d ", arr[i]);

		if((i+1)%15==0)
		{
			printf("\n");
		}
	}

	printf("\n");
}

int main(void)
{	
	int arr[SIZE];
	int select;

	unsigned seed = time(0);
	srand(seed);

	for(size_t i=0; i<SIZE; ++i)
	{
		arr[i] = rand() % SIZE;
	}

	printf("Before Sorting:\n");
	print(arr);

	insertionSort(arr);

	printf("\nAfter Sorting\n");
	print(arr);

	return 0;
}
