#include "dlinkedlist.h"

// public methods
DLinkedList* initializeList(void)
{
	DLinkedList *list = malloc(sizeof(*list));
	list->size = 0;
	list->dummy_head = createNode(0);
	list->dummy_tail = createNode(0);

	connectLink(list->dummy_head, list->dummy_tail);

	return list;
}

void pushFront(DLinkedList *list, elem data)
{
	Node *newNode = createNode(data);

	connectLink(newNode, list->dummy_head->next);
	connectLink(list->dummy_head, newNode);
	
	++list->size;
}

void pushBack(DLinkedList *list, elem data)
{
	// add new node
	Node *lastNode = list->dummy_tail->prev;
	Node *newNode = createNode(data);
	connectLink(lastNode, newNode);
	connectLink(newNode, list->dummy_tail);

	++list->size;
}

void popFront(DLinkedList *list)
{
	if(list->size != 0)
	{
		Node *temp = list->dummy_head->next;
		free(list->dummy_head);
		temp->prev = NULL;
		list->dummy_head = temp;

		--list->size;
	}
}

void popBack(DLinkedList *list)
{
	if(list->size != 0)
	{
		// remove the last node and reconnect links
		Node *temp = list->dummy_tail->prev;
		free(list->dummy_tail);
		temp->next = NULL;
		list->dummy_tail = temp;

		--list->size;
	}
}

void insertAt(DLinkedList *list, int pos, elem data)
{
	if(pos <= 1)
	{
		pushFront(list, data);
	}
	else if(pos > list->size)
	{
		pushBack(list, data);
	}
	else if(pos > 0 && pos <= list->size)
	{
		Node *newNode = createNode(data);
		Node *temp = list->dummy_head;

		while(--pos)
		{
			temp = temp->next;
		}

		connectLink(newNode, temp->next);
		connectLink(temp, newNode);
		++list->size;
	}
}

void removeAt(DLinkedList *list, int pos)
{
	if(pos <= 1)
	{
		popFront(list);
	}
	else if(pos > list->size)
	{
		popBack(list);
	}
	else
	{
		Node *temp = list->dummy_head;
		while(pos--)
		{
			temp = temp->next;
		}

		connectLink(temp->prev, temp->next);
		free(temp);

		--list->size;
	}
}

void destroy(DLinkedList *list)
{
	size_t size = list->size;
	while(size--)
	{
		popFront(list);
	}

	free(list->dummy_head);
	free(list->dummy_tail);
	free(list);
}

void print(DLinkedList *list)
{
	Node *temp = list->dummy_head->next;
	while(temp != list->dummy_tail)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}

	printf("\n");
}

// private methods
static Node* createNode(elem data)
{
	Node *temp = malloc(sizeof(*temp));
	temp->next = temp->prev = NULL;
	temp->data = data;
	return temp;
}

static inline void connectLink(Node *curr, Node *after)
{
	curr->next = after;
	after->prev = curr;
}

