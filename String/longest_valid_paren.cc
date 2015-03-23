//============================================================================
// Given a string containing just the characters '(' and ')', find the length
// of the longest valid (well-formed) parentheses substring.
//
// For "(()", the longest valid parentheses substring is "()", which has
// length = 2.
//
// Another example is ")()())", where the longest valid parentheses substring
// is "()()", which has length = 4.
//============================================================================

#include <iostream>

using namespace std;

int longest_paren(string s)
{
    int n = s.size();
    if (n < 2) return 0;

    int res = 0;

    int k = 0, l = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') k++, l++;
        else k--, l++;

        if (k == 0 && l > res) res = l;
        else if (k < 0) k = 0, l = 0;
    }

    k = 0; l = 0;
    for (int i = n-1; i >= 0; i--) {
        if (s[i] == ')') k++, l++;
        else k--, l++;

        if (k == 0 && l > res) res = l;
        else if (k < 0) k = 0, l = 0;
    }

    return res;
}

int main(void)
{
    string input("(((())((()))))))");
    cout << longest_paren(input) << endl;
    return 0;
}
