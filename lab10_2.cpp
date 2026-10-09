#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class MinHeap {
    vector<int> heap;

    void heapifyUp(int i) {
        while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void heapifyDown(int i) {
        int n = heap.size();
        while (true) {
            int l = 2 * i + 1, r = 2 * i + 2, smallest = i;
            if (l < n && heap[l] < heap[smallest]) smallest = l;
            if (r < n && heap[r] < heap[smallest]) smallest = r;
            if (smallest == i) break;
            swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }

public:
    // Build heap in O(N) (Floyd's method)
    void build(const vector<int>& arr) {
        heap = arr;
        for (int i = (int)heap.size() / 2 - 1; i >= 0; i--)
            heapifyDown(i);
    }

    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    bool deleteMin(int &removed) {
        if (heap.empty()) {
            cout << "Heap is empty!\n";
            return false;
        }
        removed = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) heapifyDown(0);
        return true;
    }

    void display() const {
        cout << "Heap array : ";
        if (heap.empty()) cout << "(empty)";
        for (int x : heap) cout << x << " ";
        cout << "\n";
    }

    // Check heap[parent] <= heap[child] for every node
    bool verify() const {
        for (size_t i = 1; i < heap.size(); i++)
            if (heap[(i - 1) / 2] > heap[i]) return false;
        return true;
    }

    void report() const {
        display();
        cout << "Min-Heap property satisfied? " << (verify() ? "YES" : "NO") << "\n\n";
    }
};

int main() {
    int n;
    cout << "Enter number of elements N: ";
    if (!(cin >> n) || n < 0) {
        cout << "Invalid N.\n";
        return 1;
    }

    vector<int> arr(n);
    cout << "Enter " << n << " integers: ";
    for (int &x : arr) cin >> x;

    cout << "\nOriginal array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    MinHeap h;
    h.build(arr);
    cout << "\nAfter building Min-Heap:\n";
    h.report();

    int choice, val, removed;
    while (true) {
        cout << "1. Insert\n2. Delete min\n3. Exit\nChoice: ";
        if (!(cin >> choice) || choice == 3) break;

        if (choice == 1) {
            cout << "Enter value to insert: ";
            cin >> val;
            h.insert(val);
            cout << "\nAfter inserting " << val << ":\n";
            h.report();
        } else if (choice == 2) {
            if (h.deleteMin(removed))
                cout << "\nAfter deleting min (" << removed << "):\n";
            h.report();
        } else {
            cout << "Invalid choice.\n\n";
        }
    }
    return 0;
}
