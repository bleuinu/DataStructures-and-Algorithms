#pragma once

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct node_t
{
	int data;
	struct node_t *left;
	struct node_t *right;
	// 1 = points to the child
	// 0 = points to predecessor/successor
	_Bool leftBit;
	_Bool rightBit;
} Node;

Node* createNode(int val)
{
	Node *rv = calloc(1, sizeof(*rv));
	rv->data = val;

	return rv;
}

Node* init(void)
{
	Node *dummy = createNode(0);
	dummy->rightBit = TRUE;
	dummy->right = dummy;
	dummy->leftBit = FALSE;
	dummy->left = dummy;

	return dummy;
}

Node* insertNode(Node *dummy, int val)
{
	Node *newNode = createNode(val);

	// tree is empty
	if(dummy->left == dummy)
	{
		newNode->left = dummy->left;
		dummy->left = newNode;
		newNode->leftBit = dummy->leftBit;
		dummy->leftBit = TRUE;
		newNode->right = dummy;
		
		return dummy;
	}

	// tree is not empty
	Node *curr = dummy->left;

	while(TRUE)
	{
		if(val < curr->data)
		{
			if(curr->leftBit == FALSE)
			{
				newNode->left = curr->left;
				curr->left = newNode;
				newNode->leftBit = curr->leftBit;
				curr->leftBit = TRUE;
				newNode->right = curr;

				return dummy;
			}
			else
			{
				curr = curr->left;
			}
		}
		else
		{
			if(curr->rightBit == FALSE)
			{
				newNode->right = curr->right;
				curr->right = newNode;
				newNode->rightBit = curr->rightBit;
				curr->rightBit = TRUE;
				newNode->left = curr;

				return dummy;
			}
			else
			{
				curr = curr->right;
			}
		}
	}
}

Node* leftMostNode(Node *node)
{
	Node *rv = node;
	while(rv->leftBit == 1)
	{
		rv = rv->left;
	}

	return rv;
}

void inorder(Node *dummy)
{
	Node *curr = leftMostNode(dummy->left);
	while(curr != dummy)
	{
		printf("%d ", curr->data);
		
		if(curr->rightBit == 0)
		{
			curr = curr->right;
		}
		else
		{
			curr = leftMostNode(curr->right);
		}
	}

	printf("\n");
}

void destroyTree(Node *dummy)
{
	Node *curr = leftMostNode(dummy->left);
	while(curr != dummy)
	{
		Node *temp = curr;

		if(curr->rightBit == 0)
		{
			curr = curr->right;
		}
		else
		{
			curr = leftMostNode(curr->right);
		}

		free(temp);
		temp = NULL;
	}

	free(dummy);
	dummy = NULL;
}
