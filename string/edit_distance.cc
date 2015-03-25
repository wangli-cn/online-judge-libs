//============================================================================
// Given two words word1 and word2, find the minimum number of steps required
// to convert word1 to word2. (each operation is counted as 1 step.)
//
// You have the following 3 operations permitted on a word:
//
// a) Insert a character
// b) Delete a character
// c) Replace a character
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > VVI;

int go(string &a, string &b, int i, int j, VVI &dp)
{
    if (i >= 0 && j >= 0 && dp[i][j] > 0) return dp[i][j];

    if (i == 0 && j == 0) return dp[i][j] = 0;
    if (i == 0) return dp[i][j] = j;
    if (j == 0) return dp[i][j] = i;

    int from_left_or_top = min(go(a, b, i, j-1, dp)+1, go(a, b, i-1, j, dp)+1);
    int from_left_top = go(a, b, i-1, j-1, dp) + (a[i-1] != b[j-1]);

    return dp[i][j] = min(from_left_or_top, from_left_top);
}

int main()
{
    string a("abcde");
    string b("edc");

    VVI dp(a.length()+1, vector<int>(b.length()+1, -1));
    std::cout << go(a, b, a.length(), b.length(), dp) << std::endl;

    return 0;
}
