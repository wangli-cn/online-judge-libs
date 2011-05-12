#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

#define REP(i,n) for (int i = 0; i < (int)n; ++i)
#define FOR(i,c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

const int MAXN = 105;

bool G[MAXN][MAXN];
int N, M;

bool visit(int v, vector<int> &order, vector<int> &color)
{
    color[v] = 1;
    REP(w, N) if (G[v][w]) {
        if (color[w] == 2) continue;
        if (color[w] == 1) return false;
        if (!visit(w, order, color)) return false;
    }

    order.push_back(v); color[v] = 2;
    return true;
}

bool TopologicalSort(vector<int> &order)
{
    vector<int> color(N);

    REP(i, N) if (!color[i] && !visit(i, order, color)) {
        return false;
    }
    
    reverse(ALL(order));
    return true;
}

int main(void)
{
    int x, y;

    while (cin >> N >> M) {
        if (N == 0 && M == 0) break;

        REP(i, N) REP(j, N) G[i][j] = 0; 

        REP(i, M) {
            cin >> x >> y;
            G[x-1][y-1] = true;
        }

        vector<int> order;
        TopologicalSort(order);

        REP(i, N) cout << (order[i]+1) << " ";
        cout << endl;
    }

    return 0;
}
