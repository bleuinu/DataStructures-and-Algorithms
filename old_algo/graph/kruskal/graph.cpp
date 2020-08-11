#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;

typedef int vertex;
typedef int weight;

class Edge
{
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
		int fi(int, int *);
		pair<int,int> uni(int, int, int *);

	public:
		Graph(int v) : V(v)
		{
			adjlist.resize(V);
		}
		~Graph() = default;

		void insertEdge(int s, int d, int w);
		void printGraph();
		void kruskal();
};

int Graph::fi(int x, int *uf)
{
	if(uf[x] == x) return x;

	return uf[x] = fi(uf[x], uf);
}

pair<int, int> Graph::uni(int a, int b, int *uf)
{
	int x = fi(a, uf);
	int y = fi(b, uf);

	uf[y] = x;
	return make_pair(x,y);
}

void Graph::kruskal()
{
	map<weight, pair<int,int>> mymap;

	// sort edges in increasing order
	for(int i=0; i<V; ++i)
	{
		for(auto it : adjlist[i])
		{
			auto it2 = mymap.find(it.w);
			if(it2 == mymap.end())
				mymap[it.w] = make_pair(i, it.v);
		}
	}

	// adding edges
	vector<pair<int, int>> k;
	int size = mymap.size();
	int cost = 0;
	int *uf = new (nothrow) int[size];

	for(int i=0; i<size; ++i)
		uf[i] = i;

	while(!mymap.empty())
	{
		// find the smallest edge
		auto it = mymap.begin();
		int v = (it->second).first;
		int w = (it->second).second;
		mymap.erase(it);

		// determine whether (v, w) creates cycle
		auto vals = uni(v, w, uf);
		
		// if not, add it to the set
		if(vals.first != vals.second)
		{
			k.push_back(make_pair(v,w));
			printf("(%d, %d [cost: %d])\n", v,w, it->first);
			cost += it->first;
		}
	}

	// print
	printf("Minimum cost: %d\n", cost);

	delete [] uf;
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

	cout << endl;
	cout << "Kruskal Algorithm" << endl;
	graph.kruskal();

	return 0;
}
