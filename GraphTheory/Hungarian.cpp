#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;
typedef int Weight;

#define REP(i,n) for(int i = 0; i < (int)n; ++i)
#define FOR(i,c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)

struct Edge 
{
    int src, dst;
    Edge(int src, int dst) 
        :src(src), dst(dst) {}
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
typedef vector<Weight> Array;
typedef vector<Array> Matrix;

Weight Hungarian(const Matrix &a)
{
    int n = a.size(), p, q;
    Array fx(n, INF), fy(n, 0);
    vector<int> x(n, -1), y(n, -1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            fx[i] = max(fx[i], a[i][j]);
    }

    for (int i = 0; i < n; ) {
        vector<int> t(n, -1), s(n+1, i);
        for (p = q = 0; p <= q && x[i] < 0; ++p) {
            for (int k = s[p], j = 0; j < n && x[i] < 0; ++j) {
                if (fx[k] + fy[j] == a[k][j] && t[j] < 0) {
                    s[++q] = y[j], t[j] = k;
                    if (s[q] < 0)
                        for (p = j; p >= 0; j = p)
                            y[j] = k = t[j], p = x[k], x[k] = j;
                }
            }
        }

        if (x[i] < 0) {
            Weight d = INF;
            for (int k = 0; k <= q; ++k) 
                for (int j = 0; j < n; ++j)
                    if (t[j] < 0) d = min(d, fx[s[k]] + fy[j] - a[s[k]][j]);
            for (int j = 0; j < n; ++j) fy[j] += (t[j] < 0 ? 0 : d);
            for (int k = 0; k <= q; ++k) fx[s[k]] -= d;
        } else {
            ++i;
        }
    }

    Weight ret = 0;
    for (int i = 0; i < n; ++i)
        ret += a[i][x[i]];
    return ret;
}

int main(void)
{
    return 0;
}
