//============================================================================
// Unique Paths II
// Follow up for "Unique Paths":
//
// Now consider if some obstacles are added to the grids. How many unique
// paths would there be?
//
// An obstacle and empty space is marked as 1 and 0 respectively in the grid.
//
// For example,
// There is one obstacle in the middle of a 3x3 grid as illustrated below.
//
// [
//  [0,0,0],
//  [0,1,0],
//  [0,0,0]
// ]
// The total number of unique paths is 2.
//
// Note: m and n will be at most 100.
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > VVI;

int go(VVI &grid, VVI &dp, int i, int j)
{
    if (dp[i][j] > 0) return dp[i][j];

    if (i >= 0 && j >= 0 && grid[i][j] == 1) return 0;

    if (i == 0 && j == 0) return dp[0][0] = 1;
    else if (i == 0) return dp[0][j-1] = go(grid, dp, 0, j-1);
    else if (j == 0) return dp[i-1][0] = go(grid, dp, i-1, 0);

    return dp[i][j] = go(grid, dp, i-1, j) + go(grid, dp, i, j-1);
}

int uniq_path(VVI &grid)
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

    cout << uniq_path(grid) << endl;
    return 0;
}
