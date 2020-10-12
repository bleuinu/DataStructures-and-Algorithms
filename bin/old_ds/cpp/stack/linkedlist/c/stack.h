/********************************************************************
 *                              stack.h
 ********************************************************************
 * Specification file for the stack
 * 
 * By: Jii Myoi
 * @ : Geisel 
 *******************************************************************/

#ifndef __STACK_H__
#define __STACK_H__

typedef _Bool bool;
typedef int elem;

typedef struct Node {
	elem data;
	struct Node *next;
} Node;

typedef struct Stack {
	Node *head;
	int size;
} Stack;

/********************************************************************
 * Return true(1) if stack is empty, else false(0) 
 *
 * precondition : stack exists
 * postcondition: no change
 *******************************************************************/
bool isEmpty(const Stack *);

/********************************************************************
 * Returns the total number of elements in stack
 *
 * precondition: stack exists
 * postcondition: no change 
 *******************************************************************/
int size(const Stack *);

/********************************************************************
 * Returns the value of top element in stack.
 *
 * precondition: stack is non-empty.
 * postcondition: no change
 *******************************************************************/
elem top(const Stack *);

/********************************************************************
 * Push an element to the top of the stack
 *
 * precondition: stack exists
 * postcondition: stack is made if empty, else new element is added
 *                and stack size increases by 1
 *******************************************************************/
void push(Stack *, elem);

/********************************************************************
 * Remove the top element in stack. If stack is empty, 
 * 
 * precondition: stack exists
 * postcondition: top element is changed and size decreases by 1
 *******************************************************************/
void pop(Stack *);

/********************************************************************
 * Deallocate all memory
 *
 * precondition : stack exists
 * postcondition: all memory deallocated and the stack is destroyed 
 *******************************************************************/
void destroy(Stack *);

#endif
