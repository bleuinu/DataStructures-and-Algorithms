#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "bst.hpp"

#define NUM 50

int main(void) {
  BST tree;
  unsigned seed = time(0);
  srand(seed);

  for(int i=0; i<10; ++i) {
    int data = rand() % NUM + 1;
    cout << "INSERT " << data << endl;
    tree.insert(rand() % NUM); 
  }

  cout << endl;
  tree.preorder(); cout << endl;
  tree.inorder(); cout << endl;
  tree.postorder(); cout << endl;
  cout << endl;

  for(int i=0; i<10; ++i) {
    int data = rand() % NUM + 1;
    cout << "Search for " << data << endl;
    if(tree.search(data)) 
      cout << "-------------------- " << data << " found.\n";
    else 
      cout << "---------" << data << " NOT found.\n";
  }
  return 0;
}
