#include <iostream>
using namespace std;

#define MAX 5

class PriorityQueue {
    int arr[MAX], priority[MAX], n;

public:
    PriorityQueue() {
        n = 0;
    }

    void enqueue(int x, int p) {
        if (n == MAX) {
            cout << "Queue Overflow!\n";
            return;
        }
        arr[n] = x;
        priority[n] = p;
        n++;
    }

    void dequeue() {
        if (n == 0) {
            cout << "Queue Underflow!\n";
            return;
        }

        int k = 0;
        for (int i = 1; i < n; i++)
            if (priority[i] < priority[k])
                k = i;

        cout << "Deleted: " << arr[k] << "\n";

        for (int i = k; i < n - 1; i++) {
            arr[i] = arr[i + 1];
            priority[i] = priority[i + 1];
        }
        n--;
    }

    void display() {
        if (n == 0) {
            cout << "Queue is Empty!\n";
            return;
        }

        cout << "Elements: ";
        for (int i = 0; i < n; i++)
            cout << arr[i] << "(" << priority[i] << ") ";
        cout << "\n";
    }
};

int main() {
    PriorityQueue q;
    int ch, x, p;

    do {
        cout << "\n1.Enqueue  2.Dequeue  3.Display  4.Exit\n";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Enter element and priority: ";
            cin >> x >> p;
            q.enqueue(x, p);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "Exiting...";
            break;
        default:
            cout << "Invalid Choice!";
        }
    } while (ch != 4);

    return 0;
}
