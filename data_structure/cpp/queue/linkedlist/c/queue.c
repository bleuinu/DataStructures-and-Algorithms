#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "queue.h"

void init(Queue *q)
{
	q->head = q->tail = NULL;
	q->size = 0;
}

void enqueue(Queue *q, elem data)
{
	Node *newNode = malloc(sizeof(*newNode));
	newNode->next = NULL;
	newNode->data = data;

	if(q->tail == NULL)
	{
		q->head = q->tail = newNode;
		return;
	}

	q->tail->next = newNode;
	q->tail = newNode;

	++(q->size);
}

void dequeue(Queue *q)
{
	if(q->head == NULL)
	{
		printf("queue is empty\n");
		assert(0);
	}
	
	Node *temp = q->head;
	q->head = q->head->next;

	if(q->head==NULL)
	{
		q->tail = NULL;
	}

	free(temp);

}

elem front(const Queue * const q)
{
	assert(q->head!=NULL);
	return q->head->data;
}

elem rear(const Queue * const q)
{
	assert(q->tail!=NULL);
	return q->tail->data;
}

void destroy(Queue *q)
{
	Node *temp = q->head;

	while(temp)
	{
		q->head = temp->next;
		free(temp);
		temp = q->head;
	}
	q->head = q->tail = NULL;
}

void display(const Queue * const q)
{
	Node *temp = q->head;

	while(temp != q->tail)
	{
		printf("%d -> ", temp->data);
		temp = temp->next;
	}

	printf("%d\n", q->tail->data);
}
