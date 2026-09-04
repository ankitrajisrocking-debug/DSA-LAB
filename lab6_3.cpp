#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

int main() {
    string exp;
    stack<int> s;

    cout << "Enter postfix expression: ";
    cin >> exp;

    for (char ch : exp) {
        // If operand, push it
        if (isdigit(ch)) {
            s.push(ch - '0');
        }
        // If operator, pop two operands
        else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();

            switch (ch) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
                case '^': s.push(pow(a, b)); break;
            }
        }
    }

    cout << "Result = " << s.top() << endl;

    return 0;
}
