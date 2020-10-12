#include <time.h>

#include "dlinkedlist.h"

int main(void)
{
	unsigned seed = time(0);
	srand(seed);

	printf("initializing list\n");
	DLinkedList *list = initializeList();
	printf("push front 5 data:\n");
	for(int i=0; i<5; ++i)
	{
		pushFront(list, rand() % 100);
		print(list);
	}
	printf("\npush back 5 data:\n");
	for(int i=0; i<5; ++i)
	{
		pushBack(list, rand() % 100);
		print(list);
	}
	printf("\n");

	printf("pop front\n");
	popFront(list);
	print(list);
	printf("pop back\n");
	popBack(list);
	print(list);
	printf("\n");

	printf("destroy list\n");
	destroy(list);
	list = NULL;

	printf("\n-----------------------------\n");
	printf("initializing list\n");
	list = initializeList();

	printf("push front 5\n");
	pushFront(list, 5);
	print(list);

	printf("insert 2 at pos 0\n");
	insertAt(list, 0, 2);
	print(list);

	printf("insert 7 at pos 1\n");
	insertAt(list, 1, 7);
	print(list);

	printf("insert 1 at pos 2\n");
	insertAt(list, 1, 1);
	print(list);

	printf("insert 10 at pos 3\n");
	insertAt(list, 3, 10);
	print(list);

	printf("insert 8 at pos -1\n");
	insertAt(list, -1, 8);
	print(list);

	printf("pop front\n");
	popFront(list);
	print(list);

	printf("insert 100 at pos 27\n");
	insertAt(list, 27, 100);
	print(list);

	printf("pop back\n");
	popBack(list);
	print(list);

	printf("removeAt 2 \n");
	removeAt(list, 2);
	print(list);

	printf("removeAt 0 \n");
	removeAt(list, 0);
	print(list);

	printf("destroy list\n");
	destroy(list);
	return 0;
}
