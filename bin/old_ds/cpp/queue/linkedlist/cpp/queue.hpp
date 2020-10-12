/********************************************************************
 *                              queue.hpp
 ********************************************************************
 * Queue linked list based implementation with template
 * 
 * By: Jii Myoi
 * @ : Home 
 *******************************************************************/
#pragma once

#include <iostream>
#include <cassert>

#include "node.hpp"

using std::cout;
using std::endl;

template <class T>
class Queue 
{
	private:
		Node<T> *head;
		Node<T> *tail;
		int size;
	public:
		Queue();
		Queue(T);
		~Queue();

		void enqueue(T data);
		void dequeue();
		T front() const;
		T rear() const;
		bool isEmpty() const;
		void print() const;
};

template <class T>
Queue<T>::Queue()
{
	head = new Node<T>();
	tail = head;
	this->size = 0;
}

template <class T>
Queue<T>::Queue(T data)
{
	head = new Node<T>(data);
	tail = head;
	this->size = 1;
}

template <class T>
Queue<T>::~Queue()
{
	while(head)
	{
		Node<T> *temp = head->next;
		delete(head);
		head = temp;
	}
}

template <class T>
void Queue<T>::enqueue(T data)
{
	Node<T> *temp = new Node<T>(data);
	tail->next = temp;
	tail = temp;
	++(this->size);
}

template <class T>
void Queue<T>::dequeue()
{
	if(head)
	{
		Node<T> *temp = head->next;
		delete(head);
		head = temp;
		--(this->size);
	}
	else
	{
		assert(false);
	}
}

template <class T>
T Queue<T>::front() const 
{
	return head->data;
}

template <class T>
T Queue<T>::rear() const 
{
	return tail->data;
}

template <class T>
bool Queue<T>::isEmpty() const
{
	return this->size==0;
}

template <class T>
void Queue<T>::print() const 
{
	if(!isEmpty())
	{
		Node<T> *temp = head;

		while(temp)
		{
			cout << temp->data << ' ';
			temp = temp->next;
		}
		cout << "\tfront: " << front() << '\t' << "rear: " << rear() << endl;
	}
}
