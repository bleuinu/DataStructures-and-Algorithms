#pragma once

#include <iostream> 

using std::cout;
using std::endl;

template <class T>
class Deque
{
  private:
    T *queue;
    int head;
    int tail;
    int capacity;
    int nElems;

  public:
    Deque(int size);
    ~Deque();

    void push_front(T val);
    void push_back(T val);
    void pop_front();
    void pop_back();
    T front();
    T back();

    bool empty();
    void print();
};

  template <class T>
Deque<T>::Deque(int size) 
{
  queue = new T[size];
  head = 0;
  tail = 1;
  nElems = 0;
  capacity = size;
}

  template <class T>
Deque<T>::~Deque()
{
  delete queue;
}

  template <class T> 
void Deque<T>::push_front(T val) 
{
  if (nElems == capacity) 
  {
    cout << "overflow.." << endl;
    return;
  }

  queue[head] = val;
  --head;

  if (head == -1) 
  {
    head = capacity - 1;
  }

  ++nElems;
}

  template <class T> 
void Deque<T>::push_back(T val) 
{
  if (nElems == capacity) 
  {
    cout << "overflow.." << endl;
    return;
  }

  queue[tail] = val;
  tail += 1;

  if (tail == capacity)
  {
    tail = 0;
  }

  ++nElems;
}

  template <class T> 
void Deque<T>::pop_front() 
{
  if(empty())
  {
    cout << "underflow.." << endl;
    return;
  }

  --nElems;
  ++head;

  if (head >= capacity) 
  {
    head = 0;
  }
}

  template <class T> 
void Deque<T>::pop_back() 
{
  if(empty())
  {
    cout << "underflow.." << endl;
    return;
  }

  --nElems;
  --tail;

  if (tail < 0)
  {
    tail = capacity - 1;
  }
}

  template <class T> 
T Deque<T>::front() 
{
  int i = head + 1;
  if (i == capacity) i = 0;
  return queue[i];
}

  template <class T> 
T Deque<T>::back() 
{
  int i = tail - 1;
  if (i == -1) i = capacity - 1;
  return queue[i];
}

  template <class T>
bool Deque<T>::empty()
{
  return nElems == 0;
}

  template <class T> 
void Deque<T>::print()
{
  int i = head+1;
  int j = tail;

  if (i == capacity) i = 0;
  do
  {
    if (i == capacity)
    {
      i = 0;
    }
    cout << queue[i] << ' ';
    ++i;
  } while(i != j);
  cout << endl;
}
