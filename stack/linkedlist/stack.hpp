#pragma once

#include <iostream> 
using namespace std;

class Node 
{
  public: 
    Node(int val):data(val), next(nullptr) {}

    int data;
    Node *next;
};

class Stack 
{
  private:
    Node *sentinel;

  public:
    Stack();
    ~Stack();

    void push(int);
    void pop();
    int top();
    bool empty();

    void print();
};

Stack::Stack() 
{
  sentinel = new Node(0);
  sentinel->next = sentinel;
}

Stack::~Stack() 
{
  while (sentinel->next != sentinel) 
  {
    Node *temp = sentinel->next;
    sentinel->next = temp->next;
    delete temp;
  }

  delete sentinel;
}

void Stack::push(int x)
{
  Node *node = new Node(x);

  node->next = sentinel->next;
  sentinel->next = node; 
}

void Stack::pop()
{
  Node *temp = sentinel->next;
  sentinel->next = sentinel->next->next;
  delete temp;
}

int Stack::top()
{
  return sentinel->next->data;
}

bool Stack::empty() 
{
  return sentinel->next == sentinel;
}

void Stack::print() 
{
  Node *temp = sentinel->next;

  while (temp != sentinel) 
  {
    cout << temp->data << ' ';
    temp = temp->next;
  }
  cout << endl;
}
