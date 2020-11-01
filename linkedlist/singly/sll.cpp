#include "sll.hpp"

int main()
{
  SinglyLinkedList<int> sll;
  for (int i=1; i<=10; ++i)
  {
    sll.push_front(2*i);
    sll.traverse();
  }

  for (int i=1; i<=10; ++i)
  {
    sll.push_back(i*2+1);
    sll.traverse();
  }

  return 0;
}
