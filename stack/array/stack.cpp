#include <iostream> 
#include <cstdlib>
#include <ctime>

using namespace std;

#include "stack.hpp"

int main()
{
  unsigned seed = time(0);
  srand(seed);

  Stack<int> stack(SIZE);

  for(int i=0; i<SIZE; ++i) 
  {
    stack.push(rand() % 100;
  }

  stack.print();

  while(!stack.empty())
  {
    cout << stack.peek() << endl;
    stack.pop();
  }

  stack.pop();

  return 0;
}
