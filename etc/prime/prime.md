```cpp
#include <iostream> 
using std::cout;
using std::endl;

bool isPrime(int n) {
  if(n<2) return 0;
  if(n<=3) return 1;

  if(n%2 == 0 || n%3 == 0) return 0;

  for(int i=5; (i*i) <= n; i+=6) 
    if(n%i==0 || n%(i+2)==0) return 0;

  return 1;
}

int main() {
  for(int i=2; i<100; ++i) {
    if(isPrime(i)) cout << i << ' ';
  }
  cout << endl;

  return 0;
}
```
