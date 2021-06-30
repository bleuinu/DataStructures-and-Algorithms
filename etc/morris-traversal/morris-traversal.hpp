#include <iostream>
#include <stack>
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

    void destructorHelper(Node *);

  public:
    BinaryTree(void) : root(nullptr), size(0) {;}
    BinaryTree(int);
    ~BinaryTree(void);

    void insertNode(int);
    void deleteNode();

    void morrisTraversalPreorder(Node *);
    void preorder(Node *);

    Node* getRoot(void) { return root; }
};

BinaryTree::BinaryTree(int data) {
  root = new Node(data);
  size = 1;
}

BinaryTree::~BinaryTree(void) {
  destructorHelper(root);
}

void BinaryTree::destructorHelper(Node *node) {
  if(!node) return;
  destructorHelper(node->left);
  destructorHelper(node->right);
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

void BinaryTree::deleteNode(void) {
  if(!root) {
    cout << "Empty tree...." << endl;
    return;
  }
  
  if(root->left == nullptr && root->right == nullptr) {
    delete root;
    root = nullptr;
    cout << "delete root" << endl;
    return;
  }

  Node *lastLevelLevelOrder = nullptr;
  Node *parentOfLastNode = nullptr;
  queue<Node *> q;
  q.push(root);

  while(!q.empty()) {
    Node *temp = q.front();
    q.pop();

    if(temp->left) {
      q.push(temp->left);

      if(temp->left->left == nullptr && temp->left->right == nullptr) {
        lastLevelLevelOrder = temp->left;
        parentOfLastNode = temp;
      }
    }

    if(temp->right) {
      q.push(temp->right);
      if(temp->right->left == nullptr && temp->right->right == nullptr) {
        lastLevelLevelOrder = temp->right;
        parentOfLastNode = temp;
      }
    }
  }

  if(lastLevelLevelOrder && parentOfLastNode) {
    if(parentOfLastNode->right) {
      delete parentOfLastNode->right;
      parentOfLastNode->right = nullptr;
    } else {
      delete parentOfLastNode->left;
      parentOfLastNode->left = nullptr;
    }
  } else {
    cout << "Empty Tree" << endl;
  }
}

void BinaryTree::preorder(Node *node) {
  if(node) {
    cout << node->data << ' ';
    preorder(node->left);
    preorder(node->right);
  }
}

/*
 * If current does not have left child
 *   a. Add current’s value
 *   b. Go to the right, i.e., current = current.right
 * Else
 *  a. In current's left subtree, make current the right child of the rightmost node
 *  b. Go to this left child, i.e., current = current.left 
 *
 * ref: https://leetcode.com/problems/binary-tree-inorder-traversal/solution 
 * */
void BinaryTree::morrisTraversalPreorder(Node* node) {
  while(node != nullptr) {
    if(node->left == nullptr) {
      cout << node->data << ' ';
      node = node->right;
    } else {
      Node *curr = node->left;
      while(curr->right && curr->right != node) curr = curr->right;

      if(curr->right == node) {
        curr->right = nullptr;
        node = node->right;
      } else {
      cout << node->data << ' ';
        curr->right = node;
        node = node->left;
      }
    }
  }
}
