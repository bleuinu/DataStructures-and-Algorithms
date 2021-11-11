#include <stdio.h>
#include <stdlib.h>

/*
 * Method: Juggling Algorithm
 * Time complexity O(N) 
 * Auxiliary Space O(1) 
 * */

int gcd(int a, int b) {
  return (b==0) ? a : gcd(b, a%b);
}

void leftRotate(int *arr, int d, const int N) {
  d = d % N;
  int _gcd = gcd(d, N);
  for(int i=0; i<_gcd; ++i) {
    // move i_th values of blocks
    int temp = arr[i];
    int j = i;
    while(1) {
      int k = j + d;
      if (k >= N) k = k - N;
      if (k == i) break;
      arr[j] = arr[k];
      j = k;
    }
    arr[j] = temp;
  }
}

void rightRotate(int *arr, int d, const int N) {
  d = d % N;
  int _gcd = gcd(d, N);
  for(int i=0; i<_gcd; ++i) {
    // move i_th values of blocks
    int temp = arr[(N-1) - i];
    int j = i;
    while(1) {
      int k = j + d;
      if (k >= N) k = k - N;
      if (k == i) break;
      arr[(N-1) - j] = arr[(N-1) - k];
      j = k;
    }
    arr[(N-1) - j] = temp;
  }
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
