#include <iostream>
#include <cstdlib> 
#include <ctime>

using namespace std;

#include "queuestack.hpp"

int main() 
{
  unsigned seed = time(0); 
  srand(seed);

  QueueStack<int> stack;

  for(int i=0; i<SIZE; ++i)
  {
    int t = rand() % 100;
    cout << "t: " << t << endl;
    stack.push(t);
  }

  while(!stack.empty())
  {
    cout << stack.top() << endl;
    stack.pop();
  }

  return 0;
}
