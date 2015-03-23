//============================================================================
// Given a string S, find the longest palindromic substring in S. You may
// assume that the maximum length of S is 1000, and there exists one unique
// longest palindromic substring.
//============================================================================

#include <iostream>

using namespace std;

bool go(string &s, int i, int j, int &len)
{
    if (i == j) {
        len = max(len, 1);
        return true;
    } else if (j == i+1) {
        if (s[i] == s[j]) {
            len = max(len, 2);
            return true;
        } else {
            return false;
        }
    } else {
        if (go(s, i+1, j-1, len) && s[i] == s[j]) {
            len = max(j-i+1, len);
            return true;
        } else {
            return false;
        }
    }
}

int main()
{
    string s("abbacdefedc");
    int len = 0;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            go(s, i, j, len);
        }
    }

    cout << len << endl;
    return 0;
}
