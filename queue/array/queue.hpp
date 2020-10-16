#pragma once

#include <iostream> 

using std::cout;
using std::endl;

#define SIZE 10

template <class T>
class Queue
{
  private:
    T queue[SIZE];
    int head;
    int tail;
    int capacity;

  public:
    Queue();
    ~Queue() = default;

    void enqueue(T val);
    void dequeue();
    T peek();

    bool empty();
    void print();
};

template <class T>
Queue<T>::Queue()
{
  head = tail = 0;
  capacity = SIZE;
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
