/********************************************************************
 *                              stack.c
 ********************************************************************
 * Implementation file for the array based stack
 * 
 * By: Jii Myoi
 * @ : Geisel 
 *******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 

#include "stack.h"

/********************************************************************
* Initialize stack with initial size of 10
 *******************************************************************/
void init(Stack *stk)
{
	const signed char INITIAL_SIZE = 10;

	stk->stack = malloc(sizeof(*(stk->stack)) * INITIAL_SIZE);
	stk->capacity = INITIAL_SIZE;
	stk->size = 0;
}

/********************************************************************
* Deallocate memory for the stack
 *******************************************************************/
void destroy(Stack *stk)
{
	stk->size = 0;
	free(stk->stack);
}

/********************************************************************
* Return true if stack is empty, else false.
 *******************************************************************/
bool isEmpty(const Stack *stk)
{
	return stk->size == 0;
}

/********************************************************************
* Return true if stack is full, else false.
 *******************************************************************/
bool isFull(const Stack *stk)
{
	return stk->size == stk->capacity;
}

/********************************************************************
* Return total number of elements in stack.
 *******************************************************************/
int size(const Stack *stk)
{
	return stk->size;
}

/********************************************************************
* Return the top element in stack.
 *******************************************************************/
elem top(const Stack *stk)
{
	assert(stk->size != 0);

	return stk->stack[stk->size-1];
}

/********************************************************************
* Add data to top of the stack.
 *******************************************************************/
void push(Stack *stk, elem data)
{
	if(stk->size == stk->capacity)
	{
		fprintf(stderr, "Stack is full\n");
		return;
	}

	stk->stack[stk->size] = data;
	++(stk->size);
}

/********************************************************************
* Remove top element in stack.
 *******************************************************************/
void pop(Stack *stk)
{
	--(stk->size);
}
