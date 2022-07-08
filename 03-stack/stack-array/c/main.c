#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "stack.h"

int main(void) {
    unsigned seed = time(0);
    srand(seed);

    Stack *stack = init();

    for(int i=0; i<15; ++i) {
        push(stack, rand()%100);
        print(stack);
    }

    printf("peek: %d\n", peek(stack));

    for(int i=0; i<10; ++i) {
        pop(stack);
    }

    push(stack, 1);
    push(stack, 2);
    print(stack);

    free(stack);

    return 0;
}

Stack* init(void) {
	Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->item = 0;
    stack->size = SIZE;

    return stack;
}

void print(Stack *stack) {
    for(int i=0; i<stack->item; ++i) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

_Bool is_full(Stack *stack) {
    return stack->item == stack->size;
}

_Bool is_empty(Stack *stack) {
    return stack->item == 0;
}

void push(Stack *stack, int value) {
    if(is_full(stack)) {
        printf("Stack is full...\n");
        return;
    }

    stack->arr[stack->item] = value;
    ++(stack->item);
}

void pop(Stack *stack) {
    if(is_empty(stack)) {
        printf("Stack is empty...\n");
        return;
    }

    --(stack->item);
}

int peek(Stack *stack) {
    if(is_empty(stack)) {
        printf("Stack is empty...\n");
        return -1;
    }

    return stack->arr[(stack->item)-1];
}