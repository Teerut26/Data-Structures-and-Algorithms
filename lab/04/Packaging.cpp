#include <iostream>
#include <stack>
#include <string>

using namespace std;

int calculateCost(int A, int B, int C, const string& input) {
    stack<int> costStack;
    int totalCost = 0;

    for (char c : input) {
        if (c == '[' || c == '(') {
            costStack.push(totalCost);
            totalCost = 0;
        } else if (c == ']') {
            int prevCost = costStack.top();
            costStack.pop();
            totalCost = A * (totalCost == 0 ? 1 : totalCost) + prevCost;
        } else if (c == ')') {
            int prevCost = costStack.top();
            costStack.pop();
            totalCost = B * (totalCost == 0 ? 1 : totalCost) + prevCost;
        } else {
            totalCost += C;
        }
    }

    return totalCost;
}

int main() {
    int A, B, C;
    string input;

    // Read inputs
    cin >> A >> B >> C;
    cin.ignore(); // Ignore the newline character after reading integers
    getline(cin, input);

    int result = calculateCost(A, B, C, input);
    cout << result << endl;

    return 0;
}
