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
    Node<T>(T val) : next(nullptr) { data = val; }
    Node<T> *next;
    T data;
};

template <class T>
class CircularSinglyLinkedList 
{
  private: 
    Node<T> *last;
    int capacity;

  public: 
    CircularSinglyLinkedList(int val);
    ~CircularSinglyLinkedList();

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
CircularSinglyLinkedList<T>::CircularSinglyLinkedList(int val)
{
  last = new Node(val);
  last->next = last;
  capacity = 1;
}

  template <class T> 
CircularSinglyLinkedList<T>::~CircularSinglyLinkedList() 
{
  while(capacity--)
  {
    Node<T> *temp = last->next;
    delete last;
    last = temp;
  }
}

  template <class T>
void CircularSinglyLinkedList<T>::link(Node<T> *curr, Node<T> *newNode)
{
  newNode->next = curr->next;
  curr->next = newNode;
}

  template <class T>
void CircularSinglyLinkedList<T>::insert_back(int val) 
{
  if (capacity == 0) 
  {
    last = new Node<T>(val);
    capacity = 1;
    return;
  }

  Node<T> *newNode = new Node(val);
  link(last, newNode);
  last = newNode;

  ++capacity;
}

  template <class T>
void CircularSinglyLinkedList<T>::insert_front(int val) 
{
  if (capacity == 0) 
  {
    last = new Node<T>(val);
    capacity = 1;
    return;
  }

  Node<T> *newNode = new Node(val);
  link(last, newNode);

  ++capacity;
}

  template <class T>
void CircularSinglyLinkedList<T>::insert_at(int index, int val) 
{
  if (capacity == 0) 
  {
    insert_back(val);
    return;
  }

  if (index <= 0) 
    insert_front(val);
  else if (index >= capacity) 
    insert_back(val);
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
void CircularSinglyLinkedList<T>::remove_front()
{
  if (capacity == 0) 
  {
    cerr << "List is empty..." << endl;
    return;
  }
  if (capacity == 1)
  {
    delete last;
    last = nullptr;
    capacity = 0;
    return;
  }

  Node<T> *temp = last->next;
  last->next = last->next->next;

  delete temp;
  --capacity;
}

  template <class T>
void CircularSinglyLinkedList<T>::remove_back()
{
  if (capacity == 0) 
  {
    cerr << "List is empty..." << endl;
    return;
  }
  if (capacity == 1)
  {
    delete last;
    last = nullptr;
    capacity = 0;
    return;
  }

  Node<T> *temp = last->next;
  while (temp->next != last) 
  {
    temp = temp->next;
  }

  temp->next = temp->next->next;
  delete last;
  last = temp;

  --capacity;
}

  template <class T>
void CircularSinglyLinkedList<T>::remove_at(int index)
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
    Node<T> *temp = last->next;
    for(int i=1; i<index && i<capacity; ++i) temp = temp->next;

    Node<T> *temp2 = temp->next;
    temp->next = temp->next->next;
    delete temp2;

    --capacity;

    if (capacity == 1)
      last = temp;
  }
}

  template <class T> 
void CircularSinglyLinkedList<T>::print()
{
  if (capacity == 0) 
  {
    cerr << "List is empty" << endl;
    return;
  }
  if (capacity == 1) 
  {
    cout << last->data << endl;
    return;
  }
  Node<T> *head = last->next;
  while(head != last) 
  {
    cout << head->data << ' ';
    head = head->next;
  }
  cout << head->data << endl;
}
