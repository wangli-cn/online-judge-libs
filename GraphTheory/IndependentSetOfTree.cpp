#include <iostream>
#include <vector>
#include <cstring>
#include "graphtool.h"

using namespace std;

const int MAXN = 205;
int f[MAXN][2], s[MAXN][2];

int DP(const Graph &g, int v, int u, int flag)
{
    if (f[v][flag] != -1) return f[v][flag];

    if (!flag) {
        int sum = 0;
        FOR(e, g[v]) if (e->dst != u) {
            if (DP(g, e->dst, v, 0) == DP(g, e->dst, v, 1)) {
                sum += DP(g, e->dst, v, 0);
                s[v][0] = 1;
            } else if (DP(g, e->dst, v, 0) > DP(g, e->dst, v, 1)) {
                sum += DP(g, e->dst, v, 0);
                if (s[e->dst][0] == 1) s[v][0] = 1;
            } else {
                sum += DP(g, e->dst, v, 1);
                if (s[e->dst][1] == 1) s[v][0] = 1;
            }
        }
        f[v][0] = sum;
    } else {
        int sum = 1;
        FOR(e, g[v]) if (e->dst != u) {
            sum += DP(g, e->dst, v, 0);
            if (s[e->dst][0] == 1) s[v][1] = 1;
        }
        f[v][1] = sum;
    }
    return f[v][flag];
}

int main(void)
{
    memset(f, -1, sizeof(f));
    memset(s, -1, sizeof(s));

    Graph g;
    g.resize(3);
    g[0].push_back(Edge(0, 1));
    g[0].push_back(Edge(0, 2));
    g[1].push_back(Edge(1, 0));
    g[2].push_back(Edge(2, 0));

    int a = DP(g, 0, -1, 0);
    int b = DP(g, 0, -1, 1);
    if (a == b) cout << a << " No" << endl;
    else if (a > b) {
        if (s[0][0] == 1) cout << a << " No" << endl;
        else cout << a << " Yes" << endl;
    } else {
        if (s[0][1] == 1) cout << b << " No" << endl;
        else cout << b << " Yes" << endl;
    }
    return 0;
}
