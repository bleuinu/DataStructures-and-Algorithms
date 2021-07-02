#include <bits/stdc++.h>
using namespace std;

void eratosthenes(int n) {
  vector<int> sieve(n+1, true);
  sieve[0] = sieve[1] = false;
  int cnt = 0;

  for(int i=2; i<=n; ++i) {
    if(!sieve[i]) continue;

    for(int j=i+i;j<=n;j+=i) {
      sieve[j] = false;
    }
  }
}
