#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <limits.h>

using namespace std;

#define INF 0x3f3f3f3f
typedef pair<int,int> Pair;
typedef int vertex;
typedef int weight;

class Edge
{
	private:
	public:
		vertex v;
		weight w;
		Edge(vertex _v, weight _w) : v(_v), w(_w) {}
};

class Graph
{
	private:
		int V;
		vector<vector<Edge>> adjlist;

	public:
		Graph(int v) : V(v)
		{
			adjlist.resize(V);
		}
		~Graph() = default;

		void insertEdge(int s, int d, int w);
		void printGraph();
		void prim(int src);
};

void Graph::prim(int src)
{
	// <weight, src>
	priority_queue<Pair, vector<Pair>, std::greater<Pair> > pq;
	vector<bool> visited(V, false);
	vector<int> mst;
	int cost = 0;

	pq.push(make_pair(0, src));
	while(!pq.empty() && mst.size() != V-1)
	{
		int c = pq.top().first;
		int u = pq.top().second;
		pq.pop();

		if(visited[u] == false)
		{
			mst.push_back(u);
			cost += c;

			// iterate through all neighbors
			for(auto neighbor : adjlist[u])
			{
				if(visited[neighbor.v] == false)
				{
					pq.push(make_pair(neighbor.w, neighbor.v));
				}
			}
		}

		visited[u] = true;
	}

	for(int i : mst)
		printf("%d ", i);
	printf("\ncost: %d\n", cost);
}

void Graph::insertEdge(int s, int d, int w)
{
	Edge dest(d, w);
	adjlist[s].push_back(dest);
	Edge src(s, w);
	adjlist[d].push_back(src);
}

void Graph::printGraph()
{
	cout << "Print Graph \n";
	for(int i=0; i<V; ++i)
	{
		for(Edge e : adjlist[i])
		{
			cout << "(" << i << ", " << e.v << ", " << e.w << ") -> ";
		}
		cout << endl;
	}
}

int main()
{
	int size;
	cin >> size;
	Graph graph(size+1);

	while(true)
	{
		int src, dest, weight;
		cin >> src >> dest >> weight;
		if(src == -1) break;
		graph.insertEdge(src, dest, weight);
	}

	graph.printGraph();

	for(int i=1; i<size; ++i)
	{
		cout << endl << "Prim's Algorithm; src = " << i << endl;
		graph.prim(i);
	}
	return 0;
}
