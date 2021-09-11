#include <iostream>
using namespace std;

#include "Dijkstra.hpp"

int main() {
  const int V = 5;
  Graph g(V);
  g.insertEdge(1, 4, 3);
  g.insertEdge(1, 3, 6);
  g.insertEdge(2, 1, 3);
  g.insertEdge(3, 4, 2);
  g.insertEdge(4, 2, 1);
  g.insertEdge(4, 3, 1);
  g.insertEdge(5, 2, 4);
  g.insertEdge(5, 4, 2);

//  g.printGraph();

  for(int i=1; i<=V; ++i) {
    g.dijkstra(i);
    cout << endl;
  }
  return 0;
}
