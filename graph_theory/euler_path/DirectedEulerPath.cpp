#include <iostream>
#include <vector>
#include <algorithm>
#include "utils/graph.h"

void visit(Graph &g, int a, vector<int> &path)
{
    while (!g[a].empty()) {
        int b = g[a].back().dst;
        g[a].pop_back();
        visit(g, b, path);
    }
    path.push_back(a);
}

bool eulerPath(Graph g, int s, vector<int> &path)
{
    int n = g.size(), m = 0;
    vector<int> deg(n);
    REP(u, n) {
        m += g[u].size();
        FOR(e, g[u]) --deg[e->dst];
        deg[u] += g[u].size();
    }

    int k = n - count(ALL(deg), 0);
    if (k == 0 || (k == 2 && deg[s] == 1)) {
        path.clear();
        visit(g, s, path);
        reverse(ALL(path));
        return path.size() == m+1;
    }
    return false;
}

int main(void)
{
    return 0;
}
