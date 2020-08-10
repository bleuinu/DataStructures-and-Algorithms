#include "slinkedlist.h"

// public methods
SLinkedList* initializeList(void)
{
	SLinkedList *list = malloc(sizeof(*list));
	list->size = 0;
	list->dummy_head = createNode(0);
	list->dummy_tail = createNode(0);

	connectLink(list->dummy_head, list->dummy_tail);

	return list;
}

void pushFront(SLinkedList *list, elem data)
{
	Node *newNode = createNode(data);
	Node *temp = list->dummy_head->next;

	connectLink(list->dummy_head, newNode);
	connectLink(newNode, temp);
	
	++list->size;
}

void pushBack(SLinkedList *list, elem data)
{
	// locate the last node
	Node *lastNode = list->dummy_head;
	while(lastNode->next != list->dummy_tail)
	{
		lastNode = lastNode->next;
	}

	// add new node
	Node *newNode = createNode(data);
	connectLink(lastNode, newNode);
	connectLink(newNode, list->dummy_tail);

	++list->size;
}

void popFront(SLinkedList *list)
{
	if(list->size != 0)
	{
		Node *temp = list->dummy_head->next->next;
		free(list->dummy_head->next);
		connectLink(list->dummy_head, temp);
		--list->size;
	}
}

void popBack(SLinkedList *list)
{
	if(list->size != 0)
	{
		// locate the last node
		Node *lastNode = list->dummy_head;
		while(lastNode->next->next != list->dummy_tail)
		{
			lastNode = lastNode->next;
		}

		// remove the last node and reconnect links
		free(lastNode->next);
		connectLink(lastNode, list->dummy_tail);
		--list->size;
	}
}

void insertAt(SLinkedList *list, int pos, elem data)
{
	if(pos <= 0)
	{
		pushFront(list, data);
	}
	else if(pos > list->size)
	{
		pushBack(list, data);
	}
	else if(pos > 0 && pos <= list->size)
	{
		Node *temp = list->dummy_head;
		for(size_t i=0; i<pos; ++i)
		{
			temp = temp->next;
		}

		Node *newNode = createNode(data);
		connectLink(newNode, temp->next);
		connectLink(temp, newNode);

		++list->size;
	}
}

void removeAt(SLinkedList *list, int pos)
{
	if(pos <= 0)
	{
		popFront(list);
	}
	else if(pos > list->size)
	{
		popBack(list);
	}
	else
	{
		Node *prev = list->dummy_head;
		for(size_t i=0; i<pos-1; ++i)
		{
			prev = prev->next;
		}

		Node *temp = prev->next->next;
		free(prev->next);
		connectLink(prev, temp);
		--list->size;
	}
}

void destroy(SLinkedList *list)
{
	size_t size = list->size;

	for(int i = list->size; i>0; --i)
	{
		popFront(list);
	}

	free(list->dummy_head);
	free(list->dummy_tail);
	free(list);
}

void print(SLinkedList *list)
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
	temp->next = NULL;
	temp->data = data;
	return temp;
}

static inline void connectLink(Node *curr, Node *after)
{
	curr->next = after;
}

