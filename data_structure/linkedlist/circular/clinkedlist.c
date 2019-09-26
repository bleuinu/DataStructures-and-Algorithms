#include "clinkedlist.h"

// public methods
CLinkedList* initializeList(void)
{
	CLinkedList *list = malloc(sizeof(*list));
	list->head = list->tail = NULL;
	list->size = 0;

	return list;
}

void pushFront(CLinkedList *list, elem data)
{
	Node *temp = createNode(data);

	if(list->head == NULL)
	{
		list->head = list->tail = temp;
		list->head->next = list->tail;
		list->tail->next = list->head;
	}
	else
	{
		temp->next = list->head;
		list->head = temp;
		list->tail->next = list->head;
	}
	++list->size;
}

void pushBack(CLinkedList *list, elem data)
{
	Node *temp = createNode(data);

	if(list->tail == NULL)
	{
		list->head = list->tail = temp;
		list->head->next = list->tail;
		list->tail->next = list->head;
	}
	else
	{
		list->tail->next = temp;
		temp->next = list->head;
		list->tail = temp;
	}

	++list->size;
}

void popFront(CLinkedList *list)
{
	Node *temp = list->head->next;
	free(list->head);
	list->tail->next = temp;
	list->head = temp;
	--list->size;
}

void popBack(CLinkedList *list)
{
	Node *temp = list->head;

	while(temp->next != list->tail)
	{
		temp = temp->next;
	}

	temp->next = list->head;
	free(list->tail);
	list->tail = temp;
	--list->size;
}

void insertAt(CLinkedList *list, int pos, elem data)
{
	if(pos <= 0)
	{
		pushFront(list, data);
	}
	else if(pos >= list->size)
	{
		pushBack(list, data);
	}
	else
	{
		Node *temp = list->head;
		for(int i = pos-1; i>0; --i)
		{
			temp = temp->next;
		}

		Node *newNode = createNode(data);
		newNode->next = temp->next;
		temp->next = newNode;
		++list->size;
	}
}

void removeAt(CLinkedList *list, int pos)
{
	if(pos <= 0)
	{
		popFront(list);
	}
	else if(pos >= list->size)
	{
		popBack(list);
	}
	else
	{
		Node *temp = list->head;
		for(int i = pos-1; i>0; --i)
		{
			temp = temp->next;
		}

		Node *remove = temp->next;
		temp->next = temp->next->next;
		free(remove);
		--list->size;
	}
}

void destroy(CLinkedList *list)
{
	for(size_t i=list->size; i>0; --i)
	{
		Node *temp = list->head->next;
		free(list->head);

		list->head = temp;
	}

	free(list);
}

void print(CLinkedList *list)
{
	Node *temp = list->head;

	for(size_t i = list->size-1; i>0; --i)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}

	printf("%d\n", temp->data);
}

// private methods
static Node* createNode(elem data)
{
	Node *temp = malloc(sizeof(*temp));
	temp->data = data;
	temp->next =  temp;
	return temp;
}
