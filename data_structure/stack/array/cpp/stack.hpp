/********************************************************************
 *                              stack.hpp
 ********************************************************************
 * Stack array based implementation with template
 * 
 * By: Jii Myoi
 * @ : Home 
 *******************************************************************/
#pragma once

#include <iostream>

using std::cout;
using std::endl;

template <class T>
class Stack {
	private:
		T *stack;
		int stackSize;
		int stackCapacity;

	public:
		Stack ();
		~Stack();

		bool isEmpty() const { return stackSize==0; }
		bool isFull() const {return stackSize==stackCapacity; }
		int size() const { return stackSize; }
		T top() const { return stack[stackSize-1]; }
		void push(T data);
		void pop();

};

template <class T>
Stack<T>::Stack()
{
	const signed char INITIAL_SIZE = 8;
	stack = new T [INITIAL_SIZE];
	stackSize = 0;
	stackCapacity = INITIAL_SIZE;
}

template <class T>
Stack<T>::~Stack()
{
	stackSize = stackCapacity = 0;
	delete(stack);
}

template <class T>
void Stack<T>::push(T data)
{
	if(stackSize == stackCapacity)
	{
		// You can expand the array here
		cout << "Stack is full" << endl;
		return;
	}
	
	stack[stackSize++] = data;
}

template <class T>
void Stack<T>::pop()
{
	if(stackSize == 0)
	{
		// you can return nullptr or throw an exception
		cout << "Stack is empty" << endl;
		return;
	}

	--stackSize;
}
