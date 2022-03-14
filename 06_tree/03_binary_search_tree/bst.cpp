#include <queue>
#include <iostream>

using namespace std;

class Node {
    private: 
        int data;
        Node *left;
        Node *right;
        friend class BST;

    public:
        Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BST {
    private:
        Node *root;

    public:
        BST() : root(nullptr) {;}
        ~BST() = default;

        void insert(int);
        bool search(Node *, int);
        Node* insert(Node *, int);
        void inorder(Node *);
        void preorder(Node *);
        void postorder(Node *);

        Node* getRoot() { return root; }

        void printLevelOrder();
};

void BST::insert(int data) {
    if(root == nullptr) {
        root = new Node(data);
        return;
    }

    Node *curr = root;
    queue<Node *> q;
    q.push(curr);

    while(!q.empty()) {
        Node *temp = q.front();
        q.pop();

        if(data < temp->data) {
            if(temp->left) {
                q.push(temp->left);
            } else {
                temp->left = new Node(data);
                return;
            }
        } else {
            if(temp->right) {
                q.push(temp->right);
            } else {
                temp->right = new Node(data);
                return;
            }
        }
    }
}

Node* BST::insert(Node *node, int data) {
    if(!node) return new Node(data);

    if(data < node->data)
        node->left = insert(node->left, data);
    else if(data > node->data) 
        node->right = insert(node->right, data);

    return node;
}

bool BST::search(Node *node, int data) {
    if(!node) return false;

    if(node->data == data) 
        return true;
    else if(data > node->data)
        return search(node->right, data);
    else 
        return search(node->left, data);

    return false;
}

void BST::preorder(Node *node) {
    if(!node) return;

    cout << node->data << ' ';
    preorder(node->left);
    preorder(node->right);
}

void BST::inorder(Node *node) {
    if(!node) return;

    inorder(node->left);
    cout << node->data << ' ';
    inorder(node->right);
}

void BST::postorder(Node *node) {
    if(!node) return;

    postorder(node->left);
    postorder(node->right);
    cout << node->data << ' ';
}

void BST::printLevelOrder() {
    queue<Node *> q;
    Node *temp = root;
    q.push(temp);

    while(!q.empty()) {
        Node *curr = q.front();
        q.pop();

        cout << curr->data << ' ';
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
    cout << endl;
}

int main(void) {
    BST bst;
    bst.insert(8);
    bst.insert(bst.getRoot(), 3);
    bst.insert(10);
    bst.insert(bst.getRoot(), 1);
    bst.insert(6);
    bst.insert(14);
    bst.insert(bst.getRoot(), 4);
    bst.insert(7);
    bst.insert(bst.getRoot(), 13);

    bst.preorder(bst.getRoot());
    cout << endl;
    bst.inorder(bst.getRoot());
    cout << endl;
    bst.postorder(bst.getRoot());
    cout << endl;
    bst.printLevelOrder();

    cout << endl;
    cout << "is 5 in BST? " << bst.search(bst.getRoot(), 5) << endl;
    cout << "is 7 in BST? " << bst.search(bst.getRoot(), 7) << endl;
    cout << "is 14 in BST? " << bst.search(bst.getRoot(), 14) << endl;
    
    return 0;
}