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
    Node<T> *tail;
    int capacity;

  public: 
    DoublyLinkedList(int val);
    ~DoublyLinkedList();

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
DoublyLinkedList<T>::DoublyLinkedList(int val)
{
  init(val);
  capacity = 1;
}

  template <class T> 
DoublyLinkedList<T>::~DoublyLinkedList() 
{
  while(head != tail)
  {
    Node<T> *temp = head;
    head = head->next;
    delete temp;
  }
  delete tail;
}

  template <class T>
void DoublyLinkedList<T>::init(T val)
{
  head = new Node<T>(val);
  tail = head;
  head->next = tail;
  tail->prev = head;
  head->prev = tail->next = nullptr;
}

  template <class T>
void DoublyLinkedList<T>::link(Node<T> *curr, Node<T> *newNode)
{
  curr->next = newNode;
  newNode->prev = curr;
}

  template <class T>
void DoublyLinkedList<T>::insert_back(int val) 
{
  if (capacity == 0) 
  {
    init(val);
    return;
  }

  Node<T> *newNode = new Node(val);
  if (capacity == 1)
  {
    link(head, newNode);
  }
  else 
  {
    link(tail, newNode);
  }
  tail = newNode;

  ++capacity;
}

  template <class T>
void DoublyLinkedList<T>::insert_front(int val) 
{
  if (capacity == 0) 
  {
    init(val);
    return;
  } 

  Node<T> *newNode = new Node(val);
  if (capacity == 1)
  {
    link(newNode, tail);
  }
  else
  {
    link(newNode, head);
  }
  head = newNode;

  ++capacity;
}

  template <class T>
void DoublyLinkedList<T>::insert_at(int index, int val) 
{
  if (index <= 0) 
  {
    insert_front(val);
  }
  else if (index >= capacity) 
  {
    insert_back(val);
  }
  else 
  {
    Node<T> *temp = head;
    for (int i=0; i<index; ++i) 
    {
      temp = temp->next;
    }

    Node<T> *newNode = new Node(val);
    temp->prev->next = newNode;
    newNode->prev = temp->prev;
    link(newNode, temp);

    ++capacity;
  }
}

  template <class T>
void DoublyLinkedList<T>::remove_front()
{
  if (capacity == 0) 
  {
    cerr << "List is empty..." << endl;
  }
  else if (capacity == 1)
  {
    delete head;
    head = tail = nullptr;
    capacity = 0;
  }
  else
  {
    Node<T> *temp = head;
    head = head->next;
    delete temp;
    head->prev = nullptr;

    --capacity;
  }
}

  template <class T>
void DoublyLinkedList<T>::remove_back()
{
  if (capacity == 0) 
  {
    cerr << "List is empty..." << endl;
  }
  else if (capacity == 1)
  {
    delete head;
    head = tail = nullptr;
    capacity = 0;
  }
  else
  {
    Node<T> *temp = tail;
    tail = tail->prev;
    delete temp;
    tail->next = nullptr;

    --capacity;
  }
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
  {
    remove_front();
  }
  else if (index >= (capacity-1)) 
  {
    remove_back();
  }
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

    --capacity;
  }
}

  template <class T> 
void DoublyLinkedList<T>::print()
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
    while (temp != tail)
    {
      cout << temp->data << ' ';
      temp = temp->next;
    }
    cout << temp->data << endl;
  }
}
