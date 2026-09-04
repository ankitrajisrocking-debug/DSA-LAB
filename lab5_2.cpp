#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    stack<char> st;

    for (char c : s)
        st.push(tolower(c));

    bool palindrome = true;

    for (char c : s) {
        if (tolower(c) != st.top()) {
            palindrome = false;
            break;
        }
        st.pop();
    }

    cout << (palindrome ? "Palindrome" : "Not Palindrome") << endl;

    return 0;
}
