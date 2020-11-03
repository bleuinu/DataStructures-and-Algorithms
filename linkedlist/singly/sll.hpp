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
    Node(T data) : next(nullptr) { this->data = data; }

    Node<T> *next;
    T data;
};

template <class T>
class SinglyLinkedList
{
  private: 
    Node<T> *head;
    Node<T> *tail;
    int size;

  public:
    SinglyLinkedList();
    SinglyLinkedList(T data);
    ~SinglyLinkedList();

    void push_front(T data);
    void push_back(T data);
    void push_at(int index, T data);

    void pop_front();
    void pop_back();
    void pop_at(int index);

    T peek_first();
    T peek_last();

    void traverse();

};

template <class T>
SinglyLinkedList<T>::SinglyLinkedList()
{
  head = tail = nullptr;
  size = 0;
}

template <class T>
SinglyLinkedList<T>::SinglyLinkedList(T data)
{
  head = new Node(data);
  tail = head;
  size = 1;
}

template <class T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
  if (!head) return;

  while (head != tail) 
  {
    Node<T> *temp = head;
    head = head->next;
    delete temp;
  }

  delete head;
  head = tail = nullptr;
}

template <class T>
void SinglyLinkedList<T>::push_front(T data) 
{
  Node<T> *temp = new Node<T>(data);
  temp->next = head;
  head = temp;

  if (tail == nullptr)
  {
    tail = head;
    tail->next = nullptr;
  }

  ++size;
}

template <class T>
void SinglyLinkedList<T>::push_back(T data) 
{
  if (size == 0) 
  {
    push_front(data);
    return;
  }

  Node<T> *temp = new Node<T>(data);
  tail->next = temp;
  tail = temp;
  tail->next = nullptr;

  ++size;
}

template <class T>
void SinglyLinkedList<T>::push_at(int index, T data)
{
  if (index <= 0) 
  {
    push_front(data);
  }
  else if (index >= size) 
  {
    push_back(data);
  }
  else 
  {
    Node<T> *temp = head;
    for (int i=0; i<index-1; ++i)
    {
      temp = temp->next;
    }

    Node<T> *newNode = new Node<T>(data);
    newNode->next = temp->next;
    temp->next = newNode;
    ++size;
  }
}

template <class T>
void SinglyLinkedList<T>::pop_front()
{
  if (size == 0)
  {
    cerr << "pop_front(): List is empty" << endl;
    return;
  }

  --size;
  Node<T> *temp = head;
  head = head->next;
  delete temp;
}

template <class T>
void SinglyLinkedList<T>::pop_back()
{
  if (size == 0)
  {
    cerr << "pop_front(): List is empty" << endl;
    return;
  }

  if (size == 1)
  {
    size = 0;
    delete head;
    head = tail = nullptr;
    size = 0;
    return;
  }

  Node<T> *temp = head;
  for (int i=1; i<size-1; ++i)
  {
    cout << "here" << endl;
    temp = temp->next;
  }

  cout << "temp; " << temp->data << endl;
  delete temp->next;
  temp->next = nullptr;
  tail = temp;

  --size;
}

template <class T>
void SinglyLinkedList<T>::pop_at(int index)
{
  if (index <= 0) 
  {
    pop_front();
  }
  else if (index >= size)
  {
    pop_back();
  }
  else 
  {
    Node<T> *temp = head;
    for (int i=0; i<index-1; ++i)
    {
      temp = temp->next;
    }
    Node<T> *temp2 = temp->next;
    temp->next = temp->next->next;
    --size;
    delete temp2;
  }
}

template <class T>
T SinglyLinkedList<T>::peek_first()
{
  if (size == 0)
  {
    cerr << "List is empty" << endl;
    return static_cast<T>(-1);
  }

  return head->data;
}

template <class T>
T SinglyLinkedList<T>::peek_last()
{
  if (size == 0)
  {
    cerr << "List is empty" << endl;
    return static_cast<T>(-1);
  }

  return tail->data;
}

template <class T>
void SinglyLinkedList<T>::traverse()
{
  if (head == nullptr) 
  {
    cout << "traverse(): List is emtpy" << endl;
    return;
  }

  Node<T> *temp = head;
  while(temp->next != nullptr) 
  {
    cout << temp->data << ' ';
    temp = temp->next;
  }

  cout << temp->data << endl;
}
