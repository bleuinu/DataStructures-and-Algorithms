#include <iostream>
#include <queue>
using namespace std;

class BinaryTree;

class Node {
  private:
    int data;
    Node *left;
    Node *right;

  public:
    Node(int _data) : data(_data), left(nullptr), right(nullptr) {;}

    friend BinaryTree;
};

class BinaryTree {
  private:
    Node *root;
    int size;

  public:
    BinaryTree(void) : root(nullptr), size(0) {;}
    BinaryTree(int);
    ~BinaryTree(void);
    void deleteNode(Node *);

    void insertNode(int);

    void preorder(Node *);
    void inorder(Node *);
    void postorder(Node *);
    Node * getRoot(void) { return root; }
};

BinaryTree::BinaryTree(int data) {
  root = new Node(data);
  size = 1;
}

BinaryTree::~BinaryTree(void) {
  deleteNode(root);
}

void BinaryTree::deleteNode(Node *node) {
  if(!node) return;
  deleteNode(node->left);
  deleteNode(node->right);
  delete node;
}

void BinaryTree::insertNode(int data) {
  if(!root) root = new Node(data);
  else {
    queue<Node *> q;

    q.push(root);

    while(!q.empty()) {
      Node *temp = q.front();
      q.pop();

      if(temp->left) {
        q.push(temp->left);
      } else {
        temp->left = new Node(data);
        ++size;
        return;
      }

      if(temp->right) {
        q.push(temp->right);
      } else {
        temp->right = new Node(data);
        ++size;
        return;
      }
    }
  }
}

void BinaryTree::inorder(Node *node) {
  if(node) {
    inorder(node->left);
    cout << node->data << ' ';
    inorder(node->right);
  }
}

void BinaryTree::preorder(Node *node) {
  if(node) {
    cout << node->data << ' ';
    preorder(node->left);
    preorder(node->right);
  }
}

void BinaryTree::postorder(Node *node) {
  if(node) {
    postorder(node->left);
    postorder(node->right);
    cout << node->data << ' ';
  }
}
