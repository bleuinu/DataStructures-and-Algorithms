## DFS
```c++
void Graph::DFS(int v)
{
	graph[v].visited = true;
	cout << v << ' ';

	vector<int> neighbors = graph[v].adjList;
	for(int v : neighbors)
	{
		if(graph[v].visited != true)
		{
			DFS(v);
		}
	}
}
```

## BFS
```c++
void Graph::BFS(int v)
{
	for(int i=0; i<V; ++i)
	{
		graph[i].visited = false;
	}

	queue<int> q;
	graph[v].visited = true;
	q.push(v);

	while(!q.empty())
	{
		int r = q.front();
		q.pop();
		cout << r << ' ';

		for(int neighbor : graph[r].adjList)
		{
			if(graph[neighbor].visited != true)
			{
				graph[neighbor].visited = true;
				q.push(neighbor);
			}
		}
	}

	cout << endl;
}
```
