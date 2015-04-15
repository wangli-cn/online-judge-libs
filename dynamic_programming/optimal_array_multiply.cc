#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;

void show(int i, int j, vector< vector<int> > &s)
{
    if (j > i) {
        cout << "(";
        show(i, s[i][j], s);
        cout << " x ";
        show(s[i][j]+1, j, s);
        cout << ")";
    } else {
        cout << "A" << i+1;
    }
}

int matrix_chain(vector<int> &p, vector< vector<int> > &s)
{
    const int n = p.size()-1;
    vector< vector<int> > X(n, vector<int>(n, INF));
    s.resize(n, vector<int>(n));
    for (int i = 0; i < n; ++i) X[i][i] = 0;
    for (int w = 1; w < n; ++w) {
        for (int i = 0, j; j = i+w, j < n; ++i)
            for (int k = i, f; k < j; ++k) {
                int f = p[i] * p[k+1] * p[j+1];
                if (X[i][k] + X[k+1][j] + f < X[i][j]) {
                    X[i][j] = X[i][k] + X[k+1][j] + f;
                    s[i][j] = k;
                }
            }
    }
    return X[0][n-1];
}

int main(void)
{
  return 0;
}
