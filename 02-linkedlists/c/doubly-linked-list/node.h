#pragma once

typedef struct ListNode {
	int data;
	struct ListNode *next;
	struct ListNode *prev;
} ListNode;

ListNode* new_node(int item) {
	ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->data = item;
	return newNode;
}
