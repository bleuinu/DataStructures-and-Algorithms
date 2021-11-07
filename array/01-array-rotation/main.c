#include <stdio.h>
#include <stdlib.h>

/* Write a function rightRotate(arr[], D, N)
 * that rightRotates arr[] of size N by D elements */
void rightRotate(int *arr, int D, const int N) {
  int *tempArr = malloc(sizeof(int) * N);
  D = D & N;

  for(int i=0; i<N; ++i) {
    tempArr[(i+D)%N] = arr[i];
  }

  for(int i=0; i<N; ++i) {
    printf("%d ", tempArr[i]);
  }

  free(tempArr);
}

/* original array is modified */
void leftRotate(int *arr, int D, const int N) {
  D = D & N;

  // Copy first D elements
  int *tempArr = malloc(sizeof(int) * D);
  for(int i=0; i<D; ++i) {
    tempArr[i] = arr[i];
  }

  // shift everything to the left
  for(int i=0; i<N-D; ++i) {
    arr[i] = arr[D+i];
  }

  // move temp saved values to the array
  for(int i=0; i<D; ++i) {
    arr[N-D+i] = tempArr[i];
  }

  for(int i=0; i<N; ++i) {
    printf("%d ", arr[i]);
  }

  free(tempArr);
}

int main(void) {
  int arr[] = {1,2,3,4,5,6,7};
  printf("Right rotation:\n");
  for(int i=0; i<15; ++i) {
    rightRotate(arr, i, 7);
    printf("\n");
  }

  printf("\nLeft rotation:\n");
  leftRotate(arr, 2, 7);
  return 0;
}
