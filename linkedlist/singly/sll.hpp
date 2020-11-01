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
    void pop_front();
    void pop_back();
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
  ++(this->size);
  temp->next = head;
  head = temp;

  if (!tail)
  {
    tail = head;
    tail->next = nullptr;
  }
}

template <class T>
void SinglyLinkedList<T>::push_back(T data) 
{
  Node<T> *temp = new Node<T>(data);
  ++(this->size);

  if (tail == nullptr) 
  {
    head = tail = temp;
    tail->next = nullptr;
  } 
  else 
  {
    tail->next = temp;
    tail = temp;
    tail->next = nullptr;
  }
}

template <class T>
void SinglyLinkedList<T>::pop_front()
{
  if (this->size == 0)
  {
    cerr << "pop_front(): List is empty" << endl;
    return;
  }

  --(this->size);
  Node<T> *temp = head;
  head = head->next;
  delete temp;
}

template <class T>
void SinglyLinkedList<T>::pop_back()
{
  if (this->size == 0)
  {
    cerr << "pop_front(): List is empty" << endl;
    return;
  }

  --(this->size);

  if (this->size == 0)
  {
    delete head;
    delete tail;
    head = tail = nullptr;
    return;
  }

  Node<T> *temp = head;
  while (temp && temp->next != tail) 
  {
    temp = temp->next;
  }

  delete tail;
  tail = temp;
  if (tail)
  {
    tail->next = nullptr;
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
