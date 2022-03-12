#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* newNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int main(void) {
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);

    printf("root: %d\n", root->data);
    printf("root.left: %d        root.right: %d\n", root->left->data, root->right->data);
    printf("root.left.left: %d\n", root->left->left->data);

    return 0;
}