#include <iostream>
#include <string>

using namespace std;

int char_to_int(char c)
{
    if (isdigit(c)) return c - '0';
    else return c - 'A';
}

char int_to_char(int d)
{
    if (d >= 10) return d - 10 + 'A';
    else return d + '0';
}

string base_conversion(string s, int from_base, int to_base)
{
    int t = 1, ans = 0;
    for (int i = s.length()-1; i >= 0; i--) {
        ans += t * char_to_int(s[i]);
        t *= from_base;
    }

    t = 1;
    while (t <= ans) t *= to_base;
    t /= to_base;

    string output("");
    while (ans > 0) {
        output += int_to_char(ans % to_base);
        ans /= to_base;
    }

    reverse(output.begin(), output.end());
    return output;
}

int main()
{
    cout << base_conversion(string("10011010"), 2, 16) << endl;
    return 0;
}


