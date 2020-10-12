#include <stdio.h>
#include <stdlib.h>

typedef struct node_t
{
	int vertex;
	struct node_t *next;
} Node;

typedef struct adjlist_t
{
	Node *head;
} AdjList;

typedef struct graph_t
{
	int V;
	AdjList *array;
} Graph;

Node* createNode(const int v)
{
	Node *rv = malloc(sizeof(*rv));
	rv->vertex = v;
	rv->next = NULL;

	return rv;
}

Graph* createGraph(const int V)
{
	Graph *graph = malloc(sizeof(*graph));
	graph->V = V;
	graph->array = malloc(V * sizeof(AdjList));

	for(int i=0; i<V; ++i)
	{
		graph->array[i].head = NULL;
	}

	return graph;
}

void addEdge(Graph *graph, const int src, const int dest, _Bool undirected)
{
	Node *newNode = createNode(dest);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;

	if(undirected)
	{
		newNode = createNode(src);
		newNode->next = graph->array[dest].head;
		graph->array[dest].head = newNode;
	}
}

void printGraph(Graph *graph)
{
	for(int i=0; i<graph->V; ++i)
	{
		Node *curr = graph->array[i].head;

		printf("%d: ", i);
		while(curr)
		{
			printf("%d ", curr->vertex);
			curr = curr->next;
		}
		printf("\n");
	}
}

void* destroyGraph(Graph *graph)
{
	for(int i=0; i<graph->V; ++i)
	{
		Node *curr = graph->array[i].head;
		while(curr)
		{
			Node *temp = curr;
			curr = curr->next;
			free(temp);
		}
	}

	free(graph->array);
	free(graph);

	return NULL;
}

int main(void)
{
	int V=4;
	Graph *graph = createGraph(V);
	_Bool bUndirected = 1;

	addEdge(graph, 0, 1, bUndirected);
	addEdge(graph, 0, 2, bUndirected);
	addEdge(graph, 1, 2, bUndirected);
	addEdge(graph, 1, 3, bUndirected);
	addEdge(graph, 2, 3, bUndirected);

	printGraph(graph);

	graph = destroyGraph(graph);

	return 0;
}
