//============================================================================
// String to Integer (atoi)
// Implement atoi to convert a string to an integer.
//
// Hint: Carefully consider all possible input cases. If you want a challenge,
// please do not see below and ask yourself what are the possible input cases.
//
// Notes: It is intended for this problem to be specified vaguely (ie, no given
// input specs). You are responsible to gather all the input requirements up
// front.
//
// Requirements for atoi:
// The function first discards as many whitespace characters as necessary until
// the first non-whitespace character is found. Then, starting from this
// character, takes an optional initial plus or minus sign followed by as many
// numerical digits as possible, and interprets them as a numerical value.
//
// The string can contain additional characters after those that form the
// integral number, which are ignored and have no effect on the behavior of
// this function.
//
// If the first sequence of non-whitespace characters in str is not a valid
// integral number, or if no such sequence exists because either str is empty
// or it contains only whitespace characters, no conversion is performed.
//
// If no valid conversion could be performed, a zero value is returned. If the
// correct value is out of the range of representable values, std::numeric_limits<int>::max()
// (2147483647) or std::numeric_limits<int>::min() (-2147483648) is returned.
//============================================================================

#include <iostream>
#include <climits>

using namespace std;

int my_atoi(const char *s)
{
    int sign = 1;
    while (*s == ' ') s++;

    if (*s == '+') s++;
    else if (*s == '-') s++, sign = -1;

    long long value = 0;
    if (s != nullptr) {
        while (*s && (*s) <= '9' && (*s) >= '0') {
            value = value * 10 + *s - '0';
            s++;
        }
    }

    if (sign == -1) value = -value;
    if (value < std::numeric_limits<int>::min()) value = std::numeric_limits<int>::min();
    if (value > std::numeric_limits<int>::max()) value = std::numeric_limits<int>::max();

    return value;
}

int main()
{
    const char *s = "1234abc";
    cout << my_atoi(s) << endl;
    return 0;
}
