#include <iostream>
#include <vector>

using namespace std;

#define REP(i,n) for (int i = 0; i < (int)n; ++i)
const int MAXN = 5;

void spiral_print(int a[][MAXN], int M, int N, int k)
{
    if (M <= 0 || N <= 0) return;

    if (M == 1) {
        for (int j = 0; j < N; j++) {
            cout << a[k][k+j] << " ";
        }
        return;
    }

    if (N == 1) {
        for (int j = 0; j < M; j++) {
            cout << a[k+j][k] << " ";
        }
        return;
    }

    for (int j = 0; j < N-1; j++) {
        cout << a[k][k+j] << " ";
    }

    for (int j = 0; j < M-1; j++) {
        cout << a[k+j][k+N-1] << " ";
    }

    for (int j = 0; j < N-1; j++) {
        cout << a[k+M-1][k+N-1-j] << " ";
    }

    for (int j = 0; j < M-1; j++) {
        cout << a[k+M-1-j][k] << " ";
    }

    spiral_print(a, M-2, N-2, k+1);
}

void spiral_print(int a[][MAXN], int M, int N)
{
    spiral_print(a, M, N, 0);
}


int main(void)
{
    int a[5][5] = { {1, 2, 3, 4, 5},
                    {6, 7, 8, 9, 10},
                    {11, 12, 13, 14, 15},
                    {16, 17, 18, 19, 20},
                    {21, 22, 23, 24, 25}};

    REP(i, 5)  {
        REP(j, 5) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    spiral_print(a, 5, 5);

    return 0;
}

