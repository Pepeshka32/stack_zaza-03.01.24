#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(const string& str) {
    stack<char> bracketStack;

    for (char ch : str) {
        if (ch == '(' || ch == '{' || ch == '[') {
            bracketStack.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (bracketStack.empty()) return false;

            char top = bracketStack.top();
            bracketStack.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    return bracketStack.empty();
}

int main() {
    string test1 = "({x-y-z} * [x + 2y] - (z + 4x));";
    string test2 = "([x-y-z} * [x + 2y) - {z + 4x)];";

    cout << "1: " << (isBalanced(test1) ? "correct" : "uncorrect") << endl;
    cout << "2: " << (isBalanced(test2) ? "correct" : "uncorrect") << endl;

    return 0;
}
