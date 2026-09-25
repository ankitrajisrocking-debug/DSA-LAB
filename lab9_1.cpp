#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

// Insertion
Node* insert(Node* root, int x) {
    if (root == NULL)
        return new Node(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);

    return root;
}

// Find minimum node
Node* minNode(Node* root) {
    while (root->left)
        root = root->left;
    return root;
}

// Deletion
Node* deleteNode(Node* root, int x) {
    if (root == NULL)
        return root;

    if (x < root->data)
        root->left = deleteNode(root->left, x);
    else if (x > root->data)
        root->right = deleteNode(root->right, x);
    else {
        // 0 or 1 child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // 2 children
        Node* temp = minNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    int a[] = {50, 30, 70, 20, 40, 60, 80};
    Node* root = NULL;

    // Construct BST
    for (int x : a)
        root = insert(root, x);

    cout << "Original BST: ";
    inorder(root);

    // Insertion
    root = insert(root, 65);

    cout << "\nAfter insertion: ";
    inorder(root);

    // Deletion
    root = deleteNode(root, 30);

    cout << "\nAfter deletion: ";
    inorder(root);

    return 0;
}
