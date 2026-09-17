#include <iostream>
using namespace std;

#define MAX 5

class TwoQueues {
    int arr[MAX];
    int front1, rear1;
    int front2, rear2;

public:
    TwoQueues() {
        front1 = rear1 = -1;
        front2 = rear2 = MAX;
    }

    void enqueue1(int x) {
        if (rear1 + 1 == rear2) {
            cout << "Array Overflow!\n";
            return;
        }

        if (front1 == -1)
            front1 = 0;

        arr[++rear1] = x;
    }

    void enqueue2(int x) {
        if (rear1 + 1 == rear2) {
            cout << "Array Overflow!\n";
            return;
        }

        if (front2 == MAX)
            front2 = MAX - 1;

        arr[--rear2] = x;
    }

    void dequeue1() {
        if (front1 == -1 || front1 > rear1) {
            cout << "Queue 1 Underflow!\n";
            return;
        }

        cout << "Deleted from Queue 1: " << arr[front1++] << endl;

        if (front1 > rear1)
            front1 = rear1 = -1;
    }

    void dequeue2() {
        if (front2 == MAX || front2 < rear2) {
            cout << "Queue 2 Underflow!\n";
            return;
        }

        cout << "Deleted from Queue 2: " << arr[front2--] << endl;

        if (front2 < rear2)
            front2 = rear2 = MAX;
    }

    void display() {
        cout << "Queue 1: ";
        if (front1 == -1)
            cout << "Empty";
        else
            for (int i = front1; i <= rear1; i++)
                cout << arr[i] << " ";

        cout << "\nQueue 2: ";
        if (front2 == MAX)
            cout << "Empty";
        else
            for (int i = front2; i >= rear2; i--)
                cout << arr[i] << " ";

        cout << endl;
    }
};

int main() {
    TwoQueues q;
    int choice, x;

    do {
        cout << "\n1. Enqueue Queue 1";
        cout << "\n2. Enqueue Queue 2";
        cout << "\n3. Dequeue Queue 1";
        cout << "\n4. Dequeue Queue 2";
        cout << "\n5. Display";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> x;
                q.enqueue1(x);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> x;
                q.enqueue2(x);
                break;

            case 3:
                q.dequeue1();
                break;

            case 4:
                q.dequeue2();
                break;

            case 5:
                q.display();
                break;

            case 6:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice!";
        }
    } while (choice != 6);

    return 0;
}