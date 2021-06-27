#include <iostream>
#include <queue>
using namespace std;
  
class Node {
  private:
  public:
    int data;
    Node *left;
    Node *right;

    Node(int _data) : data(_data), left(nullptr), right(nullptr) {;} 
    ~Node() = default;

    void preorder(Node *root) {
      if(!root) return;
      cout << root->data << ' ';
      preorder(root->left);
      preorder(root->right);
    }
};

/* postorder 방식으로 노드 삭제 */
void deleteTreeRec(Node *root) {
  if(!root) return;
  deleteTreeRec(root->left);
  deleteTreeRec(root->right);
  delete root;
}

/* BFS 방식으로 노드 삭제 */
void deleteTree(Node *root) {
  queue<Node *> q;
  q.push(root);

  while(!q.empty()) {
    Node *temp = q.front();
    q.pop();
    if(temp->left) q.push(temp->left);
    if(temp->right) q.push(temp->right);
    delete temp;
  }
}

int main() {
  Node *root = new Node(10);
  root->left = new Node(20);
  root->right = new Node(30);
  root->right->left = new Node(55);
  root->right->right = new Node(70);
  root->left->left = new Node(40);

  root->preorder(root);
//  deleteTree(root);
  deleteTreeRec(root);

  return 0;
}
