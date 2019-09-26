#include <iostream>
#include <vector>

using namespace std;

typedef struct edge_t
{
	int src;
	int dest;
	int weight;
} Edge;

typedef pair<int, int> Pair;

class Graph
{
	private:
		int V;
		vector<vector<Pair>> adjList;

	public:
		Graph(vector<Edge> const &edges, int N);
		void printGraph();
};

Graph::Graph(vector<Edge> const &edges, int N)
{
	V = N;
	adjList.resize(V);

	for(auto &edge : edges)
	{
		adjList[edge.src].push_back(make_pair(edge.dest, edge.weight));

		// undirected graph
//		adjList[edge.dest].push_back(make_pair(edge.src, edge.weight));
	}
}

void Graph::printGraph()
{
	for(int i=0; i<V; ++i)
	{
		for(Pair v : adjList[i])
		{
			cout << "(" << i << ", " << v.first << ", " << v.second << ") ";
		}
		cout << endl;
	}
}

int main(void)
{
	vector<Edge> edges =
	{
		// {src, dest, weight}
		{4,3,1},
		{3,2,4}, {3,1,3},
		{2,3,4},
		{0,2,7}, {0,4,2}, {0,3,10}
	};

	int N = 5;

	Graph graph(edges, N);

	graph.printGraph();

	return 0;
}
