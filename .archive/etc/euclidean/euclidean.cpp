#include <bits/stdc++.h>

using namespace std;

// euclidean
int gcd(int a, int b)
{
  if (a == 0) return b;
  return gcd(b % a, a);
}

// least common factor
int lcm(int a, int b) {
  return (a*b)/gcd(a, b);
}

int main() {
  int a = 35;
  int b = 5;
  cout << gcd(a, b) << endl;
  cout << lcm(a, b) << endl;

  return 0;
}

