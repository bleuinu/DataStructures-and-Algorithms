#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

/*
	best = avg = worst = O(n^2)
 */
void selectionSort(int arr[])
{
	for(int i=0; i<SIZE-1; ++i)
	{
		int min = i;
		for(int j=i+1; j<SIZE; ++j)
		{
			if(arr[min] > arr[j])
			{
				min = j;
			}
		}

		int temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
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
		arr[i] = rand()%SIZE+1;
	}

	printf("Before Sorting\n");
	print(arr);

	selectionSort(arr);

	printf("\nAfter Sorting\n");
	print(arr);

	return 0;
}
