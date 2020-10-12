#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define SIZE 10
#define BOUND 100

void merge(int *arr, int left, int mid, int right) 
{
  int *sortedArray = new int(right);
  int p = left;
  int q = mid+1;
  int k = left;

  while (p <= mid && q <= right)
  {
    if (arr[p] < arr[q]) 
    {
      sortedArray[k] = arr[p];
      ++p;
    }
    else
    {
      sortedArray[k] = arr[q];
      ++q;
    }
    ++k;
  }

  while (p <= mid)
  {
    sortedArray[k] = arr[p];
    ++p;
    ++k;
  }

  for (int i=left; i<k; ++i)
  {
    arr[i] = sortedArray[i];
  }

  delete(sortedArray);
}

void mergeSort(int *arr, int left, int right)
{
  if (left < right)
  {
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
  }
}

int main()
{
  unsigned seed = time(0);
  srand(seed);

  int arr[SIZE] = {0};
  for (int i=0; i<SIZE; ++i) 
  {
    arr[i] = rand() % BOUND;
  }

  for(int x : arr) cout << x << ' ';
  cout << endl;

  mergeSort(arr, 0, SIZE-1);

  for(int x : arr) cout << x << ' ';
  cout << endl;

  return 0;
}
