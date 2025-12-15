#include <iostream>
using namespace std;

struct Node {
    char data;
    Node *left, *right;
};

Node* newNode(char data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node *root = newNode('R');
    root->left = newNode('A');
    root->right = newNode('E');
    root->left->left = newNode('S');
    root->left->right = newNode('T');
    root->left->left->left = newNode('I');

    cout << "Tampilan secara Preorder  : ";
    preorder(root);
    cout << endl;

    cout << "Tampilan secara Inorder   : ";
    inorder(root);
    cout << endl;

    cout << "Tampilan secara Postorder : ";
    postorder(root);
    cout << endl;

    return 0;
}
