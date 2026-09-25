#include <iostream>
using namespace std;

struct Node {
    int key, height;
    Node *left, *right;

    Node(int k) {
        key = k;
        height = 1;
        left = right = NULL;
    }
};

int height(Node *n) {
    return n ? n->height : 0;
}

int balance(Node *n) {
    return n ? height(n->left) - height(n->right) : 0;
}

Node* rightRotate(Node *y) {
    Node *x = y->left;
    Node *t = x->right;

    x->right = y;
    y->left = t;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node *x) {
    Node *y = x->right;
    Node *t = y->left;

    y->left = x;
    x->right = t;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* insert(Node *root, int key) {
    if (!root) return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root;

    root->height = max(height(root->left), height(root->right)) + 1;

    int b = balance(root);

    if (b > 1 && key < root->left->key)
        return rightRotate(root);

    if (b < -1 && key > root->right->key)
        return leftRotate(root);

    if (b > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (b < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node* minNode(Node *root) {
    while (root->left)
        root = root->left;
    return root;
}

Node* deleteNode(Node *root, int key) {
    if (!root) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left || !root->right) {
            Node *temp = root->left ? root->left : root->right;

            if (!temp) {
                delete root;
                return NULL;
            }

            *root = *temp;
            delete temp;
        }
        else {
            Node *temp = minNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    root->height = max(height(root->left), height(root->right)) + 1;

    int b = balance(root);

    if (b > 1 && balance(root->left) >= 0)
        return rightRotate(root);

    if (b > 1 && balance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (b < -1 && balance(root->right) <= 0)
        return leftRotate(root);

    if (b < -1 && balance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(Node *root) {
    if (root) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main() {
    Node *root = NULL;

    int a[] = {30, 20, 40, 10, 25, 50};

    // Construct AVL Tree
    for (int x : a)
        root = insert(root, x);

    cout << "Initial AVL Tree: ";
    inorder(root);

    // Insertion
    root = insert(root, 35);
    cout << "\nAfter inserting 35: ";
    inorder(root);

    // Deletion
    root = deleteNode(root, 20);
    cout << "\nAfter deleting 20: ";
    inorder(root);

    return 0;
}
