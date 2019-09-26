#include <iostream>

#include "queue.hpp"

using namespace std;

int main()
{
	// Create a queue with one node 
	Queue<int> myqueue(10);
	myqueue.print();

	for(int i=0; i<10; ++i)
	{
		myqueue.enqueue(rand()%100);
		myqueue.print();
	}

	while(!myqueue.isEmpty())
	{
		myqueue.dequeue();
		myqueue.print();
	}
	return 0;
}
