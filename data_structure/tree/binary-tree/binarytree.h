#pragma once

#include <stdlib.h>
#include <queue>
#include <stack>

using namespace std;

typedef struct node_t
{
	int val;
	struct node_t *left;
	struct node_t *right;
} Node;

Node* createNode(int val, Node *left, Node *right)
{
	Node *rv = (Node *)malloc(sizeof(*rv));
	rv->val = val;
	rv->left = left;
	rv->right = right;
	return rv;
}
Node* createBinaryTree(int val)
{
	Node *root = (Node *)malloc(sizeof(Node));
	root->val = val;
	root->left = NULL;
	root->right = NULL;

	return root;
}

void insertLeft(Node *root, int val)
{
	Node *newNode = createNode(val, NULL, NULL);

	if(root->left == NULL)
	{
		root->left = newNode;
	}
	else
	{
		newNode->left = root->left;
		root->left = newNode;
	}
}

void insertRight(Node *root, int val)
{
	Node *newNode = createNode(val, NULL, NULL);

	if(root->right == NULL)
	{
		root->right = newNode;
	}
	else
	{
		newNode->right = root->right;
		root->right = newNode;
	}
}

Node* copy(Node *root)
{
	if(root)
	{
		Node *rv = (Node *)malloc(sizeof(*rv));
		rv->left = copy(root->left);
		rv->right = copy(root->right);
		rv->val = root->val;
		return rv;
	}
	
	return NULL;
}

void preOrder(Node *root)
{
	printf("%c ", root->val);
	if(root->left) preOrder(root->left);
	if(root->right) preOrder(root->right);
}

void inOrder(Node *root)
{
	if(root->left) inOrder(root->left);
	printf("%c ", root->val);
	if(root->right) inOrder(root->right);
}

void postOrder(Node *root)
{
	if(root->left) postOrder(root->left);
	if(root->right) postOrder(root->right);
	printf("%c ", root->val);
}

void preOrderIter(Node *root)
{
	if(!root) return;

	stack<Node *> stk;
	stk.push(root);
	while(!stk.empty())
	{
		Node *curr = stk.top();
		stk.pop();
		printf("%c ", curr->val);
		if(curr->right) stk.push(curr->right);
		if(curr->left) stk.push(curr->left);
	}
}

void inOrderIter(Node *root)
{
	stack<Node *> stk;

	while(!stk.empty() || root != NULL)
	{
		if(root != NULL)
		{
			stk.push(root);
			root = root->left;
		}
		else
		{
			root = stk.top();
			stk.pop();
			printf("%c ", root->val);
			root = root->right;
		}
	}
}

void postOrderIter(Node *root)
{
	stack<Node *> stk;
	Node *prev = NULL;

	while(!stk.empty() || root!=NULL)
	{
		if(root != NULL)
		{
			stk.push(root);
			root = root->left;
		}
		else
		{
			Node *peek = stk.top();
			if(peek->right!=NULL && prev != peek->right)
			{
				root = peek->right;
			}
			else
			{
				printf("%c ", peek->val);
				prev = stk.top();
				stk.pop();
			}
		}
	}
}
void outOrder(Node *root)
{
	if(root->right) outOrder(root->right);
	printf("%c ", root->val);
	if(root->left) outOrder(root->left);
}

void bfs(Node *root)
{
	queue<Node *> q;
	q.push(root);

	while(!q.empty())
	{
		Node *curr = q.front();
		q.pop();
		printf("%c ", curr->val);

		if(curr->left) q.push(curr->left);
		if(curr->right) q.push(curr->right);
	}
}

void destroyTree(Node *root)
{
	if(root == NULL) return;
	if(root->left) destroyTree(root->left);
	if(root->right) destroyTree(root->right);
	free(root);
}
