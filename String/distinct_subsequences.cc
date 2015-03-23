//============================================================================
// Distinct Subsequences
// Given a string S and a string T, count the number of distinct subsequences
// of T in S.
//
// A subsequence of a string is a new string which is formed from the original
// string by deleting some (can be none) of the characters without disturbing
// the relative positions of the remaining characters. (ie, "ACE" is a
// subsequence of "ABCDE" while "AEC" is not).
//
// Here is an example:
// S = "rabbbit", T = "rabbit"
//
// Return 3.
//============================================================================

#include <iostream>
#include <string>

using namespace std;

const int MAXN = 100;
int dp[MAXN][MAXN];

int go(string s, int i, string t, int j)
{
    if (dp[i][j] > 0) return dp[i][j];

    if (i == 0 && j == 0) return dp[0][0] = 1;
    if (i == 0) return dp[0][j] = 0;
    if (j == 0) return dp[i][0] = 1;

    if (s[i-1] == t[j-1]) return dp[i][j] = go(s, i-1, t, j-1) + go(s, i-1, t, j);
    else return dp[i][j] = go(s, i-1, t, j);
}

int num_distinct(string s, string t)
{
    for (int i = 0; i <= s.size(); i++) {
        for (int j = 0; j <= t.size(); j++) {
            dp[i][j] = 0;
        }
    }

    return go(s, s.size(), t, t.size());
}

int main(void)
{
    string s("rabbbit");
    string t("rabbit");

    cout << num_distinct(s, t) << endl;
    return 0;
}
