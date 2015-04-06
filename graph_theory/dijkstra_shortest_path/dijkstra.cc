#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <algorithm>
#include "utils/graph.h"

void dijkstra(const Graph &g, int s, std::vector<Weight> &dist, std::vector<int> &prev)
{
    const int n = g.size();
    dist.assign(n, INF); dist[s] = 0;
    prev.assign(n, -1);

    std::priority_queue<Edge> Q;
    for (Q.push(Edge(-2, s, 0)); !Q.empty(); ) {
        Edge e = Q.top(); Q.pop();
        if (prev[e.dst] != -1) continue;

        prev[e.dst] = e.src;
        FOR(f, g[e.dst]) if (dist[f->dst] > e.weight + f->weight) {
            dist[f->dst] = e.weight + f->weight;
            Q.push(Edge(f->src, f->dst, e.weight + f->weight));
        }
    }
}

std::vector<int> buildPath(const std::vector<int> &prev, int t)
{
    std::vector<int> path;
    for (int u = t; u >= 0; u = prev[u])
        path.push_back(u);
    reverse(path.begin(), path.end());
    return path;
}

int main(void)
{
    std::vector<Weight> dist;
    std::vector<int> prev;
    Graph g;

    g.resize(3);
    g[0].push_back(Edge(0, 1, 101));
    g[1].push_back(Edge(1, 2, 1));
    g[2].push_back(Edge(2, 0, 10000));

    dijkstra(g, 0, dist, prev);
    std::vector<int> path = buildPath(prev, 2);

    std::cout << dist[2] << std::endl;
    std::copy(path.begin(), path.end(), std::ostream_iterator<int>(std::cout, " "));

    return 0;
}

