#include <iostream>
#include <cstdlib>
#include <ctime>

#include "stack.hpp"

using namespace std;

int main()
{
  unsigned seed = time(0);
  srand(seed);

  Stack stack;

  for (int i=0; i<5; ++i)
  {
    int val = rand() % 100;
    cout << "push " << val << endl;
    stack.push(val);
  }

  cout << "Size: " << stack.getSize() << endl;
  cout << "isEmpty? " << stack.isEmpty() << endl;
  cout << "top: " << stack.top() << endl;

  while(!stack.isEmpty()) 
  {
    cout << stack.pop() << " popped" << endl;
  }

  cout << "isEmpty? " << stack.isEmpty() << endl;
  cout << "top: " << stack.top() << endl;

  return 0;
}
