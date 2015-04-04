#include <iostream>
#include "utils/graph.h"

int flip(int c)
{
    if (c == 1) return 2;
    else return 1;
}

bool visit(const Graph &g, int v, int c, vector<int> &color)
{
    color[v] = c;
    for (auto& e: g[v]) {
        if (color[e.dst] == c) return false;
        if (color[e.dst] == flip(c)) continue;
        if (!visit(g, e.dst, flip(c), color)) return false;
    }

    return true;
}

bool bipartite_detect(const Graph &g, int root)
{
    int n = g.size();
    vector<int> color(n, 0);

    for (int u = 0; u < n; u++) {
        if (!color[u] && !visit(g, u, 1, color)) {
            return false;
        }
    }

    return true;
}

int main()
{
    int n, m;

    while (std::cin >> n >> m) {
        if (n == 0 && m == 0) break;

        Graph g;
        g.resize(n);
        for (int i = 0; i < m; i++) {
            int a, b;
            std::cin >> a >> b;
            g[a-1].push_back(Edge(a-1, b-1, 1));
            g[b-1].push_back(Edge(b-1, a-1, 1));
        }

        bool ans = bipartite_detect(g, 0);
        if (ans) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }


    return 0;
}
