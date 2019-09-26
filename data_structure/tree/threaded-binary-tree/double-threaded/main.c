#include "doubletbt.h"

int main(void)
{
	// create a dummy root
	Node *tree = init();

#if 0
	tree = insertNode(tree, 6);
	tree = insertNode(tree, 8);
	tree = insertNode(tree, 3);
	tree = insertNode(tree, 5);
	tree = insertNode(tree, 1);
	tree = insertNode(tree, 11);
	tree = insertNode(tree, 7);
	tree = insertNode(tree, 9);
	tree = insertNode(tree, 13);
	tree = insertNode(tree, 20);
	tree = insertNode(tree, 16);
	tree = insertNode(tree, 18);
#endif
	tree = insertNode(tree, 1);
	tree = insertNode(tree, 2);
	tree = insertNode(tree, 4);
	tree = insertNode(tree, 10);
	tree = insertNode(tree, 12);
	tree = insertNode(tree, 13);
	tree = insertNode(tree, 15);

	inorder(tree);

	destroyTree(tree);

	return 0;
}
