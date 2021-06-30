#include <iostream>
using namespace std;

#include "morris-traversal.hpp"

int main(void) {
  BinaryTree tree(10);
  tree.insertNode(20);
  tree.insertNode(30);
  tree.insertNode(40);
  tree.insertNode(55);
  tree.insertNode(70);

  tree.preorder(tree.getRoot()); cout << endl;
  tree.morrisTraversalPreorder(tree.getRoot()); cout << endl;

  tree.deleteNode();
  tree.preorder(tree.getRoot()); cout << endl;
  tree.morrisTraversalPreorder(tree.getRoot()); cout << endl;
  tree.deleteNode();
  tree.preorder(tree.getRoot()); cout << endl;
  tree.morrisTraversalPreorder(tree.getRoot()); cout << endl;
  return 0;
}
