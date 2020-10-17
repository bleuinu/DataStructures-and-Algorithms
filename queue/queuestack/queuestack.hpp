#pragma once

#include "../array/queue.hpp"

template <class T>
class QueueStack 
{
  private:
    Queue<T> q1;
    Queue<T> q2;
    int capacity;
    int nElems;

  public:
    QueueStack();
    ~QueueStack() = default;

    void push(int val);
    void pop();
    T top();
    bool empty();
};

template <class T>
QueueStack<T>::QueueStack()
{
  capacity = SIZE;
  nElems = 0;
}

template <class T>
void QueueStack<T>::push(int val)
{
  q2.enqueue(val);
  while(!q1.empty())
  {
    q2.enqueue(q1.peek());
    q1.dequeue();
  }

  Queue<T> q3 = q1;
  q1 = q2;
  q2 = q3;

  ++nElems;
}

template <class T>
void QueueStack<T>::pop()
{
  q1.dequeue();
  --nElems;
}

template <class T> 
bool QueueStack<T>::empty() 
{
  return nElems == 0;
}

template <class T>
T QueueStack<T>::top() 
{
  return q1.peek();
}
