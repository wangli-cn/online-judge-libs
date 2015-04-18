//============================================================================
// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
// containing all ones and return its area.
//
// Field Test: http://tioj.ck.tp.edu.tw/problems/1063
//============================================================================

#include <iostream>
#include <vector>

using VVI = std::vector<std::vector<int>>;

int go(const VVI& matrix, VVI& dp, int i, int j)
{
    if (dp[i][j] > -1) return dp[i][j];

    if (j == 0) return dp[i][j] = (matrix[i][j] == 1 ? 1 : 0);

    int a = go(matrix, dp, i, j-1);
    if (matrix[i][j] == 1) {
        if (j > 0) {
            dp[i][j] = a + 1;
        } else {
            dp[i][j] = 1;
        }

        return dp[i][j];
    } else {
        return dp[i][j] = 0;
    }
}


int maximal_rectangle(const VVI& matrix)
{
    int R = matrix.size();
    int C = matrix[0].size();

    VVI dp(R, std::vector<int>(C, -1));

    for (int i = 0; i < R; i++) {
        go(matrix, dp, i, C-1);
    }

    int res = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int minimum = dp[i][j];
            int k = i;
            while (k >= 0) {
                if (dp[k][j] < minimum) minimum = dp[k][j];
                res = std::max(res, minimum * (i-k+1));
                k--;
            }
        }
    }

    return res;
}


int main(void)
{
    int m, n, elm;

    std::cin >> m >> n;
    VVI matrix(m, std::vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> elm;
            matrix[i][j] = elm;
        }
    }

    std::cout <<  maximal_rectangle(matrix) << std::endl;
    return 0;
}
