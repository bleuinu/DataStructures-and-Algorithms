#include <iostream>
#include <vector>

using namespace std;

typedef struct edge_t
{
	int src;
	int dest;
} Edge;

class Graph
{
	private:
		int V;
		vector<vector<int>> adjlist;

	public:
		Graph(vector<Edge> const &edges, int N);
		void printGraph(Graph const &graph);
};

Graph::Graph(vector<Edge> const &edges, int N)
{
	V = N;
	adjlist.resize(V);
	for(auto &edge : edges)
	{
		adjlist[edge.src].push_back(edge.dest);

		// undirected graph
		 adjlist[edge.dest].push_back(edge.src);
	}
}

void Graph::printGraph(Graph const &graph)
{
	for(int i=0; i<V; ++i)
	{
		cout << i << " --> ";

		for(int v : graph.adjlist[i])
		{
			cout << v << " ";
		}
		cout << endl;
	}
}

int main(void)
{
	vector<Edge> edges = 
	{
		{0,1}, {1,2}, {2,0},
		{3,2}, {4,5}
	};

	int N = 6;

	Graph graph(edges, N);

	graph.printGraph(graph);
	return 0;
}
