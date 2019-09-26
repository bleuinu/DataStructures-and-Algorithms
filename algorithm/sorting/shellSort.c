#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 10

void shellSort(int *arr)
{
	int gap;
	for(gap = SIZE>>1; gap>0; gap>>=1)
	{
		// gap을 홀수로 만든다
		if((gap&1) == 0)
		{
			++gap;
		}

		for(size_t i=gap; i<SIZE; ++i)
		{
			int j = i;
			int key = arr[i];

			for(; j>=gap && arr[j-gap] > key; j-=gap)
			{
				arr[j] = arr[j-gap];
			}

			arr[j] = key;
		}
	}
}

int main(void)
{
	unsigned seed = time(0);
	srand(seed);

	int arr[SIZE] = {0};

	for(size_t i=0; i<SIZE; ++i)
	{
		arr[i] = rand() % (SIZE * 10);
	}

	shellSort(arr);

	for(size_t i=0; i<SIZE; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

// ref: https://en.wikipedia.org/wiki/Shellsort
// ref: https://gmlwjd9405.github.io/2018/05/08/algorithm-shell-sort.html
