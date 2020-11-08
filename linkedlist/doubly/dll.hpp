#pragma once

#include <iostream>

using std::cout;
using std::endl;
using std::cerr;

template <class T>
class Node 
{ 
  private:
  public:
    Node<T>(T val) : prev(nullptr), next(nullptr) { data = val; }
    Node<T> *prev;
    Node<T> *next;
    T data;
};

template <class T>
class DoublyLinkedList 
{
  private: 
    Node<T> *head;
    Node<T> *last;
    int capacity;

  public: 
    DoublyLinkedList(int val);
    ~DoublyLinkedList();

    void insert_back(int val);
    void insert_front(int val);
    void insert_at(int index, int val);

    void remove_back();
    void remove_front();
    void remove_at(int index);

    void link(Node<T> *a, Node<T> *b);
    void print();
};

  template <class T>
DoublyLinkedList<T>::DoublyLinkedList(int val)
{
  head = new Node(val);
  last = head;

  head->next = head->prev = head;
  last = nullptr;
  capacity = 1;
}

  template <class T> 
DoublyLinkedList<T>::~DoublyLinkedList() 
{
  while(capacity--)
  {
    Node<T> *temp = head;
    delete temp;
    head = head->next;
  }
}

  template <class T>
void DoublyLinkedList<T>::link(Node<T> *curr, Node<T> *newNode)
{
  newNode->next = curr->next;
  curr->next->prev = newNode;
  curr->next = newNode;
  newNode->prev = curr;
}

  template <class T>
void DoublyLinkedList<T>::insert_back(int val) 
{
  if (capacity == 0) 
  {
    head = new Node<T>(val);
    head->next = head->prev = head;
    last = nullptr;
    capacity = 1;
    return;
  }

  Node<T> *newNode = new Node(val);
  if (last == nullptr) 
  {
    last = newNode;
    link(head, last);
  } else {
    link(last, newNode);
    last = last->next;
  }

  ++capacity;
}

  template <class T>
void DoublyLinkedList<T>::insert_front(int val) 
{
  if (capacity == 0) 
  {
    insert_back(val);
    return;
  }

  Node<T> *newNode = new Node(val);
  //  link(head, newNode);
  head->prev->next = newNode;
  newNode->next = head;
  newNode->prev = head->prev;
  head->prev = newNode;
  head = newNode;

  ++capacity;
}

  template <class T>
void DoublyLinkedList<T>::insert_at(int index, int val) 
{
  if (index <= 0) insert_front(val);
  else if (index >= capacity) insert_back(val);
  else 
  {
    Node<T> *temp = last;
    for (int i=0; i<index; ++i) 
    {
      temp = temp->next;
    }

    Node<T> *newNode = new Node(val);
    link(temp, newNode);

    ++capacity;
  }
}

  template <class T>
void DoublyLinkedList<T>::remove_front()
{
  if (capacity == 0) 
  {
    cerr << "List is empty..." << endl;
    return;
  }
  if (capacity == 1)
  {
    if (head) delete head;
    if (last) delete last;
    capacity = 0;
    return;
  }

  head->next->prev = head->prev;
  head->prev->next = head->next;

  delete head;
  --capacity;
}

  template <class T>
void DoublyLinkedList<T>::remove_back()
{
  if (capacity == 0) 
  {
    cerr << "List is empty..." << endl;
    return;
  }
  if (capacity == 1)
  {
    delete head;
    head = last = nullptr;
    capacity = 0;
    return;
  }

  Node<T> *temp = last->prev;
  last->prev->next = last->next;
  last->next->prev = last->prev;
  delete last;
  last = temp;

  --capacity;
}

  template <class T>
void DoublyLinkedList<T>::remove_at(int index)
{
  if (capacity == 0) 
  {
    cerr << "List is empty..." << endl;
    return;
  }

  if (index <= 0) 
    remove_front();
  else if (index >= capacity) 
    remove_back();
  else 
  {
    // 555 222   delete 222
    Node<T> *temp = head;
    for(int i=0; i<index; ++i) temp = temp->next;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    temp = nullptr;

    --capacity;
  }
}

  template <class T> 
void DoublyLinkedList<T>::print()
{
  if (capacity == 0) 
  {
    cerr << "List is empty" << endl;
    return;
  }
  if (capacity == 1) 
  {
    cout << head->data << endl;
    return;
  }
  Node<T> *temp = head;
  while(temp->next != head)
  {
    cout << temp->data << ' ';
    temp = temp->next;
  }
  cout << temp->data << endl;
}
