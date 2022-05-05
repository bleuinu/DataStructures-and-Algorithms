#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "vector.h"
#include "debug.h"

#define DEFAULT 16

int main(void) {
	unsigned seed = time(0);
	srand(seed);

#ifdef TEST_INIT
	vector *v = NULL;
	init(&v);
	printf("size: %d    capacity: %d\n", v->size, v->capacity);
	printf("\n");
#endif

#ifdef TEST_IS_EMPTY
	if(is_empty(v)) {
		printf("vector is empty\n");
	} else {
		printf("vector is not empty: size(%d)\n", v->size);
	}
	printf("\n");
#endif

#ifdef TEST_PUSH
	push(v, 1);
	print(v);
	push(v, 2);
	print(v);
	push(v, 3);
	print(v);
	push(v, 4);
	print(v);

	printf("\n");

	printf("arr[0]: %d\n", at(v, 0));
	printf("arr[1]: %d\n", at(v, 1));
	printf("arr[2]: %d\n", at(v, 2));
	printf("arr[3]: %d\n", at(v, 3));
	printf("arr[4]: %d\n", at(v, 4));
	print(v);

	printf("\n");

	push(v, 1);
	print(v);
	push(v, 2);
	print(v);
	push(v, 3);
	print(v);
	push(v, 4);
	print(v);

	push(v, 1);
	print(v);

	printf("\n");
#endif

#ifdef TEST_INSERT
	insert(v, 0, 17);
	print(v);
	insert(v, 1, 12);
	print(v);
	insert(v, 1, 123);
	print(v);

	for(int i=0; i<DEFAULT; ++i) {
		insert(v, 0, rand()%100);
		print(v);
	}

	printf("\n");
#endif

#ifdef TEST_PREPEND
	for(int i=0; i<DEFAULT + 1; ++i) {
		prepend(v, rand()%100);
		print(v);
	}
	printf("\n");
#endif

#ifdef TEST_FIND
	printf("%d is at index %d\n", 56, find(v, 56));
	printf("%d is at index %d\n", 30, find(v, 30));
	printf("%d is at index %d\n", 12, find(v, 12));
	printf("%d is at index %d\n", 11, find(v, 11));
	printf("%d is at index %d\n", 49, find(v, 49));

	printf("\n");
#endif

#ifdef TEST_REMOVE
	push(v, 1);
	push(v, 2);
	push(v, 2);
	push(v, 1);
	push(v, 3);
	push(v, 5);
	push(v, 6);
	print(v);

	remove_all(v, 1);
	print(v);
	printf("\n");

	remove_all(v, 5);
	print(v);
	printf("\n");

	remove_all(v, 2);
	print(v);
	printf("\n");
#endif

#ifdef TEST_RESIZE_HALVE
	for(int i=0; i<DEFAULT*2; ++i) {
		push(v, rand() % 100);
	}
	print(v);

	while(!is_empty(v)) {
		// pop(v);
		delete_at(v, rand() % v->size);
		print(v);
	}

	printf("\n");
#endif

#ifdef TEST_RESIZE_DOUBLE
	for(int i=0; i<DEFAULT; ++i) {
		push(v, rand() % 100);
		print(v);
		insert(v, rand() % v->size, rand() % 100);
		print(v);
	}

	printf("\n");
#endif

#ifdef TEST_DELETE_AT
	print(v);
	for(int i=0; i<DEFAULT; ++i) {
		printf("removed %d\n", delete_at(v, rand() % 10));
		print(v);
	}

	printf("\n");
#endif

#ifdef TEST_POP
	print(v);
	while(!is_empty(v)) {
		printf("popped: %d\n", pop(v));
		print(v);
	}

	pop(v);
	printf("\n");
#endif

#ifdef TEST_INIT
	_free(&v);
#endif

	return 0;
}

static void resize(vector *v, int new_capacity) {
	int *new_arr = (int *)malloc(sizeof(int) * new_capacity);

	for(int i=0; i<v->size; ++i) {
		new_arr[i] = (v->arr)[i];
	}

	free(v->arr);
	v->arr = new_arr;
	v->capacity = new_capacity;
}

