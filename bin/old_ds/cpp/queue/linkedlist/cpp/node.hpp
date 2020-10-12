/********************************************************************
 *                              node.hpp
 ********************************************************************
 * Node implementation with template used in Stack
 * 
 * By: Jii Myoi
 * @ : Home 
 *******************************************************************/

#pragma once

template <class Type>
class Node 
{
	private:
		Node<Type> *next;
		Type data;
	public:
		Node();
		Node(Type);

		template <class T>
		friend class Queue;
};

template <class T>
Node<T>::Node()
{
	next = nullptr;
}

template <class T>
Node<T>::Node(T data)
{
	next = nullptr;
	this->data = data;
}
