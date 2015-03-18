//============================================================================
// Decode Ways
// A message containing letters from A-Z is being encoded to numbers using
// the following mapping:
//
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given an encoded message containing digits, determine the total number of
// ways to decode it.
//
// For example,
// Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
//
// The number of ways decoding "12" is 2.
//============================================================================

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1024;
int dp[MAXN];

int f(string &s, int i)
{
    if (i <= 0) {
        return 1;
    }

    if (dp[i] > 0) {
        return dp[i];
    }

    if (s[i-1] == '1') {
        if (s[i] == '0') return dp[i] = f(s, i-2);
        else return dp[i] = f(s, i-1) + f(s, i-2);
    } else if (s[i-1] == '2') {
        if (s[i] == '0') return dp[i] = f(s, i-2);
        else if (s[i] > '6') return dp[i] = f(s, i-1);
        else return dp[i] = f(s, i-1) + f(s, i-2);
    } else {
        if (s[i-1] == '0') return 0;
        return dp[i] = f(s, i-1);
    }
}

int decode_ways(string &s)
{
    int n = s.size();

    fill_n(dp, 0, MAXN);

    return f(s, n-1);
}

int main(void)
{
    string input("1223");
    cout << decode_ways(input) << endl;
    return 0;
}
