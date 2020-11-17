#include <iostream>

using namespace std;

#include "dll.hpp"

int main()
{
  DoublyLinkedList<int> cll(1);
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

  cout << "insert 222 at index 20" << endl;
  cll.insert_at(20, 222);
  cll.print();
  cout << "insert 555 at index -5" << endl;
  cll.insert_at(-5, 555);
  cll.print();
  cout << "insert 12345 at index 3" << endl;
  cll.insert_at(3, 12345);
  cll.print();
  cout << "insert 7777 at index 7 " << endl;
  cll.insert_at(7, 7777);
  cll.print();

  cout << endl;
  for(int i=0; i<7; ++i) 
  {
    cll.remove_at(i);
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
