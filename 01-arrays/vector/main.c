#include <stdio.h>
#include <stdlib.h>

#define DEFAULT 8

typedef struct vector {
	int *arr;
	int size;
	int capacity;
} vector;

void init(vector **);
void _free(vector **);

inline int size(vector *);
inline int capacity(vector *);
_Bool is_empty(vector *);
int at(vector *, int);


int main(void) {
	vector *v = NULL;
	init(&v);

	printf("%d %d\n", v->size, v->capacity);

	if(is_empty(v)) {
		printf("vector is empty\n");
	} else {
		printf("vector is not empty: size(%d)\n", v->size);
	}

	_free(&v);

	return 0;
}

void init(vector **v) {
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

/* 0-based indexing */
int at(vector *v, int index) {
	if(index < 0 || index >= v->size) {
		printf("ERROR: index out of range\n");
		return -1;
	}

	return -1;
}
