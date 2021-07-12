```cpp
void primeFactors(int n) {
  // Print all 2s
  while(n%2 == 0) {
    cout << 2 << ' ';
    n >>= 1;
  }

  // 'n' must be odd at this point
  for(int i=3; i*i<=n; i+=2) {
    while(n%i==0) {
      cout << i << ' ';
      n/=i;
    }
  }

  // print 'n' if 'n' == prime
  if(n > 2) cout << n;
  cout << endl;
}
```
