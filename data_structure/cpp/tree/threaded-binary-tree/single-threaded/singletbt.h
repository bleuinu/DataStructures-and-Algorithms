#pragma once

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct node_t
{
	struct node_t *left;
	struct node_t *right;
	int data;
	_Bool rightThread;
} Node;

Node* createNode(int val)
{
	Node *rv = malloc(sizeof(*rv));
	rv->left = NULL;
	rv->right = NULL;
	rv->data = val;
	rv->rightThread = FALSE;
}

Node* insertNode(Node *root, int val)
{
	Node *newNode = createNode(val);
	Node *curr = root;
	Node *parent = NULL;

	if(curr == NULL) 
	{
		return newNode;
	}

	while(TRUE)
	{
		parent = curr;
		if(val < curr->data)
		{
			curr = curr->left;
			if(curr == NULL)
			{
				parent->left = newNode;
				newNode->right = parent;
				newNode->rightThread = TRUE;
				return root;
			}
		}
		else
		{
			if(curr->rightThread == FALSE)
			{
				curr = curr->right;
				if(curr == NULL)
				{
					// last node does not have a successor
					parent->right = newNode;
					return root;
				}
			}
			else
			{
				Node *succ = curr->right;
				curr->right = newNode;
				curr->rightThread = FALSE;
				newNode->right = succ;
				newNode->rightThread = TRUE;
				return root;
			}
		}
	}
}

Node* leftMostNode(Node *rv)
{
	if(rv == NULL) return NULL;
	else
	{
		while(rv->left != NULL)
		{
			rv = rv->left;
		}
		return rv;
	}
}

void inorder(Node *root)
{
	Node *curr = leftMostNode(root);
	if(curr == NULL) return;

	while(curr)
	{
		printf("%d ", curr->data);
		if(curr->rightThread)
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

void destroyTree(Node *node)
{
	Node *curr = leftMostNode(node);
	if(curr == NULL) return;

	while(curr)
	{
		Node *temp = curr;
		if(curr->rightThread)
		{
			curr = curr->right;
		}
		else
		{
			curr = leftMostNode(curr->right);
		}

		free(temp);
	}
}
