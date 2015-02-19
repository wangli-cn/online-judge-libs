#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "graphtool.h"

using namespace std;

#define REP(i, n) for(int i = 0; i < (int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)


bool BellmanFord(const Graph &g, int s, vector<Weight> &dist, vector<int> &prev)
{
    const int n = g.size();
    dist.assign(n, INF + INF); dist[s] = 0;
    prev.assign(n, -1);
    bool negative_cycle = false;

    REP(k, n) REP(i, n) FOR(e, g[i]) {
        if (dist[e->dst] > dist[e->src] + e->weight) {
            dist[e->dst] = dist[e->src] + e->weight;
            prev[e->dst] = e->src;
            if (k == n-1) {
                dist[e->dst] = -INF;
                negative_cycle = true;
            }
        }
    }
    return !negative_cycle;
}

vector<int> buildPath(const vector<int> &prev, int t)
{
    vector<int> path;
    for (int u = t; u >= 0; u = prev[u]) {
        path.push_back(u);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    vector<Weight> dist;
    vector<int> prev;
    Graph g;

    g.resize(3);
    g[0].push_back(Edge(0, 1, 101));
    g[1].push_back(Edge(1, 2, 1));
    g[2].push_back(Edge(2, 0, 10000));

    BellmanFord(g, 0, dist, prev);
    vector<int> path = buildPath(prev, 2);

    cout << dist[2] << endl;
    copy(path.begin(), path.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
