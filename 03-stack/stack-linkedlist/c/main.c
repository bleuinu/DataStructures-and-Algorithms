#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "stack.h"

int main(void) {
	unsigned seed = time(0);
	srand(seed);

	Stack *stack = init();

	for(int i=0; i<3; ++i) {
		push(stack, i+1);
		printf("peeking: %d\n", peek(stack));
		print(stack);
	}

	for(int i=0; i<4; ++i) {
		pop(stack);
		if(rand()%2 == 0) push(stack, rand() % 100);
		printf("peeking: %d\n", peek(stack));
		print(stack);
	}

	pop(stack);
	peek(stack);
	if(is_empty(stack)) {
		printf("stack is empty\n");
	} else {
		printf("stack is NOT empty. top element is %d\n", peek(stack));
	}

	_free(&stack);

	push(stack, 1);
	pop(stack);
	peek(stack);
	is_empty(stack);

	if(!stack) printf("stack is deleted\n");
	else  printf("stack still exists\n");

	return 0;
}

/* Node */
Node* newNode(int data) {
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->next = NULL;
	new_node->data = data;
	return new_node;
}


/* Stack */
Stack* init(void) {
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	stack->top = newNode(-1);
	stack->size = 0;
	return stack;
}

void _free(Stack **stack) {
	while(!is_empty(*stack)) {
		pop(*stack);
	}
	free((*stack)->top);
	free(*stack);
	*stack = NULL;
}

void print(Stack *stack) {
	Node *temp = stack->top->next;
	for(int i=0; i<stack->size; ++i) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void push(Stack *stack, int data) {
	printf("[ push %d ]\n", data);

	if(!stack) {
		printf("ERROR: stack is not initialized.\n");
		return;
	}

	Node *new_node = newNode(data);
	new_node->next = stack->top->next;
	stack->top->next = new_node;
	++(stack->size);
}

void pop(Stack *stack) {
	printf("[ pop ]\n");

	if(!stack) {
		printf("ERROR: stack is not initialized.\n");
		return;
	}

	if(stack->size == 0) {
		printf("ERROR: stack is empty\n");
		return;
	}

	Node *temp = stack->top->next;
	stack->top->next = temp->next;
	free(temp);
	--(stack->size);
}

int peek(Stack *stack) {
	if(!stack) {
		printf("ERROR: stack is not initialized.\n");
		return -1;
	}

	if(stack->size == 0) {
		printf("ERROR: stack is empty\n");
		return -1;
	}

	return stack->top->next->data;
}

_Bool is_empty(Stack *stack) {
	if(!stack) {
		printf("ERROR: stack is not initialized.\n");
		return 0;
	}

	return stack->size == 0;
}
