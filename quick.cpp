#include <bits/stdc++.h>
using namespace std;


int prtn (vector<int>& v, int lo, int hi) {
    int pivot = v[lo];
    int i = lo, j = hi;
    while(1) {
        while(i <= j && v[i] <= pivot) i++;
        while(i <= j && v[j] >= pivot) j--;
        if (i <= j) swap(v[i], v[j]);
        else break;
    }
    swap(v[lo], v[j]);
    return j;
}

void qk(vector<int>& v, int lo, int hi) {
    if(lo < hi) {
        int idx = prtn(v, lo, hi);

        qk(v, lo, idx - 1);
        qk(v, idx + 1, hi);
    }
}

void display(vector<int> v) {
    for(int i = 0; i < v.size(); i++) cout << v[i] << " " ;
    cout << endl;
}



int main() {
    vector<int> v = {4, 3, 5, 1, 8};
    qk(v, 0, v.size() - 1);
    display(v);

    //    return 0;
}