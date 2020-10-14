#include <iostream>  
#include <cstdlib> 
#include <ctime> 

using namespace std;

#include "deque.hpp"

#define SIZE 10

int main() 
{
  unsigned seed = time(0);
  srand(seed);

  Deque<int> deque(10);

  cout << "PUSH_BACK & FRONT 5 times" << endl;
  for(int i=0; i<5; ++i) 
  {
    deque.push_back(i+1);
    deque.print();
    deque.push_front(i+1);
    deque.print();
  }

  cout << "POP_FRONT & BACK while it's not empty" << endl;
  while(!deque.empty()) 
  {
    cout << "front: " << deque.front() << ' ' << "back: " << deque.back() << endl;
    deque.pop_front();
    deque.pop_back();
  }
  cout << "POP_FRONT & BACK" << endl;
  deque.pop_front();
  deque.pop_back();

  cout << "PUSH_BACK 6 times" << endl;
  for(int i=0; i<6; ++i) 
  {
    deque.push_back(i+1);
    deque.print();
  }

  cout << "PUSH_FRONT 6 times" << endl;
  for(int i=0; i<6; ++i) 
  {
    deque.push_front(i+1);
    deque.print();
  }

  cout << endl;
  return 0;
}
