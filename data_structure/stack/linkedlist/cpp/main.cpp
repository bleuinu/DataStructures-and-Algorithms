#include <iostream>

#include "stack.hpp"

using namespace std;

int main()
{
	Stack<int> mystack(5);

	for(int i=0; i<10; ++i)
	{
		mystack.push(rand()%100);
	}

	while(!mystack.isEmpty())
	{
		mystack.pop();
	}
	return 0;
}
