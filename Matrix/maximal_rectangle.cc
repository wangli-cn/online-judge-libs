//============================================================================
// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
// containing all ones and return its area.
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<char> > VVC;
typedef vector<vector<int> > VVI;

int go(VVC &matrix, VVI &dp, int i, int j)
{
    if (dp[i][j] > 0) return dp[i][j];

    if (j == 0) return (matrix[i][j] == '1' ? 1 : 0);

    if (matrix[i][j] == '1') {
        if (j > 0) {
            dp[i][j] = go(matrix, dp, i, j-1) + 1;
        } else {
            dp[i][j] = 1;
        }

        return dp[i][j];
    } else {
        return dp[i][j] = 0;
    }
}

int maximal_rectangle(VVC &matrix)
{
    int R = matrix.size();
    int C = matrix[0].size();

    VVI dp(R, vector<int>(C, 0));

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
                res = max(res, minimum * (i-k+1));
                k--;
            }
        }
    }

    return res;
}

int main(void)
{
    VVC matrix(10, vector<char>(10, '1'));

    cout <<  maximal_rectangle(matrix) << endl;
    return 0;
}
