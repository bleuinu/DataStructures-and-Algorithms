#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "queue.h"

int main(void) {
	unsigned seed = time(0);
	srand(seed);

	Queue *queue = init();

	for(int i=0; i<3; ++i) {
		enqueue(queue, i+1);
		printf("front: %d\n", front(queue));
		print(queue);
	}

	for(int i=0; i<4; ++i) {
		dequeue(queue);
		if(rand()%2 == 0) enqueue(queue, rand() % 100);
		printf("front: %d\n", front(queue));
		print(queue);
	}

	dequeue(queue);
	front(queue);
	if(empty(queue)) {
		printf("queue is empty\n");
	} else {
		printf("queue is NOT empty. top element is %d\n", front(queue));
	}

	_free(&queue);

	enqueue(queue, 1);
	dequeue(queue);
	front(queue);
	empty(queue);

	if(!queue) printf("queue is deleted\n");
	else  printf("queue still exists\n");

	return 0;
}

/* Node */
Node* new_node(int data) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = data;
	return newNode;
}


/* Queue */
Queue* init(void) {
	Queue *queue = (Queue *)malloc(sizeof(Queue));
	queue->front = new_node(-1);
	queue->back = NULL;
	queue->front->next = queue->back;
	queue->size = 0;
	return queue;
}

void _free(Queue **queue) {
	while(!empty(*queue)) {
		dequeue(*queue);
	}
	free((*queue)->front);
	free(*queue);
	*queue = NULL;
}

void print(Queue *queue) {
	Node *temp = queue->front->next;
	for(int i=0; i<queue->size; ++i) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void enqueue(Queue *queue, int data) {
	printf("[ enqueue %d ]\n", data);

	if(!queue) {
		printf("ERROR: queue is not initialized.\n");
		return;
	}

	Node *newNode = new_node(data);
	if(queue->back == NULL) {
		queue->back = newNode;
		queue->front->next = queue->back;
	} else {
		queue->back->next = newNode;
		queue->back = newNode;
	}
	++(queue->size);
}

void dequeue(Queue *queue) {
	printf("[ dequeue ]\n");

	if(!queue) {
		printf("ERROR: queue is not initialized.\n");
		return;
	}

	if(queue->size == 0) {
		printf("ERROR: queue is empty\n");
		return;
	}

	Node *temp = queue->front->next;
	queue->front->next = temp->next;
	free(temp);
	--(queue->size);
}

int front(Queue *queue) {
	if(!queue) {
		printf("ERROR: queue is not initialized.\n");
		return -1;
	}

	if(queue->size == 0) {
		printf("ERROR: queue is empty\n");
		return -1;
	}

	return queue->front->next->data;
}

_Bool empty(Queue *queue) {
	if(!queue) {
		printf("ERROR: queue is not initialized.\n");
		return 0;
	}

	return queue->size == 0;
}
