#include <iostream>
#include <string>

using namespace std;

string expand_around_center(string &s, int c1, int c2)
{
    int l = c1, r = c2;
    int n = s.length();
    while (l >= 0 && r <= n-1 && s[l] == s[r]) {
        l--; r++;
    }
    return s.substr(l+1, r-l-1);
}

string longest_palindrom(string &s)
{
    int n = s.length();
    if (n == 0) return "";

    string longest = s.substr(0, 1);
    for (int i = 0; i < n-1; i++) {
        string p1 = expand_around_center(s, i, i);
        if (p1.length() > longest.length()) {
            longest = p1;
        }

        string p2 = expand_around_center(s, i, i+1);
        if (p2.length() > longest.length()) {
            longest = p2;
        }
    }

    return longest;
}

int main()
{
    string s("123abccba");
    std::cout << longest_palindrom(s) << std::endl;

    return 0;
}
