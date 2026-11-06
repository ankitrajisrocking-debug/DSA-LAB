#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<double>& a) {
    for (size_t i = 1; i < a.size(); i++) {
        double key = a[i];                                                                                                                                                                                                                                
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<double> a(n);
    cout << "Enter " << n << " numbers: ";
    for (double &x : a) cin >> x;

    insertionSort(a);

    cout << "Sorted: ";
    for (double x : a) cout << x << " ";
    cout << endl;
    return 0;
}
