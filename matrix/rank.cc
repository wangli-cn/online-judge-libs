#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef double Number;
const Number EPS = 1e-8;
typedef vector<Number> Array;
typedef vector<Array> Matrix;

int rank(Matrix A)
{
    const int n = A.size(), m = A[0].size();
    int r = 0;
    for (int i = 0; r < n && i < m; ++i) {
        int pivot = r;
        for (int j = r+1; j < n; ++j)
            if (fabs(A[j][i]) > fabs(A[pivot][i])) pivot = j;
        swap(A[pivot], A[r]);
        if (fabs(A[r][i]) < EPS) continue;
        for (int k = m-1; k >= i; --k) 
            A[r][k] /= A[r][i];
        for (int j = r+1; j < n; ++j)
            for (int k = i; k < m; ++k)
                A[j][k] -= A[r][k] * A[j][i];
        ++r;
    }
    return r;
}

int main(void)
{
    return 0;
}