void init(vector **v) {
#ifdef DEBUG
	printf("inside 'init'\n");
	printf("Default capacity is set to %d\n", DEFAULT);
#endif
	*v = (vector *)malloc(sizeof(vector));
	(*v)->size = 0;
	(*v)->capacity = DEFAULT;
	(*v)->arr = (int *)malloc(sizeof(int) * DEFAULT);
}

void _free(vector **v) {
	free((*v)->arr);
	free(*v);
	*v = NULL;
}

inline int size(vector *v) {
	return v->size;
}

inline int capacity(vector *v) {
	return v->capacity;
}

_Bool is_empty(vector *v) {
	return !(v->size);
}

int at(vector *v, int index) {
#ifdef DEBUG
	printf("inside 'at': at(%d)\n", index);
#endif

	if(is_empty(v)) {
		printf("ERROR: empty vector\n");
		return -1;
	}

	if(index < 0 || index >= v->size) {
		printf("ERROR: index out of range\n");
		return -1;
	}

	return (v->arr)[index];
}

int find(vector *v, int item) {
#ifdef DEBUG
	printf("inside 'find': look up item: %d\n", item);
#endif

	if(is_empty(v)) {
		printf("ERROR: empty vector\n");
		return -1;
	}

	for(int i=0; i<v->size; ++i) {
		if((v->arr)[i] == item) return i;
	}
	return -1;
}

void remove_all(vector *v, int item) {
#ifdef DEBUG
	printf("inside 'remove': delete all occurrences of %d\n", item);
#endif

	if(is_empty(v)) {
		printf("ERROR: empty vector\n");
		return;
	}

	while(1) {
		int i = find(v, item);
		if(i != -1) {
			delete_at(v, i);
		} else {
			break;
		}
	}
}

void push(vector *v, int data) {
#ifdef DEBUG
	printf("inside 'push': pushing %d\n", data);
#endif

	if(v->size == v->capacity) {
		resize(v, (v->capacity) << 1);
	}
	(v->arr)[v->size] = data;
	++(v->size);
}

void insert(vector *v, int index, int item) {
#ifdef DEBUG
	printf("inside insert: insert %d at location %d\n", item, index);
#endif

	if(v->size == v->capacity) {
		resize(v, (v->capacity) << 1);
	}

	if(index < 0 || index > v->size) {
		printf("ERROR: index out of range\n");
		return;
	}

	for(int i=(v->size); i>index; --i) {
		(v->arr)[i] = (v->arr)[i-1];
	}

	(v->arr)[index] = item;
	++(v->size);
}

void prepend(vector *v, int item) {
#ifdef DEBUG
	printf("inside 'prepend': prepend %d\n", item);
#endif

	insert(v, 0, item);
}

int pop(vector *v) {
#ifdef DEBUG
	printf("inside 'pop'\n");
#endif

	if(is_empty(v)) {
		printf("ERROR: empty vector\n");
		return -1;
	}

	--(v->size);

	if(v->size == (v->capacity)/4) {
		resize(v, (v->capacity) >> 1);
	}
	return (v->arr)[v->size];
}

int delete_at(vector *v, int index) {
#ifdef DEBUG
	printf("inside 'delete_at': delete item at index %d\n", index);
#endif

	if(is_empty(v)) {
		printf("ERROR: empty vector\n");
		return -1;
	}

	if(index < 0 || index >= v->size) {
		printf("ERROR: index out of range\n");
		return -1;
	}
	int item = (v->arr)[index];

	for(int i=index; i<v->size-1; ++i) {
		(v->arr)[i] = (v->arr)[i+1];
	}

	--(v->size);
	if(v->size == (v->capacity)/4) {
		resize(v, (v->capacity) >> 1);
	}
	return item;
}

void print(vector *v) {
	const int SIZE = v->size;
	printf("[%d/%d] ", SIZE, v->capacity);
	for(int i=0; i<SIZE; ++i) {
		printf("%2d ", (v->arr)[i]);
	}
	printf("\n");
}
