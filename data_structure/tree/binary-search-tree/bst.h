#include <stdio.h>
#include <stdlib.h>

typedef struct node_t
{
	int val;
	struct node_t *left;
	struct node_t *right;
} Node;

Node* createNode(int val)
{
	Node *rv = (Node *)malloc(sizeof(*rv));
	rv->val = val;
	rv->left = NULL;
	rv->right = NULL;

	return rv;
}

void insert(Node **root, int val)
{

	if(*root == NULL)
	{
		*root = createNode(val);
	}
	else if(val < (*root)->val)
	{
		insert(&((*root)->left), val);
	}
	else
	{
		insert(&((*root)->right), val);
	}
}

int findMinimum(Node *root)
{
	Node *temp = root;
	while(temp->left)
	{
		temp = temp->left;
	}
	
	return temp->val;
}

_Bool removeNode(Node *curr, Node *parent, int target)
{
	// find the node to removeNode
	if(target < curr->val && curr->left)
	{
		return removeNode(curr->left, curr, target);
	}
	else if(target < curr->val)
	{
		return 0;
	}
	else if(target > curr->val && curr->right)
	{
		return removeNode(curr->right, curr, target);
	}
	else if(target > curr->val)
	{
		return 0;
	}
	// target is found
	else 
	{
		// scenario 1: leaf node
		if(!curr->left && !curr->right)
		{
			if(curr == parent->left)
			{
				free(parent->left);
				parent->left = NULL;
			}
			else
			{
				free(parent->right);
				parent->right = NULL;
			}
		}
		// scenario 2: left child
		else if(curr->left && !curr->right)
		{
			if(curr == parent->left)
			{
				parent->left = curr->left;
				free(curr);
				curr = NULL;
			}
			else
			{
				parent->right = curr->left;
				free(curr);
				curr = NULL;
			}
		}
		// scenario 2: right child
		else if(!curr->left && curr->right)
		{
			if(curr == parent->left)
			{
				parent->left = curr->right;
				free(curr);
				curr = NULL;
			}
			else
			{
				parent->right = curr->right;
				free(curr);
				curr = NULL;
			}
		}
		// scenario 3: both child
		else
		{
			curr->val = findMinimum(curr->right);
			removeNode(curr->right, curr, curr->val);
		}

		return 1;
	}
}

_Bool search(Node *root, int target) 
{
	if(target > root->val && root->right)
	{
		return search(root->right, target);
	}
	if(target < root->val && root->left)
	{
		return search(root->left, target);
	}

	return root->val == target;
}

// print values in sorted order
void inOrder(Node *root)
{
	if(root == NULL) 
	{
		return;
	}

	if(root->left)
	{
		inOrder(root->left);
	}

	printf("%d ", root->val);

	if(root->right) 
	{
		inOrder(root->right);
	}
}

// print values in reversed order
void outOrder(Node *root)
{
	if(root->right)
	{
		outOrder(root->right);
	}

	printf("%d ", root->val);

	if(root->left)
	{
		outOrder(root->left);
	}
}

void destroyBST(Node *root)
{
	if(root->left) destroyBST(root->left);
	if(root->right) destroyBST(root->right);
	free(root);
}
