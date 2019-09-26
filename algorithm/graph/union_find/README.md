## Union and Find
```c++
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
```
