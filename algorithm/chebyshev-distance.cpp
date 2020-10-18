#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); ++i) 
typedef long long ll;
typedef pair<int, int> p;

int chebyshevDistance(vector<int> x, vector<int> y)
{
  int chebyshev = 0;
  const int SIZE = x.size();

  for (int i=0; i<SIZE; ++i) 
  {
    int v = abs(x[i] - y[i]); 
    chebyshev = (v > chebyshev) ? v : chebyshev;
  }

  return chebyshev;
}

int main()
{
  vector<int> x {3, -1, -4, 1, -5, 9, 2, -6, 5, -3};
  vector<int> y {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  cout << chebyshevDistance(x, y) << endl;

  return 0;
}
