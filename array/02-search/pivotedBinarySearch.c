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

int findPivot(int *arr, int low, int high) {
  // base case
  if (high < low) return -1;
  if (high == low) return low;

  int mid = low + (high -low) / 2;
  if (mid < high && arr[mid] > arr[mid+1]) return mid;
  if (mid > low && arr[mid] < arr[mid-1]) return (mid-1);
  if (arr[low] >= arr[mid]) return findPivot(arr, low, mid-1);
  return findPivot(arr, mid+1, high);
}

int pivotedBinarySearch(int *arr, int n, int key) {
  int pivot = findPivot(arr, 0, n-1);

  // if we didn't find pivot, arr is not rotated
  if (pivot == -1) return binarySearch(arr, key, 0, n-1);

  // pivot exists
  // first compare with pivot and then search in 2 subarrays around pivot  
  if (arr[pivot] == key) return pivot;
  if (arr[0] <= key) return binarySearch(arr, key, 0, pivot-1);
  return binarySearch(arr, key, pivot+1, n-1);
}

int main(void) {
//  int arr[] = {1,2,3,4,5,6,7,8,9};
  int arr[] = {4,5,6,7,8,9,1,2,3};
  const int SIZE = sizeof(arr) / sizeof(int);

  int key = 1;
  int index = pivotedBinarySearch(arr, SIZE, key);
  if(index != -1) {
    printf("%d is found at index %d!\n", key, index);
  } else {
    printf("%d is not found!\n", key);
  }
  return 0;
}
