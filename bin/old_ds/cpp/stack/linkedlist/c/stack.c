/********************************************************************
 *                              stack.c
 ********************************************************************
 * Implementation file for the stack
 * 
 * By: Jii Myoi
 * @ : Geisel 
 *******************************************************************/

#include <stdlib.h>
#include <assert.h>

#include "stack.h"

/********************************************************************
 * Return true(1) if stack is empty, else false(0)
 *******************************************************************/
bool isEmpty(const Stack *stk)
{
	return stk->size == 0;
}

/********************************************************************
 * Returns the total number of elements in stack
 *******************************************************************/
int size(const Stack *stk)
{
	return stk->size;
}

/********************************************************************
 * Returns the value of top element in stack.
 *******************************************************************/
elem top(const Stack *stk)
{
	assert(stk->size != 0);

	return stk->head->data;
}

/********************************************************************
 * Push an element to the top of the stack
 *******************************************************************/
void push(Stack *stk, elem _data)
{
	if(stk->head == NULL)
	{
		stk->head = malloc(sizeof(*(stk->head)));
		stk->head->data = _data;
		stk->head->next = NULL;
	}
	else
	{
		Node *temp = malloc(sizeof(*temp));
		temp->data = _data;
		temp->next = stk->head;
		stk->head = temp;
	}

	++(stk->size);
}

/********************************************************************
 * Remove the top element in stack.
 *******************************************************************/
void pop(Stack *stk)
{
	if(isEmpty(stk))
	{
		return;
	}

	Node *temp = stk->head;
	stk->head = stk->head->next;
	temp->next = NULL;
	free(temp);

	--(stk->size);
}

/********************************************************************
 * Remove the top element in stack.
 *******************************************************************/
void destroy(Stack *stk)
{
	if(stk)
	{
		while(!isEmpty(stk))
		{
			pop(stk);
		}
	}
}
