#include "sll.hpp"

int main()
{
  SinglyLinkedList<int> sll(2);
  for (int i=2; i<=10; ++i)
  {
    sll.push_front(2*i);
    cout << "first( " << sll.peek_first() << ")   \
      last( " << sll.peek_last() << ")\t";
    sll.traverse();
  }

  for (int i=1; i<=10; ++i)
  {
    sll.push_back(i*2+1);
    cout << "first( " << sll.peek_first() << ")   \
      last( " << sll.peek_last() << ")\t";
    sll.traverse();
  }

  for (int i=0; i<10; ++i)
  {
    sll.pop_back();
    sll.pop_front();
    cout << "first( " << sll.peek_first() << ")   \
      last( " << sll.peek_last() << ")\t";
    sll.traverse();
  }

  return 0;
}
