#include <stdio.h>

#include "binarytree.h"

int main(void)
{
	Node *root = createBinaryTree('a');

	// child of root
	insertLeft(root, 'b');
	insertRight(root, 'c');

	//child of b node
	insertRight(root->left, 'd');

	// child of c node
	insertLeft(root->right, 'e');
	insertRight(root->right, 'f');

	//print
	printf("%20s", "pre-order: ");
	preOrder(root);
	printf("\n");
	printf("%20s", "pre-order recur: ");
	preOrderIter(root);
	printf("\n");

	printf("%20s", "in-order: ");
	inOrder(root);
	printf("\n");
	printf("%20s", "in-order recur: ");
	inOrderIter(root);
	printf("\n");

	printf("%20s", "post-order: ");
	postOrder(root);
	printf("\n");
	printf("%20s", "post-order recur: ");
	postOrderIter(root);
	printf("\n");

	printf("%20s", "out-order: ");
	outOrder(root);
	printf("\n");

	printf("%20s", "bfs: ");
	bfs(root);
	printf("\n\n");

	printf("Copying bst....\n");
	Node *dup = copy(root);
	if(dup)
	{
		preOrder(dup);
		printf("\n");
		inOrder(dup);
		printf("\n");
		postOrder(dup);
		printf("\n");
	}
	
	destroyTree(root);
	destroyTree(dup);

	return 0;
}
