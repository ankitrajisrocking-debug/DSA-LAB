#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<double>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[minIdx]) minIdx = j;
        if (minIdx != i) swap(a[i], a[minIdx]);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<double> a(n);
    cout << "Enter " << n << " numbers: ";
    for (double &x : a) cin >> x;

    selectionSort(a);

    cout << "Sorted: ";
    for (double x : a) cout << x << " ";
    cout << endl;
    return 0;
}
