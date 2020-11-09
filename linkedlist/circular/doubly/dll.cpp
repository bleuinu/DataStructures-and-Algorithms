#include <iostream>

using namespace std;

#include "dll.hpp"

int main()
{
  CircularDoublyLinkedList<int> cll(1);
  cll.print();

  for (int i=2; i<6; ++i)
  {
    cll.insert_back(i);
    cll.print();
  }

  for (int i=0; i>-4; --i)
  {
    cll.insert_front(i);
    cll.print();
  }

  cll.insert_at(20, 222);
  cll.print();
  cll.insert_at(-5, 555);
  cll.print();
  cll.insert_at(3, 12345);
  cll.print();
  cll.insert_at(7, 7777);
  cll.print();

  cout << endl;
  for(int i=0; i<7; ++i) 
  {
    cll.remove_at(1);
    cll.print();
  }

  cll.insert_front(5);
  cll.print();

  cll.remove_front();
  cll.print();
  cll.remove_front();
  cll.print();

  cll.remove_back();
  cll.print();
  cll.remove_back();
  cll.print();
  return 0;
}
