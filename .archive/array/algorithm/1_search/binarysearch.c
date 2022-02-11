#include <stdio.h>

/*
 * Binary Search
 * Time complexity: O(log n)
 * Auxiliary space: O(1) for iterative implementation
 * Auxiliary space: O(log n) for recursive implementation
 * */
int binarySearch(int *arr, int key, int low, int high) {
  if (high < low) return -1;

  int mid = low + (high - low) / 2;
  if (key == arr[mid]) return mid;
  if (key > arr[mid]) return binarySearch(arr, key, mid+1, high);
  return binarySearch(arr, key, low, mid-1);
}

int main(void) {
  int arr[] = {1,2,3,4,5,6,7,8,9};
  const int SIZE = sizeof(arr) / sizeof(int);

  int key = 1;
  int index = binarySearch(arr, key, 0, SIZE);
  if(index != -1) {
    printf("%d is found at index %d!\n", key, index);
  } else {
    printf("%d is not found!\n", key);
  }
  return 0;
}
