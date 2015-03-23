//============================================================================
// Interleaving String
// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
//
// For example,
// Given:
// s1 = "aabcc",
// s2 = "dbbca",
//
// When s3 = "aadbbcbcac", return true.
// When s3 = "aadbbbaccc", return false.
//============================================================================

#include <iostream>
#include <string>

using namespace std;

const int MAXN = 100;
bool dp[MAXN][MAXN];

bool go(string s1, int i, string s2, int j, string s3)
{
    if (i > s1.size() && s3.size() != i+j) return dp[i][j] = false;
    if (j > s2.size() && s3.size() != i+j) return dp[i][j] = false;

    if (i == 0) {
        if (s2[j-1] == s3[j-1]) return dp[i][j] = true;
        else return dp[i][j] = false;
    }

    if (j == 0) {
        if (s1[i-1] == s3[i-1]) return dp[i][j] = true;
        else return dp[i][j] = false;
    }

    if ((go(s1, i-1, s2, j, s3) && (s3[i+j-1] == s1[i-1])) ||
        (go(s1, i, s2, j-1, s3) && (s3[i+j-1] == s2[j-1]))) {
        return dp[i][j] = true;
    } else {
        return dp[i][j] = false;
    }
}

bool is_interleaving(string s1, string s2, string s3)
{
    return go(s1, s1.size(), s2, s2.size(), s3);
}

int main(void)
{
    string s1("aabcc");
    string s2("dbbca");
    string s3("aadbbcbcac");
    string s4("aadbbbaccc");

    cout << is_interleaving(s1, s2, s3) << endl;
    cout << is_interleaving(s1, s2, s4) << endl;
    return 0;
}
