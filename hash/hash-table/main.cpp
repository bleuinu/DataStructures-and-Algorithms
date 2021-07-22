#include <iostream> 
#include <cstdlib>
#include <ctime>

#include "hashtable.hpp"

using namespace std;

int main() {
  unsigned seed = time(0);
  srand(seed);

  HashTable hashtbl;
  for(int i=0; i<5; ++i) {
    int val = rand() % 100 + 15;
    cout << "Insert " << val << "!!" << endl;
    hashtbl.insert(val);
  }

  for(int i=0; i<10; ++i) {
    int target = rand() % 100 + 15; 
    if(hashtbl.search(target))
      cout << target << " found!" << endl;
    else 
      cout << target << " NOT found!" << endl;
  }

  return 0;
}
