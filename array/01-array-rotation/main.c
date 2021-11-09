#include <stdio.h>
#include <stdlib.h>

/*
 * Time complexity O(N*d) 
 * Auxiliary Space O(1) 
 * */

// Right rotate helper
void rightRotateByOne(int *arr, const int N) {
  int temp = arr[N-1];
  for(int i=N-1; i>0; --i) 
    arr[i] = arr[i-1];
  arr[0] = temp;
}

void rightRotate(int *arr, int d, const int N) {
  for(int i=0; i<d; ++i)
    rightRotateByOne(arr, N);
}

// Left rotate helper 
void leftRotateByOne(int *arr, const int N) {
  int temp = arr[0];
  for(int i=0; i<N-1; ++i)
    arr[i] = arr[i+1];
  arr[N-1] = temp;
}

void leftRotate(int *arr, int d, const int N) {
  for(int i=0; i<d; ++i)
    leftRotateByOne(arr, N);
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
    rightRotate(arr, 1, SIZE);
    printArr(arr, SIZE);
  }

  printf("Left Rotation\n");
  for(int i=0; i<SIZE; ++i) {
    printf("Left rotate %d ----> ", i+1);
    leftRotate(arr, 1, SIZE);
    printArr(arr, SIZE);
  }
  return 0;
}
