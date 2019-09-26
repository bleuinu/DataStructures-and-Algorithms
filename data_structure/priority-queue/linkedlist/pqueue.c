#include "pqueue.h"

/* constructor */
Node* NewNode(const Element data, const int priority)
{
	Node *work = malloc(sizeof(*work));
	work->data = data;
	work->priority = priority;

	return work;
}

PQueue* NewPriorityQueue(void)
{
	PQueue *pq = malloc(sizeof(*pq));
	pq->head = NewNode(DATA, PRIORITY);
	pq->tail = NewNode(DATA, PRIORITY);
	pq->head->next = pq->tail;
	pq->tail->prev = pq->head;
	pq->size = 0;

	return pq;
}	

/* destructor */
void DestroyList(PQueue *pq)
{
	Node *head = pq->head->next;
	Node *end = pq->tail;

	while(head != end)
	{
		Node *temp = head->next;
		free(head);
		head = temp;
	}

	free(pq->head);
	free(end);
	free(pq);
}

/* list modifier */
void Push(PQueue *pq, const Element data, const int priority)
{
	Node *curr = pq->head->next;
	Node *end = pq->tail;

	for(; curr != end; curr = curr->next)
	{
		// highest priority comes first
		if(curr->priority < priority)
		{
			break;
		}
	}

	Node *work = NewNode(data, priority);
	ConnectNode(work, curr);
	pq->size++;
}

void Pop(PQueue *pq)
{
	if(pq->size > 0)
	{
		printf("deleting the last node..\n");
		Delete(pq, pq->tail->prev);
	}
}

void DeleteNthNode(PQueue *pq, int n)
{
	if(n <= 0 || n > pq->size)
	{
		fprintf(stderr, "out of bound...\n");
		return;
	}

	printf("deleting node #%d..\n", n);
	Node *work = pq->head->next;

	for(int i=0; i<n-1; ++i)
	{
		work = work->next;
	}

	Delete(pq, work);
}

/* list access */
void Print(const PQueue *pq)
{
	Node *beg = pq->head->next;
	Node *end = pq->tail;

	while(beg->next != end)
	{
		if(beg == end)
		{
			break;
		}

		printf("(%d, %d) -> ", beg->data, beg->priority);
		beg = beg->next;
	}
	printf("(%d, %d)\n", beg->data, beg->priority);
}

bool IsEmpty(const PQueue *pq)
{
	return pq->size == 0;
}

int GetSize(const PQueue *pq)
{
	return pq->size;
}

Element GetHighestPriority(const PQueue *pq)
{
	if(pq->size <= 0)
	{
		fprintf(stderr, "list is empty...\n");
		return -1;
	}

	return pq->head->next->data;
}

Element GetSmallestPriority(const PQueue *pq)
{
	if(pq->size <= 0)
	{
		fprintf(stderr, "list is empty...\n");
		return -1;
	}

	return pq->tail->prev->data;
}

/* helper functions */
static void ConnectNode(Node *work, Node *curr)
{
	curr->prev->next = work;
	work->prev = curr->prev;
	curr->prev = work;
	work->next = curr;
}

static void Delete(PQueue *pq, Node *remove)
{
	DisconnectNode(remove);
	free(remove);
	remove = NULL;
	pq->size--;
}

static void DisconnectNode(Node *curr)
{
	curr->prev->next = curr->next;
	curr->next->prev = curr->prev;
}
