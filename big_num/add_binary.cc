//============================================================================
// Given two binary strings, return their sum (also a binary string).
//
// For example,
// a = "11"
// b = "1"
// Return "100".
//
//============================================================================

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string add(string a, string b)
{
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string result;

    auto i = a.begin();
    auto j = b.begin();
    int carry = 0;
    while (1) {
        if (i != a.end() && j != b.end()) {
            int tmp = (*i - '0') + (*j - '0') + carry;
            carry = tmp / 2;
            char c = (tmp % 2) + '0';
            result.push_back(c);

            i++; j++;
        } else if (i != a.end()) {
            int tmp = (*i - '0') + carry;
            carry = tmp / 2;
            char c = (tmp % 2) + '0';
            result.push_back(c);

            i++;
        } else if (j != b.end()) {
            int tmp = (*j - '0') + carry;
            carry = tmp / 2;
            char c = (tmp % 2) + '0';
            result.push_back(c);

            j++;
        } else {
            break;
        }
    }

    if (carry == 1) result.push_back('1');

    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    string a("1111");
    string b("1");

    cout << add(a, b) << endl;

    return 0;
}
