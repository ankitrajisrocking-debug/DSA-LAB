#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q1, q2;

public:
    void push(int x) {
        q2.push(x);

        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }

    void pop() {
        if (q1.empty())
            cout << "Stack Underflow\n";
        else {
            cout << "Popped: " << q1.front() << endl;
            q1.pop();
        }
    }

    void top() {
        if (q1.empty())
            cout << "Stack is Empty\n";
        else
            cout << "Top: " << q1.front() << endl;
    }
};

int main() {
    Stack s;
    int choice, x;

    do {
        cout << "\n1. Push\n2. Pop\n3. Top\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> x;
                s.push(x);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.top();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 4);

    return 0;
}