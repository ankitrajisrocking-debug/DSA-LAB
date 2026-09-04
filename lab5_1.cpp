#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

void push(int x) {
    Node* n = new Node{x, top};
    top = n;
}

void pop() {
    if (top == NULL) {
        cout << "Stack Underflow\n";
        return;
    }
    Node* temp = top;
    cout << "Popped: " << top->data << endl;
    top = top->next;
    delete temp;
}

void display() {
    for (Node* p = top; p; p = p->next)
        cout << p->data << " ";
    cout << endl;
}

void reverseStack() {
    Node *prev = NULL, *cur = top, *next;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    top = prev;
}

int main() {
    push(12);
    push(76);
    push(23);
    push(12);

    cout << "Original Stack: ";
    display();

    pop();

    cout << "After Pop: ";
    display();

    reverseStack();

    cout << "Reversed Stack: ";
    display();

    return 0;
}
