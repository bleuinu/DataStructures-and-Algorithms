#include <iostream>  
#include <cstdlib> 
#include <ctime> 

using namespace std;

#include "queue.hpp"

#define SIZE 10

int main() 
{
  unsigned seed = time(0);
  srand(seed);

  Queue<int> queue(10);
  for(int i=0; i<SIZE; ++i) 
  {
    queue.enqueue(rand() % 100);
  }
  queue.print();

  while(!queue.empty()) 
  {
    cout << queue.peek() << ' ';
    queue.dequeue();
  }
  cout << endl;
  return 0;
}
