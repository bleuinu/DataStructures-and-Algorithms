#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15

void print(int arr[])
{
	for(int i=0; i<SIZE; ++i)
	{
		printf("%d ", arr[i]);

		if((i+1)%15==0)
			printf("\n");
	}

	printf("\n");
}

void merge(int arr[], int left, int mid, int right)
{
	int sortedArr[SIZE] = {0};
	int L = left;
	int R = mid+1;
	int K = left;

	// combine two lists
	while(L <= mid && R <= right)
	{
		if(arr[L] < arr[R])
			sortedArr[K++] = arr[L++];
		else
			sortedArr[K++] = arr[R++];
	}

	// Read all remaining data on the left
	while(L <= mid)
		sortedArr[K++] = arr[L++];
	
	// Right is already sorted; no need to copy again
	// copy over the data
	for(int i=left; i<K; ++i)
		arr[i] = sortedArr[i];
}

void mergeSort(int arr[], int left, int right)
{
	int mid;

	if(left < right)
	{
		mid = left + (right - left) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid+1, right);
		merge(arr, left, mid, right);
	}
}

int main(void)
{	
	int arr[SIZE];
	int select;

	unsigned seed = time(0);
	srand(seed);

	for(size_t i=0; i<SIZE; ++i)
		arr[i] = rand()%SIZE+1;

	printf("Before Sorting\n");
	print(arr);

	mergeSort(arr, 0, SIZE-1);

	printf("\nAfter Sorting\n");
	print(arr);

	return 0;
}
