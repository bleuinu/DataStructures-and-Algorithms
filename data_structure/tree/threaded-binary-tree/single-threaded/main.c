#include "singletbt.h"

int main(void)
{
	Node *stbt = NULL;

	stbt = insertNode(stbt, 6);
	stbt = insertNode(stbt, 8);
	stbt = insertNode(stbt, 3);
	stbt = insertNode(stbt, 5);
	stbt = insertNode(stbt, 1);
	stbt = insertNode(stbt, 11);
	stbt = insertNode(stbt, 7);
	stbt = insertNode(stbt, 9);
	stbt = insertNode(stbt, 13);
	stbt = insertNode(stbt, 20);
	stbt = insertNode(stbt, 16);
	stbt = insertNode(stbt, 18);

	inorder(stbt);

	destroyTree(stbt);

	return 0;
}
