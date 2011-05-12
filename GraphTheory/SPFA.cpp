#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>

using namespace std;

const double INF = 1e20;

#define FOR(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define REP(i, n) for(int i = 0; i < (int)n; ++i)

typedef double Weight;

struct Edge 
{
    int src, dst;
    Weight weight;
    Edge(int src, int dst, Weight weight)
        :src(src), dst(dst), weight(weight) {}
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

bool SPFA(const Graph &g, int s, double guess, vector<Weight> &dist, vector<int> &prev)
{
    const int n = g.size();
    dist.assign(n, INF); dist[s] = 0;
    prev.assign(n, -1);
    bool negative_cycle = false;

    vector<bool> inQ(n, false);
    vector<int> cnt(n, 0);
    queue<int> Q; Q.push(s); inQ[s] = true; 
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        inQ[u] = false;

        FOR(e, g[u]) {
            double w = e->weight - guess;
            if (dist[u] + w < dist[e->dst]) {
                dist[e->dst] = dist[u] + w;
                if (!inQ[e->dst]) {
                    Q.push(e->dst);
                    inQ[e->dst] = true;
                    prev[e->dst] = e->src;
                    cnt[e->dst] += 1;

                    if (cnt[e->dst] >= n) {
                        negative_cycle = true;
                        return true;
                    }
                }
            }
        }
    }

    return negative_cycle;
}

bool DFS_visit(const Graph &g, int u, int v, vector<int> &color, int &time)
{
    color[v] = 1;
    time += 1;
    bool cycle = false;

    FOR(e, g[v]) {
        if (color[e->dst] == 0) {
            if (DFS_visit(g, v, e->dst, color, time)) return true;
        }
        else if (color[e->dst] == 1) {
            cycle = true;
        }
    }

    color[v] = 2;
    return cycle;
}

bool DFS(const Graph &g)
{
    const int n = g.size();
    vector<int> color(n);
    int time = 0;
    REP(i, n) {
        if (color[i] == 0) {
            if (DFS_visit(g, -1, i, color, time)) {
                return true;
            }
        }
    }
    return false;
}

int main(void)
{
    int L, P;
    int x, y, w;
    int nCase;

    scanf("%d", &nCase);
    for (int c = 1; c <= nCase; ++c) {
        scanf("%d %d", &L, &P);

        Graph g(L+1);
        for (int i = 0; i < P; ++i) {
            scanf("%d %d %d", &x, &y, &w);
            g[x-1].push_back(Edge(x-1, y-1, (double)w));
        }

        for (int i = 0; i < L; ++i) {
            g[L].push_back(Edge(L, i, 0.0));
        }

        if (!DFS(g)) {
            printf("Case #%d: No cycle found.\n", c);
            continue;
        }

        double l = 0.0, r = 1e9;
        while (r-l > 1e-4) {
            double mid = (l+r)/2;

            vector<Weight> dist;
            vector<int> prev;
            if (SPFA(g, L, mid, dist, prev)) {
                r = mid;
            } else {
                l = mid;
            }
        }

        double x = floor(l * 100 + 0.5) / 100.0;
        printf("Case #%d: %.2lf\n", c, x);
    }

    return 0;
}
