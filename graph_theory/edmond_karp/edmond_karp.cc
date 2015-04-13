#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>
#include "utils/graph.h"

#define RESIDUE(s,t) (capacity[s][t] - flow[s][t])

Weight EdmondKarp(const Graph &g, int s, int t)
{
    int n = g.size();
    Matrix flow(n , Array(n)), capacity(n, Array(n));
    REP(u, n) FOR(e, g[u]) capacity[e->src][e->dst] += e->weight;

    Weight total = 0;
    while (1) {
        std::queue<int> Q; Q.push(s);
        std::vector<int> prev(n, -1); prev[s] = s;
        while (!Q.empty() && prev[t] < 0) {
            int u = Q.front(); Q.pop();
            FOR(e, g[u]) if (prev[e->dst] < 0 && RESIDUE(u, e->dst)) {
                prev[e->dst] = u;
                Q.push(e->dst);
            }
        }
        if (prev[t] < 0) return total;
        Weight inc = INF;
        for (int j = t; prev[j] != j; j = prev[j])
            inc = std::min(inc, RESIDUE(prev[j], j));
        for (int j = t; prev[j] != j; j = prev[j])
            flow[prev[j]][j] += inc, flow[j][prev[j]] -= inc;
        total += inc;
    }
}

int main()
{
    int N, M;
    int src, dst;

    while (std::cin >> N && N) {
        Graph g;
        g.resize(N);

        std::cin >> src >> dst >> M;
        REP(i, M) {
            int x, y, c;
            std::cin >> x >> y >> c;
            g[x].push_back(Edge(x, y, c));
        }

        std::cout << EdmondKarp(g, src, dst) << std::endl;
    }
    return 0;
}
