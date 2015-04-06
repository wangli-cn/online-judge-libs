#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <limits>
#include <algorithm>
#include "utils/graph.h"


class UnionFind
{
public:
    std::vector<int> data;

    UnionFind(int size) :data(size, -1) {}

    bool unionSet(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (data[y] < data[x]) std::swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }

    bool findSet(int x, int y) {
        return root(x) == root(y);
    }

    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }

    int size(int x) {
        return -data[root(x)];
    }
};


std::pair<Weight, Edges> Kruskal(const Graph &g)
{
    int n = g.size();
    UnionFind uf(n);
    std::priority_queue<Edge> Q;

    REP(u, n) FOR(e, g[u]) if (u < e->dst) Q.push(*e);

    Weight total = 0;
    Edges F;
    while (F.size() < n-1 && !Q.empty()) {
        Edge e = Q.top(); Q.pop();
        if (uf.unionSet(e.src, e.dst)) {
            F.push_back(e);
            total += e.weight;
        }
    }

    return std::move(std::pair<Weight, Edges>(total, F));
}


int main()
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
