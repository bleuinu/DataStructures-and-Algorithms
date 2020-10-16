#include <iostream>
#include <cstdlib> 
#include <ctime>

using namespace std;

#include "stackqueue.hpp"

int main()
{
  StackQueue<int> squeue(SIZE);
  unsigned seed = time(0);
  srand(seed);

  for(int i=0; i<SIZE; ++i) 
  {
    int temp = rand() % 100;
    cout << "enqueue: " << temp << endl;
    squeue.enqueue(temp);
  }

  while(!squeue.empty())
  {
    cout << squeue.peek() << ' ';
    squeue.dequeue();
  }
  cout << endl;

    cout << squeue.peek() << endl;
    squeue.dequeue();

  cout << endl;

  return 0;
}
