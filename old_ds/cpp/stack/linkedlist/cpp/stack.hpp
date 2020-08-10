/********************************************************************
 *                              stack.hpp
 ********************************************************************
 * Stack linked list based implementation with template
 * 
 * By: Jii Myoi
 * @ : Home 
 *******************************************************************/

#pragma once

template <class T>
class Node {
	private:
		Node *prev;
		T data;

	public:
		Node(T data)
		{
			this->data = data;
			this->prev = nullptr;
		}

		template<class Type>
		friend class Stack;
};

template <class T>
class Stack {
	private:
		Node<T> *head;
		int stackSize;

	public:
		Stack (T data);
		~Stack();

		bool isEmpty() const { return stackSize==0; }
		int size() const { return stackSize; }
		T top() const { return head->data; }
		void push(T data);
		void pop();

};

template <class T>
Stack<T>::Stack(T data)
{
	Node<T> *temp = new Node<T>(data);
	head = temp;
	stackSize = 1;
}

template <class T>
Stack<T>::~Stack()
{
	while(!isEmpty())
	{
		pop();
	}

	delete(head);
}

template <class T>
void Stack<T>::push(T data)
{
	Node<T> *temp = new Node<T>(data);
	temp->prev = head;
	head = temp;
	++(stackSize);
}

template <class T>
void Stack<T>::pop()
{
	Node<T> *temp = head;
	head = head->prev;
	temp->prev = nullptr;
	delete(temp);
	--(stackSize);
}
