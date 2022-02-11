#include <stdio.h>
#include <stdlib.h>

/*
 * Method: 2 pointers to rotate clockwise
 * Time complexity O(N) 
 * Auxiliary Space O(1) 
 * */

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void rotate(int *arr, const int N) {
  for(int i=0, j=N-1; i!=j; ++i)
    swap(&arr[i], &arr[j]);
}

void printArr(int *arr, const int N) {
  for(int i=0; i<N; ++i) 
    printf("%d ", arr[i]);
  printf("\n");
}

int main(void) {
  int arr[] = {1,2,3,4,5,6,7};
  const int SIZE = sizeof(arr) / sizeof(int);

  printf("Right Rotation\n");
  for(int i=0; i<SIZE; ++i) {
    printf("Right rotate %d ----> ", i+1);
    rotate(arr, SIZE);
    printArr(arr, SIZE);
  }

  return 0;
}
