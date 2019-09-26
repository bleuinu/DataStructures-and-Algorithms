#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <limits.h>

using namespace std;

#define INF 0x7FFFFFFF

typedef pair<int,int> Pair;

class Edge
{
	private:
	public:
		int dest;
		int weight;
		Edge(int _v, int _w) : dest(_v), weight(_w) {}
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
		void dijkstra(int src);
};

void Graph::insertEdge(int s, int d, int w)
{
	Edge dest(d, w);
	adjlist[s].push_back(dest);
	// undirected
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
			cout << "(" << i << ", " << e.dest << ", " << e.weight << ") -> ";
		}
		cout << endl;
	}
}

void Graph::dijkstra(int src)
{
	vector<int> dist(V, INF);
	dist[src] = 0;

	priority_queue<int> pq;
	pq.push(src);

	while(!pq.empty())
	{
		int r = pq.top();
		pq.pop();

		for(auto &v : adjlist[r])
		{
			int cost = dist[r] + v.weight;
			if(dist[v.dest] > cost)
			{
				dist[v.dest] = cost;
				pq.push(v.dest);
			}
		}
	}

	for(int i=0; i<V; ++i)
	{
		printf("v(0) to v(%d):    %d\n", i, dist[i]);
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

	printf("\n");
	printf("Dijkstra strating at src :%d\n", 0);
	graph.dijkstra(0);

	return 0;
}
