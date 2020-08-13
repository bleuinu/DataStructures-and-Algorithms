#include <iostream>

using namespace std;

int linearSearch(int *arr, const int SIZE, int target)
{
  for(int i=0; i<SIZE; ++i) 
  {
    if (arr[i] == target)
      return i;
  }

  return -1;
}

int main()
{
  int arr[] = {10, 20, 80, 30, 60, 50, 110, 100, 130, 170};
  printf("search for? x = ");
  int x;
  cin >> x;

  int index = linearSearch(arr, sizeof(arr)/sizeof(int), x);

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
