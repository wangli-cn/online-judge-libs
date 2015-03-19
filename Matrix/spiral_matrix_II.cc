//============================================================================
// Spiral Matrix II
// Given an integer n, generate a square matrix filled with elements from 1 to
// n2 in spiral order.
//
// For example,
// Given n = 3,
//
// You should return the following matrix:
// [
// [ 1, 2, 3 ],
// [ 8, 9, 4 ],
// [ 7, 6, 5 ]
// ]
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

void go(vector<vector<int> > &res, int seq, int n, int k)
{
    if (n <= 0) return;
    if (n == 1) {
        res[k][k] = seq++;
        return;
    }

    for (int i = 0; i < n-1; i++) {
        res[k][k+i] = seq++;
    }

    for (int i = 0; i < n-1; i++) {
        res[k+i][k+n-1] = seq++;
    }

    for (int i = n-1; i > 0; i--) {
        res[k+n-1][k+i] = seq++;
    }

    for (int i = n-1; i > 0; i--) {
        res[k+i][k] = seq++;
    }

    go(res, seq, n-2, k+1);
}

vector<vector<int> > gen_spiral_matrix(int n)
{
    vector<vector<int> > res(n, vector<int>(n, 0));

    go(res, 1, n, 0);
    return res;
}

int main(void)
{
    vector<vector<int> > res = gen_spiral_matrix(5);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
