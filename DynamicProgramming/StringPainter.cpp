#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

const int MAXN = 105;

string A, B;

int f[MAXN][MAXN][27];

int DP(int i, int j, int c)
{
    if(f[i][j][c] >= 0)
        return f[i][j][c];

    if(i > j) return 0;

    char ch = 'a' + c;
    f[i][j][c] = MAXN;
    if(c == 26) {
        if (i == j) {
            if (B[i] == A[i]) return (f[i][i][c] = 0);
            else return (f[i][i][c] = 1);
        }

        if (B[i] == A[i]) f[i][j][c] = min(f[i][j][c], DP(i+1, j, c));
        else {
            for (int k = i; k <= j; k++) {
                if(B[i] == B[k]) 
                    f[i][j][c] = min(f[i][j][c], DP(i+1, k-1, B[i]-'a') + 1 + DP(k+1, j, c));
            }
        }

        if (B[j] == A[j]) f[i][j][c] = min(f[i][j][c], DP(i, j-1, c));
        else {
            for (int k = j; k >= i; k--) {
                if (B[j] == B[k]) 
                    f[i][j][c] = min(f[i][j][c], DP(i, k-1, c) + 1 + DP(k+1, j-1, B[j]-'a'));
            }
        }
    } else {
        if (i == j) {
            if (B[i] == ch) return (f[i][i][c] = 0);
            else return (f[i][i][c] = 1);
        }

        for (int k = i; k <= j; k++) {
            if (B[i] == B[k]) {
                if (B[i] == ch) f[i][j][c] = min(f[i][j][c], DP(i+1, k-1, c) + DP(k+1, j, c));
                else f[i][j][c] = min(f[i][j][c], DP(i+1, k-1, B[i]-'a') + 1 + DP(k+1, j, c));
            }
        }

        for (int k = j; k >= i; k--) {
            if (B[j] == B[k]) {
                if (B[j] == ch) {
                    f[i][j][c] = min(f[i][j][c], DP(i, k-1, c) + DP(k+1, j-1, c));
                } else {
                    f[i][j][c] = min(f[i][j][c], DP(i, k-1, c) + 1 + DP(k+1, j-1, B[j]-'a'));
                }
            }
        }
    }

    /*cout << "(i, j, c) = " << "(" << i << ", " << j << ", " << c << ") = " << f[i][j][c] << endl;*/
    return f[i][j][c];
}

int main(void)
{
    while (cin >> A >> B) {
        memset(f, -1, sizeof(f)); 

        int size = A.length();
        cout << DP(0, size-1, 26) << endl;
    }

    return 0;
}

