#include <iostream>
#include <string>

using namespace std;

//can deal with the repetition in the string
void lexical_permutation(string &s, int pos)
{
    int n = s.length();
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
    for (int i = pos+1; i < n; ++i)
        s[i-1] = s[i];
    s[n-1] = c;
}

int main(void)
{
    string s;
    cin >> s;
    lexical_permutation(s, 0);

    return 0;
}
