// Given a matrix consisting only 0s and 1s, find the maximum size square sub-matrix with all 1s
#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<char> > VVC;
typedef vector<vector<int> > VVI;

int go(VVC &matrix, VVI &dp, int i, int j)
{
    if (dp[i][j] > 0) return dp[i][j];

    if (j == 0) return dp[i][j] = (matrix[i][j] == '1' ? 1 : 0);
    if (i == 0) return dp[i][j] = (matrix[i][j] == '1' ? 1 : 0);

    if (matrix[i][j] == '1') {
        int left = go(matrix, dp, i, j-1);
        int up_left = go(matrix, dp, i-1, j-1);
        int up = go(matrix, dp, i-1, j);

        return dp[i][j] = min(left, min(up_left, up)) + 1;
    } else {
        return dp[i][j] = 0;
    }
}

int maximal_square(VVC &matrix)
{
    int R = matrix.size();
    int C = matrix[0].size();

    VVI dp(R, vector<int>(C, 0));
    return go(matrix, dp, R-1, C-1);
}

int main(void)
{
    VVC matrix(10, vector<char>(10, '1'));
    matrix[5][5] = '0';

    cout <<  maximal_square(matrix) << endl;
    return 0;
}
