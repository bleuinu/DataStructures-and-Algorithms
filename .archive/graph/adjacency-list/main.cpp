#include <iostream>
using namespace std;

#include "AdjacencyList.hpp"

#define UNDIRECTED 0

int main() {
  const int V = 6;
  vector<int> adj[V];

  addEdge(adj, 0, 2, UNDIRECTED); // A
  addEdge(adj, 1, 3, UNDIRECTED); // B
  addEdge(adj, 2, 1, UNDIRECTED); // C
  addEdge(adj, 2, 4, UNDIRECTED);
  addEdge(adj, 3, 2, UNDIRECTED); // D
  addEdge(adj, 5, 3, UNDIRECTED); // F
  addEdge(adj, 5, 4, UNDIRECTED);

  printGraph(adj, V);
  return 0;
}
