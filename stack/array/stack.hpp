#pragma once

#include <iostream> 

using std::cout;
using std::endl;

#define SIZE 10

template <class T>
class Stack 
{
  private:
    T *stack;
    int top;
    int capacity;

  public:
    Stack(int n);
    ~Stack();

    void pop();
    void push(T val);
    T peek();
    bool empty();
    void print(); 
};

template <class T>
Stack<T>::Stack(int n) 
{
  stack = new T[n+1];
  top = 0;
  capacity = n;
}

template <class T>
Stack<T>::~Stack() 
{
  capacity = top = 0;
  delete [] stack;
}

template <class T>
bool Stack<T>::empty()
{
  return top == 0;
}

template <class T>
void Stack<T>::push(T val)
{
  if (top == capacity)
  {
    cout << "Overflow...";
    return;
  }

  top += 1;
  stack[top] = val;
}

template <class T>
void Stack<T>::pop() 
{
  if(empty())
  {
    cout << "Underflow...";
    return;
  }
  top -= 1;
}

template <class T> 
T Stack<T>::peek() 
{
  return stack[top];
}

template <class T> 
void Stack<T>::print() 
{
  for(int i=1; i<=top; ++i)
  {
    cout << stack[i] << ' ';
  }
  cout << endl;
}
