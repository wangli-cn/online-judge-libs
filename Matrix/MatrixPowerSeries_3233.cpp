#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

typedef int Number;
typedef vector<Number> Array;
typedef vector<Array> Matrix;
int N, K, M;

Matrix identity(int n)
{
    Matrix A(n, Array(n));
    for (int i = 0; i < n; i++) 
        A[i][i] = 1;
    return A;
}

Matrix mul(const Matrix &A, const Matrix &B)
{
    Matrix C(A.size(), Array(B[0].size()));
    for (int i = 0; i < C.size(); i++) {
        for (int j = 0; j < C[0].size(); j++) {
            for (int k = 0; k < A[i].size(); ++k) {
                C[i][j] = (C[i][j] + ((A[i][k] * B[k][j]) % M)) % M;
            }
        }
    }
    return C;
}

Matrix pow(const Matrix &A, int e)
{
    return e == 0 ? identity(A.size()) :
           e % 2 == 0 ? pow(mul(A, A), e/2): mul(A, pow(A, e-1));
}

Matrix add(const Matrix &A, const Matrix &B)
{
    Matrix C(A.size(), Array(B[0].size()));
    for (int i = 0; i < C.size(); i++) {
        for (int j = 0; j < C[0].size(); j++) {
            C[i][j] = (A[i][j] + B[i][j]) % M;
        }
    }
    return C;
}

Matrix mod(const Matrix &A)
{
    Matrix C(A.size(), Array(A[0].size()));
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[0].size(); j++) {
            C[i][j] = A[i][j] % M;
        }
    }
    return C;
}

Matrix pow_sum(const Matrix &A, int k)
{
    Matrix AA = mod(A);
    if (k == 1) {
        return AA;
    } else {
        if (k % 2 == 0) {
            Matrix B = pow_sum(AA, k/2);
            Matrix O = pow(AA, k/2);
            return add(B, mul(O, B));
        } else {
            Matrix B = pow_sum(AA, (k-1)/2);
            Matrix O = pow(AA, (k-1)/2 + 1);
            return add(add(O, B), mul(O, B));
        }
    }
}

int main(void)
{
    int x;

    scanf("%d %d %d", &N, &K, &M);
    Matrix A(N, Array(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d ", &x); 
            A[i][j] = x % M;
        }
    }

    Matrix B = pow_sum(A, K);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N-1; j++) {
            printf("%d ", B[i][j]);
        }
        printf("%d\n", B[i][N-1]);
    }

    return 0;
}
