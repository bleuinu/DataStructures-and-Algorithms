#include <iostream> 
using namespace std;

#define V 6
#define UNDIRECTED 1

void addEdge(int adj[][V], int u, int v, bool isUndirected) {
  adj[u][v] = 1;
  if(isUndirected)
    adj[v][u] = 1;
}

void printGraph(int adj[][V]) {
  for(int i=0; i<V; ++i) {
    printf("Adjacency Matrix : Vertex %c\n", 65 + i);
    printf("%c ", 65+i);

    for(int j=0; j<V; ++j) {
      if(adj[i][j])
        printf("-> %c ", 65 + j);
    }
    printf("\n");
  }
}

int main() {
  int adj[V][V] = {0};

  addEdge(adj, 0, 2, UNDIRECTED); // A
  addEdge(adj, 1, 3, UNDIRECTED); // B
  addEdge(adj, 2, 1, UNDIRECTED); // C
  addEdge(adj, 2, 4, UNDIRECTED);
  addEdge(adj, 3, 2, UNDIRECTED); // D
  addEdge(adj, 5, 3, UNDIRECTED); // F
  addEdge(adj, 5, 4, UNDIRECTED);

  printGraph(adj);
  return 0;
}
