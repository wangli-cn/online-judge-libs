//============================================================================
// Palindrome Partitioning
// Given a string s, partition s such that every substring of the partition¿
// is a palindrome.
//
// Return all possible palindrome partitioning of s.
//
// For example, given s = "aab",
// Return
//
//   [
//       ["aa","b"],
//       ["a","a","b"]
//   ]
//============================================================================


#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<vector<bool> > VVB;
typedef vector<string> VS;
typedef vector<vector<string> > VVS;

bool go(string s, int i, int j, VVB &dp)
{
    if (i == j) return dp[i][j] = true;
    else if (i+1 == j) return dp[i][j] = (s[i] == s[j]);
    else return dp[i][j] = (go(s, i+1, j-1, dp) && s[i] == s[j]);
}

void run(string &s, int i, VS &sol, VVS &res, VVB &dp)
{
    if (i == s.size()) {
        res.push_back(sol);
        return;
    }

    for (int j = i; j < s.size(); j++) {
        if (go(s, i, j, dp)) {
            sol.push_back(s.substr(i, j-i+1));
            run(s, j+1, sol, res, dp);
            sol.pop_back();
        }
    }
}

VVS partition(string s)
{
    int n = s.length();

    VVS res;
    VS sub;
    VVB dp(n, vector<bool>(n, false));

    run(s, 0, sub, res, dp);
    return res;
}

int main(void)
{
    auto res = partition(string("aab"));

    for (auto it1: res) {
        for (auto it2: it1) {
            cout << it2 << " ";
        }
        cout << endl;
    }

    return 0;
}
