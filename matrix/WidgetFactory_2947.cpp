#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

typedef int Number;
typedef vector<Number> Array;
typedef vector<Array> Matrix;

const char *DoW = "SUN MON TUE WED THU FRI SAT";

int get_weekday(const char *s)
{
    return (strstr(DoW, s) - DoW) / 4;
}

int egcd(int a, int b, int &x, int &y)
{
    if (b == 0) {
        x = 1; y = 0;
        return a;
    } else {
        int d = egcd(b, a % b, y, x);
        y -= (a/b) * x;
        return d;
    }
}

int mod(int x, int n)
{
    return (x % n + n) % n;
}

int mod_inverse(int a, int n) 
{
    int d, x, y;
    d = egcd(a, n, x, y);
    return d == 1 ? mod(x, n) : -1;
}

int gauss(Matrix &A)
{
    int n = A.size(), m = A[0].size();

    int r = 0;
    for (int i = 0; r < n && i < m-1; ++i) {
        int pivot = r;
        for (int j = r+1; j < n; ++j) {
            if (A[j][i] != 0) { 
                pivot = j; 
                break; 
            }
        }
        swap(A[pivot], A[r]);

        if (A[r][i] == 0) continue;

        int inverse = mod_inverse(A[r][i], 7);
        for (int k = m-1; k >= i; --k) 
            A[r][k] = (A[r][k] * inverse) % 7;

        for (int j = 0; j < n; ++j) {
            if (j == r) continue;
            if (A[j][i] == 0) continue;
            for (int k = m-1; k >= i; --k) {
                A[j][k] = (A[j][k] - A[r][k] * A[j][i] + 700) % 7;
            }
        }

        r++;
    }
    
    //printf("rank = %d\n", r);
    //for (int i = 0; i < n; i++) {
        //for (int j = 0; j < m; j++) {
            //printf("%d ", A[i][j]);
        //}
        //printf("\n");
    //}

    for (int i = r; i < n; ++i) {
        if (A[i][m-1] != 0) return -1;
    }

    if (r == m-1) return 1;
    else return 2; 
}

int main(void)
{
    int n, m, k;
    char start[4], end[4];
    int widget_id;

    while (scanf("%d %d", &n, &m) == 2 && n && m) {
        Matrix A(m, Array(n+1));
        for (int i = 0; i < m; i++) {
            scanf("%d %s %s ", &k, start, end);

            for (int j = 0; j < k; ++j) {
                scanf("%d", &widget_id);
                A[i][widget_id-1] = (A[i][widget_id-1] == 6) ? 0 : A[i][widget_id-1] + 1;
            }

            int s = get_weekday(start);
            int e = get_weekday(end);
            A[i][n] = (e - s + 70 + 1) % 7;
        }

        int ans = gauss(A);
        if (ans == -1) printf("Inconsistent data.\n");
        else if (ans == 2) printf("Multiple solutions.\n");
        else {
            for (int i = 0; i < n; i++) {
                if (i != 0) printf(" ");
                printf("%d", A[i][n] + (A[i][n] < 3 ? 7 : 0));
            }
            printf("\n");
        }
    }

    return 0;
}
