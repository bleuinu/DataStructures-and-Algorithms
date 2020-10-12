#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct node_t
{
	bool visited;
	vector<int> adjList;
} Node;

typedef struct edge_t
{
	int src;
	int dest;
} Edge;

class Graph
{
	private:
		int V;
		vector<Node> graph;

	public:
		Graph(vector<Edge> const &edges, int N);
		void printGraph();
		void DFS(int v);
		void BFS(int v);
};

Graph::Graph(vector<Edge> const &edges, int N)
{
	V = N;
	graph.resize(V);
	for(auto &edge : edges)
	{
		graph[edge.src].adjList.push_back(edge.dest);

		// undirected graph
		 graph[edge.dest].adjList.push_back(edge.src);
	}
}

void Graph::printGraph()
{
	for(int i=0; i<V; ++i)
	{
		cout << i << " --> ";

		for(int v : graph[i].adjList)
		{
			cout << v << " ";
		}
		cout << endl;
	}
}

void Graph::DFS(int v)
{
	graph[v].visited = true;
	cout << v << ' ';

	vector<int> neighbors = graph[v].adjList;
	for(int v : neighbors)
	{
		if(graph[v].visited != true)
		{
			DFS(v);
		}
	}
}

void Graph::BFS(int v)
{
	for(int i=0; i<V; ++i)
	{
		graph[i].visited = false;
	}

	queue<int> q;
	graph[v].visited = true;
	q.push(v);

	while(!q.empty())
	{
		int r = q.front();
		q.pop();
		cout << r << ' ';

		for(int neighbor : graph[r].adjList)
		{
			if(graph[neighbor].visited != true)
			{
				graph[neighbor].visited = true;
				q.push(neighbor);
			}
		}
	}

	cout << endl;
}

int main(void)
{
	vector<Edge> edges = 
	{
		{0,1}, {0,2}, {0,3},
		{1,4}, {1,5},
		{2,6},
	};

	int N = 9;

	Graph graph(edges, N);

	graph.printGraph();
	cout << endl;

	int dfs = 0;
	int bfs = 0;
	cout << "DFS from " << dfs << endl;
	graph.DFS(dfs);
	cout << endl;
	cout << "BFS from " << bfs << endl;
	graph.BFS(bfs);

	return 0;
}
