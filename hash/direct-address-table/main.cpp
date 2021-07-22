#include <iostream> 
#include <cstdlib>
#include <ctime>

#include "dat.hpp"

using namespace std;

int main() {
  unsigned seed = time(0);
  srand(seed);

  DAT dat;
  for(int i=0; i<5; ++i) {
    int val = rand() % 10;
    cout << "Insert " << val << "!!" << endl;
    dat.insert(val);
  }

  for(int i=0; i<10; ++i) {
    int target = rand() % 10; 
    if(dat.search(target)) 
      cout << target << " found!" << endl;
    else 
      cout << target << " NOT found!" << endl;
  }
  cout << dat.search(7) << endl;

  return 0;
}
