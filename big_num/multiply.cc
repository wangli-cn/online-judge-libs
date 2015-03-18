//============================================================================
// Multiply Strings
//
// Given two numbers represented as strings, return multiplication of the
// numbers as a string.
//
// Note: The numbers can be arbitrarily large and are non-negative.
//============================================================================

#include <iostream>
#include <string>

using namespace std;

string multiply(string a, string b)
{
    int m = a.length(), n = b.length();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string c(m+n, '0');

    int carry = 0;
    for (int i = 0; i < m; i++) {
        carry = 0;
        for (int j = 0; j < n; j++) {
            int tmp = carry + (c[i+j] - '0') + (a[i] - '0') * (b[j] - '0');

            c[i+j] = (tmp % 10) + '0';
            carry = tmp / 10;
        }

        c[i+n] = (carry + '0');
    }

    reverse(c.begin(), c.end());

    int l = 0;
    for (int i = 0; i < c.length(); i++) {
        if (c[i] == '0') {
            l += 1;
        } else {
            break;
        }
    }

    string res = c.substr(l);

    return res;
}

int main()
{
    string a("10000");
    string b("99999");

    cout << multiply(a, b) << endl;

    return 0;
}
