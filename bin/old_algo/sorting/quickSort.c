#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(x,y) do {typeof(x) SWAP = x; x = y; y = SWAP;} while (0)

#define SIZE 300

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int index = low-1;

	for(int j = low; j < high; ++j)
	{
		if(arr[j] <= pivot)
		{
			++index;
			SWAP(arr[index], arr[j]);
		}
	}

	SWAP(arr[index+1], arr[high]);

	return index+1;
}

void quickSort(int arr[], int low, int high)
{
	if(low < high)
	{
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi-1);
		quickSort(arr, pi+1, high);
	}
}

void print(int arr[])
{
	for(int i=0; i<SIZE; ++i)
	{
		printf("%3d ", arr[i]);

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

	quickSort(arr, 0, SIZE-1);

	printf("\nAfter Sorting\n");
	print(arr);

	return 0;
}
