#include "sll.hpp"

using std::cin;

int main()
{
  SinglyLinkedList<int> sll;
  int choice;

  while(true)
  {
    cout << "=================================================" << endl;
    cout << "1. push_front    2. push_back     3. push_at" << endl;
    cout << "4. pop_front     5. pop_back      6. pop_at" << endl;
    cout << "7. traverse      8. peek_front    9. peek_last" << endl;
    cout << "0. exit" << endl;
    cout << "> ";
    cin >> choice;
    cout << "=================================================" << endl;

    int data, index;
    switch(choice)
    {
      case 1: 
        cout << "Enter the data to insert: ";
        cin >> data;
        sll.push_front(data);
        break;
      case 2:
        cout << "Enter the data to insert: ";
        cin >> data;
        sll.push_back(data);
        break;
      case 3: 
        cout << "enter the index and data: ";
        cin >> index >> data;
        sll.push_at(index, data);
        break;
      case 4: 
        sll.pop_front(); 
        break;
      case 5: 
        sll.pop_back(); 
        break;
      case 6: 
        cout << "Pop the element located at: ";
        cin >> index;
        sll.pop_at(index); 
        break;
      case 7:
        sll.traverse();
        break;
      case 8:
        cout << "front: " << sll.peek_first() << endl;
        break;
      case 9:
        cout << "back: " << sll.peek_last() << endl;
        break;
      case 0:
        // fallthrough
      default:
        cout << "Exit" << endl;
        goto Loop;
    }
  }
Loop:
  return 0;
}
