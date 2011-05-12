/********************************************
 * Field Testing:
 *     - POJ 1505: Copying Books
 ********************************************
 */
#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

const int MAXN = 505;
int f[MAXN][MAXN];
int book[MAXN], total[MAXN];

int Sum(int s, int e)
{
    return (total[e] - total[s-1]);
}

int DP(int i, int j)
{
    if (f[i][j] != -1) return f[i][j];
    if (j == 0) return f[i][j] = 0;
    if (i == 0) return f[i][j] = INT_MAX;

    int tmp;
    f[i][j] = INT_MAX;
    for (int k = i-1; k < j; ++k) {
        tmp = max(DP(i-1, k), Sum(k+1, j));
        f[i][j] = min(tmp, f[i][j]);
    }
    return f[i][j];
}

int main(void)
{
    int nCase;
    int k, m;

    scanf("%d", &nCase);
    while (nCase--) {
        scanf("%d%d", &m, &k);
        for (int i = 1; i <= m; ++i)
            scanf("%d", &book[i]);
        
        total[0] = 0;
        for (int i = 1; i <= m; ++i)
            total[i] = total[i-1] + book[i];

        memset(f, -1, sizeof(f));
        bool slash[MAXN];
        int maximum = DP(k, m);
        int tmp = 0, p = k;
        memset(slash, false, sizeof(slash));
        for (int i = m; i > 0; --i) {
            if (tmp + book[i] > maximum || i < p) {
                slash[i] = true;
                tmp = book[i];
                p--;
            } else {
                tmp += book[i];
            }
        }

        for (int i = 1; i <= m; ++i) {
            printf("%d", book[i]);
            if (slash[i]) printf(" / ");
            else if (i != m) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
