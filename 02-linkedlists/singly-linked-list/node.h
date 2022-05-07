#pragma once

typedef struct ListNode {
	int data;
	struct ListNode *next;
} ListNode;

ListNode* new_node(int item, ListNode *next) {
	ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
	newNode->data = item;
	newNode->next = next;
	return newNode;
}
