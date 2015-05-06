//============================================================================
// Unique Binary Search Trees
// Given n, how many structurally unique BST's (binary search trees) that
// store values 1...n?
//
// For example,
// Given n = 3, there are a total of 5 unique BST's.
//
//   1         3     3      2      1
//    \       /     /      / \      \
//     3     2     1      1   3      2
//    /     /       \                 \
//   2     1         2                 3
//
//============================================================================

#include <iostream>
#include <algorithm>

const int MAXN = 1000;
int dp[MAXN];

int go(int i)
{
    if (i == 0 || i == 1) return 1;

    if (dp[i] > 0) return dp[i];

    for (int j = 0; j < i; j++) {
        dp[i] += go(j) * go(i-j-1);
    }

    return dp[i];
}

int num_trees(int n)
{
    std::fill_n(dp, n+1, 0);

    return go(n);
}

int main(void)
{
    std::cout << num_trees(3) << std::endl;
    return 0;
}

