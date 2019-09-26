/********************************************************************
 *                              stack.h
 ********************************************************************
 * Specification file for the array based stack
 * 
 * By: Jii Myoi
 * @ : Geisel 
 *******************************************************************/

#ifndef __STACK_H__
#define __STACK_H__

typedef _Bool bool;
typedef int elem;

typedef struct Stack {
	elem *stack;
	int size;
	int capacity;
} Stack;

/********************************************************************
* Initialize stack with initial size of 10
*
* precondition : none
* postcondition: stack exists
 *******************************************************************/
void init(Stack *);

/********************************************************************
* Deallocate memory for the stack
*
* precondition : stack exists
* postcondition: stack is deallocated
 *******************************************************************/
void destroy(Stack *);

/********************************************************************
* Return true if stack is empty, else false.
*
* precondition : stack exists
* postcondition: no change
 *******************************************************************/
bool isEmpty(const Stack *);

/********************************************************************
* Return true if stack is full, else false.
*
* precondition : stack exists
* postcondition: no change
 *******************************************************************/
bool isFull(const Stack *);

/********************************************************************
* Return total number of elements in stack.
*
* precondition : stack exists
* postcondition: no change
 *******************************************************************/
int size(const Stack *);

/********************************************************************
* Return the top element in stack.
*
* precondition : stack is non-empty
* postcondition: stack size decreased by 1
 *******************************************************************/
elem top(const Stack *);

/********************************************************************
* Add data to top of the stack.
*
* precondition : stack exists
* postcondition: stack contains new data and size increases by 1
 *******************************************************************/
void push(Stack *, elem);

/********************************************************************
* Remove top element in stack.
*
* precondition : stack exists
* postcondition: stack top element changed and size decreases by 1
 *******************************************************************/
void pop(Stack *);

#endif
