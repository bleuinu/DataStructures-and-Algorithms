#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Node
{
	public:
		T vertex;
		bool visited;
		vector<T> neighbors;

		Node(T v): vertex(v), visited(false) {}
};

template <class T>
class Graph
{
	private:
		int V = 0;
		vector<Node<T> > graph;

	public:
		void addVertex(int v);
		void addEdge(T src, T dest, bool undirected);
		void print();
		void dfs(T v);
		void bfs();
};

template <class T>
void Graph<T>::addVertex(int v)
{
	for(auto node : graph)
	{
		if(node.vertex == v)
		{
			return;
		}
	}

	Node<T> newNode(v);
	graph.push_back(v);
	++V;
}

template <class T>
void Graph<T>::addEdge(T src, T dest, bool undirected)
{
	int srcIndex = -1;
	int destIndex = -1;

	for(int i=0; i<V; ++i)
	{
		if(srcIndex == -1 && graph[i].vertex == src)
		{
			srcIndex = i;
		}
		else if(destIndex == -1 && graph[i].vertex == dest)
		{
			destIndex = i;
		}
	}

	if(srcIndex!=-1 && destIndex!=-1)
	{
		graph[srcIndex].neighbors.push_back(dest);
		if(undirected)
		{
			graph[destIndex].neighbors.push_back(src);
		}
	}
}

template <class T>
void Graph<T>::print()
{
	for(auto node : graph)
	{
		cout << node.vertex << ": ";

		for(auto n : node.neighbors)
		{
			cout << n << ' ';
		}

		cout << endl;
	}
}

int main()
{
	Graph<char> graph;

	graph.addVertex('A');
	graph.addVertex('B');
	graph.addVertex('C');
	graph.addVertex('D');

	graph.addEdge('A', 'B', false);
	graph.addEdge('A', 'C', false);
	graph.addEdge('B', 'C', false);
	graph.addEdge('B', 'D', false);
	graph.addEdge('C', 'D', false);
	graph.addEdge('D', 'E', false);

	graph.addVertex('E');
	graph.addEdge('E', 'D', false);
	graph.addEdge('D', 'E', false);

	graph.print();

	return 0;
}
