#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<double>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<double> a(n);
    cout << "Enter " << n << " numbers: ";
    for (double &x : a) cin >> x;

    bubbleSort(a);

    cout << "Sorted: ";
    for (double x : a) cout << x << " ";
    cout << endl;
    return 0;
}
