#include <time.h>

#include "bst.h"

int main(void)
{
	unsigned seed = time(0);
	srand(seed);

	Node *bst = NULL;

	insert(&bst, 11);
	insert(&bst, 3);
	insert(&bst, 13);
	insert(&bst, 1);
	insert(&bst, 8);
	insert(&bst, 9);
	insert(&bst, 5);
	insert(&bst, 7);
	insert(&bst, 6);

	// print
	printf("%10s", "sorted: ");
	inOrder(bst);
	printf("\n");

	printf("%10s", "reversed: ");
	outOrder(bst);
	printf("\n\n");

	// search
	for(int i=0; i<10; ++i)
	{
		int target = rand() % 100;
		printf("searching for %2d in bst.......", target);
		printf("%s\n", (search(bst, target)) ? "found" : "not found");
	}

	printf("\n\n");

	removeNode(bst, bst, 8);
	inOrder(bst);
	printf("\n");

	removeNode(bst, bst, 17);
	inOrder(bst);
	printf("\n");

	removeNode(bst, bst, 15);
	inOrder(bst);
	printf("\n");

	destroyBST(bst);

	return 0;
}

