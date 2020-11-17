#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); ++i) 
typedef long long ll;
typedef pair<int, int> p;

double euclideanDistance(vector<int> x, vector<int> y)
{
  int distance = 0;
  const int SIZE = x.size();

  for (int i=0; i<SIZE; ++i) 
  {
    int t = x[i] - y[i];
    distance += (t * t);
  }

  return sqrt(distance);
}

int main()
{
  vector<int> x {-1, 2, 3};
  vector<int> y {4, 0, -3};
  cout << euclideanDistance(x, y) << endl;

  return 0;
}
