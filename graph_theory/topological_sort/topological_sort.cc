#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include "utils/graph.h"

bool visit(const Graph &g, int v, std::vector<int> &order, std::vector<int> &color)
{
    color[v] = 1;
    FOR(e, g[v]) {
        if (color[e->dst] == 2) continue;
        if (color[e->dst] == 1) return false;
        if (!visit(g, e->dst, order, color)) return false;
    }
    order.push_back(v); color[v] = 2;
    return true;
}

bool TopologicalSort(const Graph &g, std::vector<int> &order)
{
    int n = g.size();
    std::vector<int> color(n);

    REP(u, n) if (!color[u] && !visit(g, u, order, color))
        return false;

    reverse(ALL(order));
    return true;
}

void TopologicalSort_ByDegree(std::vector<std::vector<bool>> G, std::vector<int> inDeg, std::vector<int> &order)
{
    int n = G.size();
    int zeroCnt, zero;

    REP(i, n) inDeg[i] = 0;

    REP(i, n) REP(j, n) if (G[i][j]) {
        inDeg[j] += 1;
    }

    REP(i, n) {
        zeroCnt = 0;
        REP(j, n) if (inDeg[j] == 0) {
            zeroCnt += 1; zero = j;
        }

        order.push_back(zero);
        inDeg[zero] = -1;

        REP(j, n) if (G[i][j]) {
            inDeg[j] -= 1;
        }
    }
}


int main(void)
{
    int n, m;
    while (std::cin >> n >> m) {
        if (n == 0 && m == 0) break;

        char a, b, rel;
        Graph g(n);
        REP(i, m) {
            std::cin >> a >> rel >> b;

            if (rel == '>') {
                g[a-'A'].push_back(Edge(a-'A', b-'A'));
            } else if (rel == '<') {
                g[b-'A'].push_back(Edge(b-'A', a-'A'));
            }
        }

        std::vector<int> order;
        std::cout << TopologicalSort(g, order) << std::endl;
    }
    return 0;
}
