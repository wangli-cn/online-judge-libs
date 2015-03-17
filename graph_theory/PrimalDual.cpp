#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>

using namespace std;

const int INF = 9999999;

#define REP(i, n) for(int i = 0; i < (int)n; ++i)
#define FOR(i,c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)

typedef int Weight;

struct Edge 
{
    int src, dst;
    Weight capacity, cost;
    Edge(int src, int dst, Weight capacity, Weight cost) 
        :src(src), dst(dst), capacity(capacity), cost(cost) {}
};

bool operator<(const Edge &e, const Edge &f)
{
    return (e.cost != f.cost) ? e.cost > f.cost :
           (e.src != f.src) ? e.src > f.src : e.dst > f.dst;
}

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;
#define RESIDUE(s,t) (capacity[s][t] - flow[s][t])
#define RCOST(s,t) (cost[s][t] + h[s] - h[t])

pair<Weight, Weight> PrimalDual(const Graph &g, int s, int t)
{
    const int n = g.size();
    Matrix capacity(n, Array(n)), cost(n, Array(n)), flow(n, Array(n));
    REP(u, n) FOR(e, g[u]) {
        capacity[e->src][e->dst] += e->capacity;
        cost[e->src][e->dst] += e->cost;
    }

    pair<Weight, Weight> total;
    vector<Weight> h(n);

    for (Weight F = INF; F > 0; ) {
        vector<Weight> dist(n, INF); dist[s] = 0;
        vector<int> prev(n, -1);
        priority_queue<Edge> Q;
        for (Q.push(Edge(-2, s, 0, 0)); !Q.empty(); ) {
            Edge e = Q.top(); Q.pop();
            if (prev[e.dst] != -1) continue;
            prev[e.dst] = e.src;
            FOR(f, g[e.dst]) if (RESIDUE(f->src, f->dst) > 0) {
                if (dist[f->dst] > dist[f->src] + RCOST(f->src, f->dst)) {
                    dist[f->dst] = dist[f->src] + RCOST(f->src, f->dst);
                    Q.push(Edge(f->src, f->dst, 0, dist[f->dst]));
                }
            }
        }

        if (prev[t] == -1) break;

        Weight f = F;
        for (int u = t; u != s; u = prev[u]) 
            f = min(f, RESIDUE(prev[u], u));
        for (int u = t; u != s; u = prev[u]) {
            total.first += f * cost[prev[u]][u];
            flow[prev[u]][u] += f; flow[u][prev[u]] -= f;
        }
        F -= f;
        total.second += f;
        REP(u, n) h[u] += dist[u];
    }
    return total;
}

int main(void)
{
    int N, M;
    int src, dst;

    while (cin >> N && N) {
        Graph g;
        g.resize(N);

        cin >> src >> dst >> M;
        REP(i, M) {
            int x, y, capacity, cost;
            cin >> x >> y >> capacity >> cost;
            g[x].push_back(Edge(x, y, capacity, cost));
        }

        pair<Weight, Weight> res = PrimalDual(g, src, dst);
        cout << res.first << " " << res.second << endl;
    }
    return 0;
}
