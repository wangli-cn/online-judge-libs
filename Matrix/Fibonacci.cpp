#include <iostream>
#include <vector>

using namespace std;

typedef double Number;
const Number EPS = 1e-8;
typedef vector<Number> Array;
typedef vector<Array> Matrix;

Matrix identity(int n)
{
    Matrix A(n, Array(n));
    for (int i = 0; i < n; ++i)
        A[i][i] = 1;
    return A;
}

Matrix mul(const Matrix &A, const Matrix &B)
{
    Matrix C(A.size(), Array(B[0].size()));
    for (int i = 0; i < C.size(); ++i) 
        for (int j = 0; j < C[i].size(); ++j)
            for (int k = 0; k < A[i].size(); ++k)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

Matrix pow(const Matrix &A, int e)
{
    return e == 0 ? identity(A.size()) :
           e % 2 == 0 ? pow(mul(A, A), e/2) : mul(A, pow(A, e-1));
}

int main(void)
{
    Matrix F;
    F.resize(2);
    F[0].push_back(1);
    F[0].push_back(1);
    F[1].push_back(1);
    F[1].push_back(0);

    Matrix ans = pow(F, 5);
    cout << ans[0][1] << endl;

    return 0;
}
