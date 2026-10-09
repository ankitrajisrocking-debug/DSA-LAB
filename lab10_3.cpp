#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MaxHeap {
    vector<int> a;  // 0-indexed: parent(i)=(i-1)/2, left=2i+1, right=2i+2

    void siftUp(int i) {
        while (i > 0 && a[(i - 1) / 2] < a[i]) {
            swap(a[(i - 1) / 2], a[i]);
            i = (i - 1) / 2;
        }
    }

    void siftDown(int i) {
        int n = a.size();
        while (true) {
            int l = 2 * i + 1, r = 2 * i + 2, largest = i;
            if (l < n && a[l] > a[largest]) largest = l;
            if (r < n && a[r] > a[largest]) largest = r;
            if (largest == i) break;
            swap(a[i], a[largest]);
            i = largest;
        }
    }

public:
    // Build heap from array in O(N) (bottom-up heapify)
    void build(const vector<int>& arr) {
        a = arr;
        for (int i = (int)a.size() / 2 - 1; i >= 0; i--)
            siftDown(i);
    }

    void insert(int x) {
        a.push_back(x);
        siftUp(a.size() - 1);
    }

    // Deletes and returns the max (root). Returns false if heap is empty.
    bool deleteMax(int& removed) {
        if (a.empty()) return false;
        removed = a[0];
        a[0] = a.back();
        a.pop_back();
        if (!a.empty()) siftDown(0);
        return true;
    }

    // Verify: every node must be >= its children
    bool isMaxHeap() const {
        int n = a.size();
        for (int i = 0; i < n; i++) {
            int l = 2 * i + 1, r = 2 * i + 2;
            if (l < n && a[i] < a[l]) return false;
            if (r < n && a[i] < a[r]) return false;
        }
        return true;
    }

    void display() const {
        if (a.empty()) { cout << "Heap is empty.\n"; return; }
        cout << "Heap (array): ";
        for (int x : a) cout << x << " ";
        cout << "\nTree view:\n";
        int level = 0, count = 0, perLevel = 1;
        for (size_t i = 0; i < a.size(); i++) {
            if (count == 0) cout << "  Level " << level << ": ";
            cout << a[i] << " ";
            if (++count == perLevel) {
                cout << "\n";
                level++; count = 0; perLevel *= 2;
            }
        }
        if (count != 0) cout << "\n";
    }

    void report() const {
        display();
        cout << "Max-Heap property satisfied? "
             << (isMaxHeap() ? "YES" : "NO") << "\n";
    }
};

int main() {
    MaxHeap h;
    int n;
    cout << "Enter number of elements N: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter " << n << " integers: ";
    for (int& x : arr) cin >> x;

    h.build(arr);
    cout << "\n--- After constructing Max-Heap ---\n";
    h.report();

    int choice;
    do {
        cout << "\n1. Insert  2. Delete (max)  3. Exit\nChoice: ";
        cin >> choice;
        if (choice == 1) {
            int x;
            cout << "Enter value to insert: ";
            cin >> x;
            h.insert(x);
            cout << "\n--- After inserting " << x << " ---\n";
            h.report();
        } else if (choice == 2) {
            int removed;
            if (h.deleteMax(removed)) {
                cout << "\n--- After deleting max (" << removed << ") ---\n";
                h.report();
            } else {
                cout << "Cannot delete: heap is empty.\n";
            }
        }
    } while (choice != 3);

    return 0;
}
