#include <iostream>
#include <vector>
#include <algorithm>
#include "utils/graph.h"

void visit(int v, const Graph &g, vector<int> &ord, vector<int> &num, int k)
{
    if (num[v] >= 0) return;
    num[v] = k;
    for (int i = 0; i < g[v].size(); ++i)
        visit(g[v][i].dst, g, ord, num, k);
    ord.push_back(v);
}

void stronglyConnectedComponents(const Graph &g, vector< vector<int> > &scc)
{
    const int n = g.size();

    Graph h(n);
    REP(u, n) FOR(e, g[u]) {
        h[e->dst].push_back(Edge(e->dst, e->src));
    }

    vector<int> num(n, -1), ord, dro;
    for (int i = 0; i < n; ++i) {
        visit(i, g, ord, num, i);
    }

    std::reverse(ord.begin(), ord.end());

    std::fill(num.begin(), num.end(), -1);
    for (int i = 0; i < n; ++i) {
        visit(ord[i], h, dro, num, i);
    }
}

int main(void)
{
    return 0;
}
