//============================================================================
// Given a collection of numbers, return all possible permutations.
//
// For example,
// [1,2,3] have the following permutations:
// [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
//============================================================================

#include <iostream>
#include <string>

using namespace std;

void lexical_permutation(string &s, int pos)
{
    const int n = s.length();
    if (pos == n-1) {
        cout << s << endl;
        return;
    }

    lexical_permutation(s, pos+1);
    for (int i = pos+1; i < n; ++i) {
        if (s[pos] != s[i]) {
            swap(s[pos], s[i]);
            lexical_permutation(s, pos+1);
        }
    }

    char c = s[pos];
    for (int i = pos+1; i < n; i++)
        s[i-1] = s[i];
    s[n-1] = c;
}

int main(void)
{
    string s("123");

    lexical_permutation(s, 0);

    return 0;
}
