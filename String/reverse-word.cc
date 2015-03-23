#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string reverse_word(string &s)
{
    int l = s.length();

    reverse(s.begin(), s.end());
    size_t found;
    size_t last = 0;
    while ((found = s.find_first_of(" \t\n", last)) != string::npos) {
        reverse(s.begin() + last, s.begin() + found);
        last = found + 1;
    }

    if (last < l) {
        reverse(s.begin() + last, s.end());
    }

    return s;
}


int main(void)
{
    string s("   This \t is a \t book");
    cout << reverse_word(s) << endl;

    return 0;
}
