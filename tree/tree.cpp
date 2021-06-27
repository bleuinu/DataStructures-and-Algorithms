#include <iostream>
using namespace std;

class Node {
  private:
  public:
    int data;
    Node *left;
    Node *right;

    Node(int _data) : data(_data), left(nullptr), right(nullptr) {;} 

    void preorder(Node *root) {
      if(!root) return;
      cout << root->data << ' ';
      preorder(root->left);
      preorder(root->right);
    }
};

int main() {
  Node *root = new Node(10);
  root->left = new Node(20);
  root->right = new Node(30);
  root->right->left = new Node(55);
  root->right->right = new Node(70);
  root->left->left = new Node(40);
  root->preorder(root);

  return 0;
}
