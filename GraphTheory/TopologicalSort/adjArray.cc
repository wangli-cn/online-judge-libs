#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

#define REP(i,n) for (int i = 0; i < (int)n; ++i)
#define FOR(i,c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

const int MAXN = 27;

bool G[MAXN][MAXN];
int n;

bool visit(int v, vector<int> &order, vector<int> &color) 
{
    color[v] = 1;
    REP(w, n) if (G[v][w]) {
        if (color[w] == 2) continue;
        if (color[w] == 1) return false;
        if (!visit(w, order, color)) return false;
    }

    order.push_back(v); color[v] = 2;
    return true;
}

bool TopologicalSort(vector<int> &order)
{
    vector<int> color(n);
    REP(u, n) if (!color[u] && !visit(u, order, color)) {
        return false;
    }

    reverse(ALL(order));
    return true;
}

int main(void)
{
    int m;
    while (scanf("%d %d ", &n, &m) == 2) {
        if (n == 0 && m == 0) break;

        REP(i, n) REP(j, n) G[i][j] = 0;
    
        char a, b, rel;
        REP(i, m) {
            cin >> a >> rel >> b;

            if (rel == '>') {
                G[a-'A'][b-'A'] = true;
            } else if (rel == '<') {
                G[b-'A'][a-'A'] = true;
            }
        }

        vector<int> order;
        cout << TopologicalSort(order) << endl;
    }
    return 0;
}
