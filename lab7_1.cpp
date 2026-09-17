#include <iostream>
#include <stack>
using namespace std;

class Queue {
    stack<int> s1, s2;

public:
    void enqueue(int x) {
        s1.push(x);
    }

    void dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty\n";
            return;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        cout << "Dequeued: " << s2.top() << endl;
        s2.pop();
    }

    void display() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue: ";
        stack<int> temp = s2;

        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }

        stack<int> t = s1;
        int a[100], n = 0;

        while (!t.empty()) {
            a[n++] = t.top();
            t.pop();
        }

        for (int i = n - 1; i >= 0; i--)
            cout << a[i] << " ";

        cout << endl;
    }
};

int main() {
    Queue q;
    int n, x;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.enqueue(x);
    }

    q.display();
while(1){
    cout << "Enter 1 to dequeue or 0 to exit : ";
    cin >> x;

    if (x == 1)
        q.dequeue();
    else{
    	cout<< "exit" << endl;
    	break;
    	}

    q.display();
    }

    return 0;
}