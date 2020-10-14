#pragma once

#include <iostream> 

using std::cout;
using std::endl;

template <class T>
class Queue
{
  private:
    T *queue;
    int head;
    int tail;
    int capacity;

  public:
    Queue(int size);
    ~Queue();

    void enqueue(T val);
    void dequeue();
    T peek();

    bool empty();
    void print();
};

template <class T>
Queue<T>::Queue(int size) 
{
  queue = new T[size];
  head = tail = 0;
  capacity = size;
}

template <class T>
Queue<T>::~Queue()
{
  delete queue;
}

template <class T> 
void Queue<T>::enqueue(T val) 
{
  if (tail == capacity) 
  {
    cout << "overflow.." << endl;
    return;
  }

  queue[tail] = val;
  tail += 1;
}

template <class T> 
void Queue<T>::dequeue() 
{
  if(empty())
  {
    cout << "underflow.." << endl;
    return;
  }

  for (int i=1; i<tail; ++i) 
  {
    queue[i-1] = queue[i];
  }
  queue[tail-1] = queue[tail];

  tail -= 1;
}

template <class T> 
T Queue<T>::peek() 
{
  return queue[head];
}

template <class T>
bool Queue<T>::empty()
{
  return tail == 0;
}

template <class T> 
void Queue<T>::print()
{
  for(int i=0; i<tail; ++i) 
  {
    cout << queue[i] << ' ';
  }
  cout << endl;
}
