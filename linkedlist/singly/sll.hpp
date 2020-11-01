#pragma once

#include <iostream>

using std::cout;
using std::endl;

template <class T>
class Node 
{
  private:
  public:
    Node(T data) { this->data = data; }

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
  tail = nullptr;
  size = 1;
}

template <class T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
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

  if (head == nullptr) 
  {
    head = temp;
    tail = head;
    return;
  }

  temp->next = head;
  head = temp;

  ++(this->size);
}

template <class T>
void SinglyLinkedList<T>::push_back(T data) 
{
  Node<T> *temp = new Node<T>(data);

  if (tail == nullptr) 
  {
    head = temp;
    tail = temp;
    return;
  }

  tail->next = temp;
  tail = temp;

  ++(this->size);
}

template <class T>
void SinglyLinkedList<T>::traverse()
{
  Node<T> *temp = head;
  while(temp->next != nullptr) 
  {
    cout << temp->data << ' ';
    temp = temp->next;
  }

  cout << tail->data << endl;
}
