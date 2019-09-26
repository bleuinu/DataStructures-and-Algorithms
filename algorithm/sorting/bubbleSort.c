#include <stdio.h>

#define SIZE 100000

/*
	best = avg = worst = O(n^2)
 */
void bubbleSort(int arr[])
{
	for(int i=0; i<SIZE; ++i)
	{
		for(int j=0; j<SIZE-(i+1); ++j)
		{
			if(arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

/*
	best = O(n)
	avg = worst = O(n^2)
 */
void optimizedBubbleSort(int arr[])
{
	for(int i=0; i<SIZE; ++i)
	{
		_Bool isSwapped = 0;
		
		for(int j=0; j<SIZE-i-1; ++j)
		{
			if(arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;

				isSwapped = 1;
			}
		}

		if(isSwapped == 0)
		{
			break;
		}
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

	for(size_t i=0; i<SIZE; ++i)
	{
		arr[i] = i;
	}

	printf("1. bubble sort\n");
	printf("2. optimized bubble sort\n> ");
	scanf("%d", &select);

	if(select == 1)
	{
		bubbleSort(arr);
	}
	else
	{
		optimizedBubbleSort(arr);
	}

	print(arr);

	return 0;
}
