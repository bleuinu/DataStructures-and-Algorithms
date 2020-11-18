#include <iostream>

using namespace std;

int linearSearch(int const * const arr, const int target, const int SIZE)
{
  for (int i=0; i<SIZE; ++i)
  {
    if (arr[i] == target)
      return i;
  }

  return -1;
}

int main()
{
  int arr[] = {1,2,3,4,5};
  int target = 2;
  const int SIZE = sizeof(arr) / sizeof(int);

  int index = linearSearch(arr, target, SIZE);
  if (index >= 0) 
  {
    cout << "target [" << target << "] found at index [" << index << "]" << endl; 
  }
  else 
  {
    cout << "target not found" << endl;
  }

  return 0;
}
