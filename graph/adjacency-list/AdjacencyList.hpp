#include <iostream>
#include <vector>
using namespace std;

// directed and undirected  graph
void addEdge(vector<int> adj[], int u, int v, bool isUndirected) {
  adj[u].push_back(v);
  if(isUndirected)
    adj[v].push_back(u);
}

// a utility func to print the adj list 
void printGraph(vector<int> adj[], const int V) {
  for(int v=0; v<V; ++v) {
    printf("\nAdjacency list of vertex %c\nhead ", v+65);
    for(auto x : adj[v]) 
      printf("-> %c", x+65);
    cout << endl;
  }
}
