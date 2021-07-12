## Morris Traversal

```cpp
void BinaryTree::morrisTraversalPreorder(Node* _root) {
  Node *node = _root;
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

void BinaryTree::morrisTraversalInorder(Node* _root) {
  Node *node = _root;
  while(node != nullptr) {
    if(node->left == nullptr) {
      cout << node->data << ' ';
      node = node->right;
    } else {
      Node *curr = node->left;
      while(curr->right && curr->right != node) curr = curr->right;

      if(curr->right == nullptr) {
        curr->right = node;
        node = node->left;
      } else {
        curr->right = nullptr;
        cout << node->data << ' ';
        node = node->right;
      }
    }
  }
}
```
