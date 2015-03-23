//============================================================================
// Valid Parentheses
// Given a string containing just the characters '(', ')', '{', '}', '[' and
// ']', determine if the input string is valid.
//
// The brackets must close in the correct order, "()" and "()[]{}" are all
// valid but "(]" and "([)]" are not.
//============================================================================

#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool is_valid(string s)
{
    int n = s.length();
    stack<char> S;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            S.push(s[i]);
        } else {
            char c = S.top();
            if ((c == '(' && s[i] == ')') || (c == '[' && s[i] == ']') || (c == '{' && s[i] == '}')) {
                S.pop();
            } else {
                return false;
            }
        }
    }

    return S.empty();
}

int main()
{
    string input("[](){}");

    cout << std::boolalpha << is_valid(input) << endl;
    return 0;
}
