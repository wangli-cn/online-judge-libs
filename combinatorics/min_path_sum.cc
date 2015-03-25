//============================================================================
// Given a m x n grid filled with non-negative numbers, find a path from top
// left to bottom right which minimizes the sum of all numbers along its path.
//
// Note: You can only move either down or right at any point in time.
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > VVI;

int go(VVI &grid, VVI &dp, int i, int j)
{
    if (dp[i][j] > 0) return dp[i][j];

    if (i == 0 && j == 0) return dp[0][0] = grid[0][0];
    else if (i == 0) return dp[0][j-1] = go(grid, dp, 0, j-1) + grid[0][j];
    else if (j == 0) return dp[i-1][0] = go(grid, dp, i-1, 0) + grid[i-1][0];

    int from_top = go(grid, dp, i-1, j) + grid[i][j];
    int from_left = go(grid, dp, i, j-1) + grid[i][j];
    return dp[i][j] = max(from_left, from_top);
}

int min_sum(VVI &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int> > dp(m, vector<int>(n, 0));

    return go(grid, dp, m-1, n-1);
}

int main(void)
{
    VVI grid(3, vector<int>(3, 0));
    grid[1][1] = 1;

    cout << min_sum(grid) << endl;
    return 0;
}
