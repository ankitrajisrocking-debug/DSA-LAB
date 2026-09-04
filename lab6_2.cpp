#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;

    stack<string> s;

    for (char c : postfix) {
        if (!isOperator(c)) {
            s.push(string(1, c));
        } 
        else {
            string op2 = s.top(); s.pop();
            string op1 = s.top(); s.pop();

            s.push(string(1, c) + op1 + op2);
        }
    }

    cout << "Prefix expression: " << s.top() << endl;

    return 0;
}
