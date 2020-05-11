#include <stdio.h>
#include <stdlib.h>

typedef struct graph_t
{
	int V;
	int **array;
} Graph;

Graph* createGraph(const int V)
{
	Graph *graph = malloc(sizeof(*graph));
	graph->V = V;
	graph->array = malloc(V * sizeof(int *));
	for(int i=0; i<V; ++i)
	{
		graph->array[i] = malloc(V * sizeof(int));
	}

	for(int i=0; i<V; ++i)
	{
		for(int j=0; j<V; ++j)
		{
			graph->array[j][i] = -1;
		}
	}

	return graph;
}

void addEdge(Graph *graph, const int src, const int dest, _Bool undirected)
{
	graph->array[src][dest] = 1;
	if(undirected)
	{
		graph->array[dest][src] = 1;
	}
}

void printGraph(Graph *graph)
{
	for(int i=0; i<graph->V; ++i)
	{
		printf("%d: ", i);
		for(int j=0; j<graph->V; ++j)
		{
			if(graph->array[i][j] > 0)
			{
				printf("%d ", j);
			}
		}
		printf("\n");
	}
}

void* destroyGraph(Graph *graph)
{
	for(int i=0; i<graph->V; ++i)
	{
		free(graph->array[i]);
	}
	free(graph->array);
	free(graph);

	return NULL;
}

int main(void)
{
	int V=4;
	Graph *graph = createGraph(V);
	_Bool bUndirected = 0;

	addEdge(graph, 0, 1, bUndirected);
	addEdge(graph, 0, 2, bUndirected);
	addEdge(graph, 1, 2, bUndirected);
	addEdge(graph, 1, 3, bUndirected);
	addEdge(graph, 2, 3, bUndirected);

	printGraph(graph);

	graph = destroyGraph(graph);

	return 0;
}
