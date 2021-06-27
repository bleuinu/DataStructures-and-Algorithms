#include <iostream>
using namespace std;

#include "binarytree.hpp"

int main(void) {
  BinaryTree tree(10);
  tree.insertNode(20);
  tree.insertNode(30);
  tree.insertNode(40);
  tree.insertNode(55);
  tree.insertNode(70);

  Node *root = tree.getRoot();
  tree.preorder(root); cout << endl;
  tree.inorder(root); cout << endl;
  tree.postorder(root); cout << endl;

  return 0;
}
