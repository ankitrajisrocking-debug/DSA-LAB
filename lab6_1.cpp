#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void displayStack(stack<char> s) {
    string temp;
    while (!s.empty()) {
        temp += s.top();
        s.pop();
    }

    for (int i = temp.length() - 1; i >= 0; i--)
        cout << temp[i];
}

string infixToPostfix(string exp) {
    stack<char> st;
    string postfix;

    cout << "\nSymbol\tStack\tPostfix\n";
    cout << "---------------------------\n";

    for (char ch : exp) {

        if (isalnum(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            st.push(ch);
        }
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();   // remove '('
        }
        else {
            while (!st.empty() && st.top() != '(' &&
                   precedence(st.top()) >= precedence(ch)) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }

        cout << ch << "\t";
        displayStack(st);
        cout << "\t" << postfix << endl;
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    cout << "End\t";
    displayStack(st);
    cout << "\t" << postfix << endl;

    return postfix;
}

int main() {
    string exp;

    cout << "Enter infix expression: ";
    cin >> exp;

    cout << "\nPostfix Expression: " << infixToPostfix(exp) << endl;

    return 0;
}
