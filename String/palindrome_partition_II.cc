//============================================================================
// Palindrome Partitioning II
// Given a string s, partition s such that every substring of the partition¿
// is a palindrome.
//
// Return the minimum cuts needed for a palindrome partitioning of s.
//
// For example, given s = "aab",
// Return 1 since the palindrome partitioning ["aa","b"] could be produced¿
// using 1 cut.
//
//============================================================================

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<vector<bool> > VVB;
typedef vector<bool> VB;
typedef vector<int> VI;

bool go(string s, int i, int j, VVB &dp)
{
    if (i == j) return dp[i][j] = true;
    else if (i+1 == j) return dp[i][j] = (s[i] == s[j]);
    else return dp[i][j] = (go(s, i+1, j-1, dp) && s[i] == s[j]);
}

int run(string s, int i, VI &part, VVB &dp)
{
    if (i == 0) return part[i] = -1;

    part[i] = run(s, i-1, part, dp) + 1;
    for (int j = i-2; j >= 0; j--) {
        if (go(s, j, i-1, dp)) {
            part[i] = min(part[i], 1 + run(s, j, part, dp));
        }
    }

    return part[i];
}

int min_cut(string s)
{
    int n = s.length();
    VI part(n+1, 0);
    VVB dp(n, vector<bool>(n, false));

    int res = run(s, n, part, dp);

    return res;
}

int main(void)
{
    auto res = min_cut(string("aab"));
    cout << res << endl;

    return 0;
}
