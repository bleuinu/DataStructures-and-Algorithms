#include <iostream>
#include <cstdlib>

#include "stack.hpp"

using namespace std;

int main()
{
	Stack<int> mystack;

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
