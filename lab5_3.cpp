#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "{[a+b}";
    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[')
            st.push(c);

        else if (c == ')' || c == '}' || c == ']') {
            if (st.empty()) {
                cout << "Not Balanced";
                return 0;
            }

            char t = st.top();
            st.pop();

            if ((c == ')' && t != '(') ||
                (c == '}' && t != '{') ||
                (c == ']' && t != '[')) {
                cout << "Not Balanced";
                return 0;
            }
        }
    }

    cout << (st.empty() ? "Balanced" : "Not Balanced");
    return 0;
}
