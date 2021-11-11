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

  cout << "Preorder:" << endl;
  tree.preorder(tree.getRoot()); cout << endl;
  cout << "Preorder - Morris traversal:" << endl;
  tree.morrisTraversalPreorder(tree.getRoot()); cout << endl;
  cout << "Inorder:" << endl;
  tree.inorder(tree.getRoot()); cout << endl;
  cout << "Inorder: Morris traversal" << endl;
  tree.morrisTraversalInorder(tree.getRoot()); cout << endl;

  cout << endl << endl;

  tree.deleteNode();
  tree.preorder(tree.getRoot()); cout << endl;
  tree.morrisTraversalPreorder(tree.getRoot()); cout << endl;
  tree.inorder(tree.getRoot()); cout << endl;
  tree.morrisTraversalInorder(tree.getRoot()); cout << endl;

  cout << endl << endl;

  tree.deleteNode();
  tree.preorder(tree.getRoot()); cout << endl;
  tree.morrisTraversalPreorder(tree.getRoot()); cout << endl;
  tree.inorder(tree.getRoot()); cout << endl;
  tree.morrisTraversalInorder(tree.getRoot()); cout << endl;
  return 0;
}
