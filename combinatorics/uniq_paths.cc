//============================================================================
// Unique Paths
// A robot is located at the top-left corner of a m x n grid (marked 'Start'
// in the diagram below).
//
// The robot can only move either down or right at any point in time. The robot
// is trying to reach the bottom-right corner of the grid (marked 'Finish' in
// the diagram below).
//
// How many possible unique paths are there?
//============================================================================


#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > VVI;

int go(VVI &dp, int i, int j)
{
    if (dp[i][j] > 0) return dp[i][j];

    if (i == 0 && j == 0) return dp[0][0] = 1;
    else if (i == 0) return dp[0][j-1] = go(dp, 0, j-1);
    else if (j == 0) return dp[i-1][0] = go(dp, i-1, 0);

    return dp[i][j] = go(dp, i-1, j) + go(dp, i, j-1);
}

int uniq_path(int m, int n)
{
    vector<vector<int> > dp(m, vector<int>(n, 0));

    return go(dp, m-1, n-1);
}

int main(void)
{
    cout << uniq_path(3, 2) << endl;
    return 0;
}
