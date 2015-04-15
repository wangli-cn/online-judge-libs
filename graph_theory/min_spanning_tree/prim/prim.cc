#include <iostream>
#include <queue>
#include <limits>
#include "utils/graph.h"

std::pair<Weight, Edges> Prim(const Graph &g, int r = 0)
{
    int n = g.size();
    Edges T;
    Weight total = 0;

    std::vector<bool> visited(n, false);
    std::priority_queue<Edge> Q;
    for (Q.push(Edge(-1, r, 0)); !Q.empty(); ) {
        Edge e = Q.top(); Q.pop();
        if (visited[e.dst]) continue;
        T.push_back(e);
        total += e.weight;
        visited[e.dst] = true;
        FOR(f, g[e.dst]) if (!visited[f->dst]) Q.push(*f);
    }

    return std::move(std::pair<Weight, Edges>(total, T));
}

int main(void)
{
    int n, m;

    while (std::cin >> n >> m) {
        if (n == 0 && m == 0) break;

        Graph g;
        g.resize(n);
        for (int i = 0; i < m; i++) {
            int a, b, w;
            std::cin >> a >> b >> w;
            g[a-1].push_back(Edge(a-1, b-1, w));
        }

        auto ans = Kruskal(g);
        if (ans.second.size() != (n-1)) {
            std::cout << -1 << std::endl;
        } else {
            std::cout << ans.first << std::endl;
        }
    }

    return 0;
}
