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
class CircularDoublyLinkedList 
{
  private: 
    Node<T> *head;
    int capacity;

  public: 
    CircularDoublyLinkedList(int val);
    ~CircularDoublyLinkedList();

    void init(T val);
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
CircularDoublyLinkedList<T>::CircularDoublyLinkedList(int val)
{
  head = new Node(val);
  head->next = head->prev = head;
  capacity = 1;
}

  template <class T> 
CircularDoublyLinkedList<T>::~CircularDoublyLinkedList() 
{
  while(capacity--)
  {
    Node<T> *temp = head;
    delete temp;
    head = head->next;
  }
}

  template <class T>
void CircularDoublyLinkedList<T>::init(T val)
{
  head = new Node<T>(val);
  head->next = head->prev = head;
  capacity = 1;
}

  template <class T>
void CircularDoublyLinkedList<T>::link(Node<T> *curr, Node<T> *newNode)
{
  newNode->next = curr->next;
  curr->next->prev = newNode;
  curr->next = newNode;
  newNode->prev = curr;
}

  template <class T>
void CircularDoublyLinkedList<T>::insert_back(int val) 
{
  if (capacity == 0) 
  {
    init(val);
    return;
  }

  Node<T> *newNode = new Node(val);
  link(head->prev, newNode);

  ++capacity;
}

  template <class T>
void CircularDoublyLinkedList<T>::insert_front(int val) 
{
  if (capacity == 0) 
  {
    init(val);
    return;
  }

  Node<T> *newNode = new Node(val);
  link(head->prev, newNode);
  head = newNode;

  ++capacity;
}

  template <class T>
void CircularDoublyLinkedList<T>::insert_at(int index, int val) 
{
  if (index <= 0) insert_front(val);
  else if (index >= capacity) insert_back(val);
  else 
  {
    Node<T> *temp = head->prev;
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
void CircularDoublyLinkedList<T>::remove_front()
{
  if (capacity == 0) 
  {
    cerr << "List is empty..." << endl;
  }
  else if (capacity == 1)
  {
    delete head;
    head = nullptr;
    capacity = 0;
  }
  else
  {
    Node<T> *temp = head->next;
    head->next->prev = head->prev;
    head->prev->next = head->next;
    delete head;
    head = temp;

    --capacity;
  }
}

  template <class T>
void CircularDoublyLinkedList<T>::remove_back()
{
  if (capacity == 0) 
  {
    cerr << "List is empty..." << endl;
  }
  if (capacity == 1)
  {
    delete head;
    head = nullptr;
    capacity = 0;
  }
  else
  {
    Node<T> *temp = head->prev;
    head->prev->prev->next = head;
    head->prev = head->prev->prev;
    delete temp;

    --capacity;
  }
}

  template <class T>
void CircularDoublyLinkedList<T>::remove_at(int index)
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
    Node<T> *temp = head;
    for(int i=0; i<index; ++i) 
    {
      temp = temp->next;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    temp = nullptr;

    --capacity;
  }
}

  template <class T> 
void CircularDoublyLinkedList<T>::print()
{
  if (capacity == 0) 
  {
    cerr << "List is empty" << endl;
  }
  else if (capacity == 1) 
  {
    cout << head->data << endl;
  }
  else 
  {
    Node<T> *temp = head;
    while(temp->next != head)
    {
      cout << temp->data << ' ';
      temp = temp->next;
    }
    cout << temp->data << endl;
  }
}
