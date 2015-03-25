/*
A k-palindrome is a string which transforms into a palindrome on removing at most k characters.

Given a string S, and an interger K, print "YES" if S is a k-palindrome; otherwise print "NO".
Constraints:
S has at most 20,000 characters.
0<=k<=30

Sample Test Case#1:
Input - abxa 1
Output - YES
Sample Test Case#2:
Input - abdxa 1
Output - No
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

typedef vector<vector<int> > VVI;

int go(const string &a, const string &b, int K, int i, int j, VVI dp)
{
    if (abs(i-j) > K) {
        return (std::numeric_limits<int>::max() / 2);
    }

    if (dp[i][j] > 0 && dp[i][j] < (std::numeric_limits<int>::max() / 2)) {
        return dp[i][j];
    }

    if (i == 0 && j == 0) return dp[i][j] = 0;
    if (i == 0) return dp[i][j] = j;
    if (j == 0) return dp[i][j] = i;

    if (a[i-1] == b[j-1]) {
        dp[i][j] = go(a, b, K, i-1, j-1, dp);
    }

    dp[i][j] = min(dp[i][j], go(a, b, K, i, j-1, dp) + 1);
    dp[i][j] = min(dp[i][j], go(a, b, K, i-1, j, dp) + 1);

    return dp[i][j];
}

int modified_edit_distance(const string &a, const string &b, int K)
{
    int n = a.size();

    VVI dp(n+1, vector<int>(n+1, std::numeric_limits<int>::max()));

    return go(a, b, K, n, n, dp);
}


bool is_k_palindrome(const string &s, int K)
{
    string reversed_s(s);
    reverse(reversed_s.begin(), reversed_s.end());

    int ans = modified_edit_distance(s, reversed_s, K);

    if (ans <= K+K) {
        return true;
    } else {
        return false;
    }
}

int main()
{
    cout << std::boolalpha << is_k_palindrome(string("abxa"), 1) << endl;  //yes
    cout << std::boolalpha << is_k_palindrome(string("abdxa"), 1) << endl;  //no
    cout << std::boolalpha << is_k_palindrome(string("abaxbabax"), 2) << endl; //yes

    return 0;
}
