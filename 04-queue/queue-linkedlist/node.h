#pragma once

typedef struct Node {
	int data;
	struct Node *next;
} Node;

Node* new_node(int);
