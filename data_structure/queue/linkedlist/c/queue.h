/********************************************************************
 *                              queue.h
 ********************************************************************
 * Specification file for the linkedlist based queue
 * 
 * By  : Jii Myoi
 * Date: 12-11-18 09:02
 * @   : Geisel 4F
 *******************************************************************/

#ifndef __QUEUE_H__
#define __QUEUE_H__

typedef _Bool bool;
typedef int elem;

typedef struct Node {
	struct Node *next;
	elem data;

} Node;

typedef struct Queue {
	Node *head;
	Node *tail;
	int size;
} Queue;

/********************************************************************
* Initialize queue with initial size of 10
*
* precondition : none
* postcondition: queue created
 *******************************************************************/
void init(Queue *);

/********************************************************************
* Add an item to the queue
*
* precondition : none
* postcondition: Queue contains n+1 data, where n = current size
 *******************************************************************/
void enqueue(Queue *, elem);

/********************************************************************
* Removes an item from the queue
*
* precondition : Queue contains at least one item
* postcondition: Queue conatins n-1 data, where n = current size
 *******************************************************************/
void dequeue(Queue *);

/********************************************************************
* Get the front item from the queue
*
* precondition : Queue exists
* postcondition: no change
 *******************************************************************/
elem front(const Queue * const);

/********************************************************************
* Get the last item from the queue
*
* precondition : Queue exists
* postcondition: no change
*******************************************************************/
elem rear(const Queue * const);

/********************************************************************
* Remove all nodes and deallocate every memory
*
* precondition : Queue exists
* postcondition: Queue destroyed
*******************************************************************/
void destroy(Queue *);

/********************************************************************
* Display all items in the queu
*
* precondition : queue exists 
* postcondition: none
*******************************************************************/
void display(const Queue * const);

#endif
