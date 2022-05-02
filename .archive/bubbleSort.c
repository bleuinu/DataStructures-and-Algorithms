#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *arr, const int SIZE) {
	_Bool swapped = 0;

	for(int i=0; i<SIZE; ++i) {
		for(int j=0; j<SIZE-1; ++j) {
			if(arr[j] > arr[j+1]) {
				swapped = 1;
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}

		if(!swapped) break;
	}
}
void optimizedBubbleSort(int *arr, const int SIZE) {
	_Bool swapped = 0;

	for(int i=0; i<SIZE; ++i) {
		for(int j=0; j<SIZE-i-1; ++j) {
			if(arr[j] > arr[j+1]) {
				swapped = 1;
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}

		if(!swapped) break;
	}
}

int main(void) {
	int n;
	int *arr;

	scanf("%d", &n);
	arr = (int *)malloc(sizeof(int) * n);

	for(int i=0; i<n; ++i) {
		scanf("%d", &arr[i]);
	}

//	optimizedBubbleSort(arr, n);
	bubbleSort(arr, n);

	for(int i=0; i<n; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	free(arr);

	return 0;
}
