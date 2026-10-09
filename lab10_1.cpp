#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

int height(Node *n) {
    return n ? 1 + max(height(n->left), height(n->right)) : 0;
}

// Balance factor = height(left) - height(right)
int balanceFactor(Node *n) {
    return n ? height(n->left) - height(n->right) : 0;
}

// Plain BST insert (no balancing) so the tree can become unbalanced
Node *bstInsert(Node *root, int key) {
    if (!root) return new Node(key);
    if (key < root->key) root->left = bstInsert(root->left, key);
    else if (key > root->key) root->right = bstInsert(root->right, key);
    else cout << "Duplicate " << key << " ignored.\n";
    return root;
}

Node *rotateRight(Node *y) {
    Node *x = y->left;
    y->left = x->right;
    x->right = y;
    return x;
}

Node *rotateLeft(Node *x) {
    Node *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

// Print balance factor of every node (in-order); returns true if all are balanced
bool showBalanceFactors(Node *n) {
    if (!n) return true;
    bool ok = showBalanceFactors(n->left);
    int bf = balanceFactor(n);
    bool bad = (bf > 1 || bf < -1);
    cout << "  Node " << setw(4) << left << n->key
         << " | height(L)=" << height(n->left)
         << " height(R)=" << height(n->right)
         << " | BF = " << showpos << bf << noshowpos
         << (bad ? "  <-- UNBALANCED" : "  (ok)") << "\n";
    ok = ok && !bad;
    return showBalanceFactors(n->right) && ok;
}

// Bottom-up: fix children first, then this node. Identifies LL/RR/LR/RL.
Node *rebalance(Node *n) {
    if (!n) return nullptr;
    n->left = rebalance(n->left);
    n->right = rebalance(n->right);

    int bf = balanceFactor(n);

    if (bf > 1) {                                   // left heavy
        if (balanceFactor(n->left) >= 0) {
            cout << "  Node " << n->key << ": LL imbalance -> right rotation on " << n->key << "\n";
            return rotateRight(n);
        } else {
            cout << "  Node " << n->key << ": LR imbalance -> left rotation on " << n->left->key
                 << ", then right rotation on " << n->key << "\n";
            n->left = rotateLeft(n->left);
            return rotateRight(n);
        }
    }
    if (bf < -1) {                                  // right heavy
        if (balanceFactor(n->right) <= 0) {
            cout << "  Node " << n->key << ": RR imbalance -> left rotation on " << n->key << "\n";
            return rotateLeft(n);
        } else {
            cout << "  Node " << n->key << ": RL imbalance -> right rotation on " << n->right->key
                 << ", then left rotation on " << n->key << "\n";
            n->right = rotateRight(n->right);
            return rotateLeft(n);
        }
    }
    return n;
}

void inorder(Node *n) {
    if (!n) return;
    inorder(n->left);
    cout << n->key << " ";
    inorder(n->right);
}

void preorder(Node *n) {
    if (!n) return;
    cout << n->key << " ";
    preorder(n->left);
    preorder(n->right);
}

void freeTree(Node *n) {
    if (!n) return;
    freeTree(n->left);
    freeTree(n->right);
    delete n;
}

int main() {
    int n, key;
    Node *root = nullptr;

    cout << "Enter number of nodes: ";
    if (!(cin >> n) || n <= 0) return 1;

    cout << "Enter " << n << " keys: ";
    for (int i = 0; i < n; i++) {
        if (!(cin >> key)) return 1;
        root = bstInsert(root, key);
    }

    cout << "\n--- Balance factors of the initial tree ---\n";
    bool balanced = showBalanceFactors(root);

    if (balanced) {
        cout << "\nResult: The tree already satisfies the AVL condition.\n";
    } else {
        cout << "\nResult: The tree is NOT an AVL tree. Rebalancing...\n\n";
        root = rebalance(root);

        cout << "\n--- Balance factors after rebalancing ---\n";
        balanced = showBalanceFactors(root);
        cout << "\nResult: " << (balanced ? "The tree now satisfies the AVL condition."
                                          : "Tree is still unbalanced.") << "\n";
    }

    cout << "\nIn-order traversal : ";
    inorder(root);
    cout << "\nPre-order traversal: ";
    preorder(root);
    cout << "\n";

    freeTree(root);
    return 0;
}
