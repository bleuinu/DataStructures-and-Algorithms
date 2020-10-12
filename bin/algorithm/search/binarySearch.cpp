#include <iostream>

using namespace std;

int binarySearch(int *arr, const int SIZE, int target)
{
  int low = 0;
  int high = SIZE;

  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (target == arr[mid])
    {
      return mid;
    }
    else if (target < arr[mid])
    {
      high = mid - 1;  
    } 
    else 
    {
      low = mid + 1;
    }
  }

  return -1;
}

int main()
{
  int arr[] = {3, 20, 36, 40, 50, 60, 70,110, 130, 170};
  const int SIZE = sizeof(arr) / sizeof(int);
  for (int i=0; i<SIZE; ++i)
    cout << arr[i] << ' ';
  cout << endl;

  printf("search for? x = ");
  int x;
  cin >> x;
  int index = binarySearch(arr, SIZE, x);
  
  if (index >= 0)
  {
    cout << "Element " << x << " is present at index " << index << endl; 
  }
  else 
  {
    cout << "Element " << x << " is not present in the array." << endl;
  }

  return 0;
}
