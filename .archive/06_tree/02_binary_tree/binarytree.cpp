#include <queue>
#include <iostream>

using namespace std;

class Node {
    private: 
        int data;
        Node *left;
        Node *right;
        friend class BinaryTree;

    public:
        Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BinaryTree {
    private:
        Node *root;

    public:
        BinaryTree() : root(nullptr) {;}
        ~BinaryTree() = default;

        void insert(int);
        void inorder(Node *);
        void preorder(Node *);
        void postorder(Node *);

        Node* getRoot() { return root; }

        void printLevelOrder();
};

void BinaryTree::insert(int data) {
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

        if(temp->left) {
            q.push(temp->left);
        } else {
            temp->left = new Node(data);
            return;
        }

        if(temp->right) {
            q.push(temp->right);
        } else {
            temp->right = new Node(data);
            return;
        }
    }
}

void BinaryTree::preorder(Node *node) {
    if(!node) return;

    cout << node->data << ' ';
    preorder(node->left);
    preorder(node->right);
}

void BinaryTree::inorder(Node *node) {
    if(!node) return;

    inorder(node->left);
    cout << node->data << ' ';
    inorder(node->right);
}

void BinaryTree::postorder(Node *node) {
    if(!node) return;

    postorder(node->left);
    postorder(node->right);
    cout << node->data << ' ';
}

void BinaryTree::printLevelOrder() {
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
    BinaryTree bt;
    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);

    cout << "Preorder: ";
    bt.preorder(bt.getRoot());
    cout << endl;

    cout << "Inorder: ";
    bt.inorder(bt.getRoot());
    cout << endl;
    
    cout << "Postorder: ";
    bt.postorder(bt.getRoot());
    cout << endl;

    cout << "Print Level Order (BFS): ";
    bt.printLevelOrder();

    return 0;
}