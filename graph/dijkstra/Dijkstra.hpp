#pragma once

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 0x7FFFFFFF
#define endl '\n'

typedef pair<int, int> PairII; // <dest, weight>

class Graph {
  private:
    int V;
    vector<vector<PairII>> adjlist;

  public:
    Graph(int v) : V(v) { adjlist.resize(V+1); }
    ~Graph() = default;

    void insertEdge(int src, int dest, int weight);
    void printGraph();
    void dijkstra(int src);
};

// directed graph - src -> (dest, weight)
void Graph::insertEdge(int src, int dest, int weight) {
  adjlist[src].push_back(make_pair(dest, weight));
}

void Graph::dijkstra(int src) {
  vector<int> dist(V, INF);
  dist[src] = 0;

  priority_queue<int> pq;
  pq.push(src);

  while(!pq.empty()) {
    int r = pq.top();
    pq.pop();

    for(auto &v : adjlist[r]) {
      // v.first = dest
      // v.second = weight
      int cost = dist[r] + v.second;
      if(dist[v.first] > cost) {
        dist[v.first] = cost;
        pq.push(v.first);
      }
    }
  }

  for(int i=1; i<=V; ++i) {
    printf("v(%d) to v(%d):     %d\n", src, i, dist[i]);
  }
}

void Graph::printGraph() {
  cout << "Print Graph" << endl;
  for(int i=0; i<V; ++i)
  {
    for(auto &e : adjlist[i])
    {
      cout << "(" << i << " -> " << e.first << ", " << e.second << ") ==> ";
    }
    cout << endl;
  }
}
