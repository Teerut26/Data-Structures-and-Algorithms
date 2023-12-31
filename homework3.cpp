#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string s) {
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            result += c;

        else if (c == '(')
            st.push('(');

        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                char temp = st.top();
                st.pop();
                result += temp;
            }
            st.pop();
        }

        else {
            while (!st.empty() && precedence(c) <= precedence(st.top())) {
                char temp = st.top();
                st.pop();
                result += temp;
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        char temp = st.top();
        st.pop();
        result += temp;
    }

    return result;
}

int main() {
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    cout << infixToPostfix(exp) << endl;
    return 0;
}
