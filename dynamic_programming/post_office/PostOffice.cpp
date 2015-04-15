/********************************************
 * Field Testing:
 *     - POJ 1660: Post Office
 ********************************************
 */
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXP = 35;
const int MAXN = 10005;

#define REP(i,n) for(int i = 1; i <= (int)n; ++i)

long long d[MAXN];
long long m[MAXP][MAXN];
long long w[MAXN][MAXN];
long long s[MAXP][MAXN];

long long W(int i, int j)
{
    if (w[i][j] != -1) {
        return w[i][j]; 
    }

    if (j-i == 1) {
        return w[i][j] = d[j] - d[i];
    }

    int l = j-i;
    w[i][j] = W(i, j-1);
    for (int k = 0; k < ((l+1)/2); ++k) {
        w[i][j] += W(j-k-1, j-k);
    }
    return w[i][j];
}

long long DP(int i, int j)
{
    if (m[i][j] != -1) {
        return m[i][j];
    }

    if (i == 1) {
        s[i][j] = 0; s[j][j] = j-1;
        return m[i][j] = W(i, j);
    }

    for (int k = s[i-1][j]; k <= j-1; ++k) {
        if (m[i][j] == -1 || m[i][j] > DP(i-1, k) + W(k+1, j)) {
            m[i][j] = DP(i-1, k) + W(k+1, j);
            s[i][j] = k;
        }
    }

    return m[i][j];
}

int main(void)
{
    int n, k;

    while (scanf("%d %d", &n, &k) != EOF) {
        if (n == 0 && k == 0) 
            break;

        REP(i, n) scanf("%lld", &d[i]);
        REP(i, n) REP(j, n) w[i][j] = -1;
        REP(i, k) REP(j, n) m[i][j] = -1;

        printf("%lld\n", DP(k, n));
    }

    return 0;
}
