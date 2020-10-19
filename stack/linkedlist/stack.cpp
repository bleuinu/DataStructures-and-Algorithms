#include <iostream> 
using namespace std;

#include "stack.hpp"

int main() 
{
  Stack stack;

  cout << "=========== PUSH ===========" << endl; 
  stack.push(1);
  stack.print();
  cout << "TOP: " << stack.top() << endl;

  stack.push(4);
  stack.print();
  cout << "TOP: " << stack.top() << endl;

  stack.push(16);
  stack.print();
  cout << "TOP: " << stack.top() << endl;

  stack.push(9);
  stack.print();
  cout << "TOP: " << stack.top() << endl;

  stack.push(25);
  stack.print();
  cout << "TOP: " << stack.top() << endl;

  cout << "=========== POP ===========" << endl; 
  while(!stack.empty())
  {
    cout << "POP: " << stack.top() << endl;
    stack.pop();
  }
  return 0;
}
