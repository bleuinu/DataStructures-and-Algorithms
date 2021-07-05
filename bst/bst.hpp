#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class BST;

class Node {
  private:
    int data;
    Node *left;
    Node *right;

  public:
    Node(int _data) : data(_data), left(nullptr), right(nullptr) {;}

    friend BST;
};

class BST {
  private:
    Node *root;
    int size;

    void destructorHelper(Node *);
    void _preorder(Node *);
    void _inorder(Node *);
    void _postorder(Node *);
    void insertHelper(Node *, int);

  public:
    BST(void) : root(nullptr), size(0) {;}
    BST(int);
    ~BST(void);

    void insert(int);
    bool search(int);
    void remove();

    void preorder(void) { cout<<"Preorder\n"; _preorder(root); }
    void inorder(void) { cout<<"Inorder\n"; _inorder(root); }
    void postorder(void) { cout<<"Postorder\n"; _postorder(root); }
};

BST::BST(int data) {
  root = new Node(data);
  size = 1;
}

BST::~BST(void) {
  destructorHelper(root);
}

void BST::destructorHelper(Node *node) {
  if(!node) return;
  destructorHelper(node->left);
  destructorHelper(node->right);
  delete node;
}

void BST::insert(int data) {
  if(!root) {
    root = new Node(data);
    return;
  }

  insertHelper(root, data);
}

void BST::insertHelper(Node *node, int data) {
  if(data < node->data) {
    if(node->left) {
      insertHelper(node->left, data);
    } else {
      node->left = new Node(data);
      return;
    }
  }
  else {
    if(node->right) {
      insertHelper(node->right, data);
    } else {
      node->right = new Node(data);
      return;
    }
  }
}

bool BST::search(int data) {
  if(root->data == data) return true;

  Node *temp = root;
  while(temp->data != data) {
    if(data < temp->data) 
      temp = temp->left;
    else 
      temp = temp->right;

    if(!temp) return false;
  }

  return true;
}


void BST::remove(void) {
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

void BST::_inorder(Node *node) {
  if(node) {
    _inorder(node->left);
    cout << node->data << ' ';
    _inorder(node->right);
  }
}

void BST::_preorder(Node *node) {
  if(node) {
    cout << node->data << ' ';
    _preorder(node->left);
    _preorder(node->right);
  }
}

void BST::_postorder(Node *node) {
  if(node) {
    _postorder(node->left);
    _postorder(node->right);
    cout << node->data << ' ';
  }
}
