#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int partition(vector<int> &arr, int low, int high)
{
  int pivot = arr[high];
  int i = low - 1; 
  for (int j = low; j <= high; ++j)
  {
    if (arr[j] < pivot)
    {
        ++i;
        swap(arr[i], arr[j]);
    }
  }

  swap(arr[i+1], arr[high]);
  return i+1;
}

void quicksort(vector<int> &arr, int low, int high)
{
  if (low >= high) return;

  int pi = partition(arr, low, high);

  quicksort(arr, low, pi - 1); // before pi 
  quicksort(arr, pi + 1, high); // After pi 
}

int main()
{
  unsigned seed = time(0);
  srand(seed);

  const int SIZE = 10;
  vector<int> arr(SIZE);
  
  for (int i=0; i<SIZE; ++i)
    arr[i] = rand()%100;

  quicksort(arr, 0, SIZE-1);

  for(int x : arr) cout << x << endl;
}
