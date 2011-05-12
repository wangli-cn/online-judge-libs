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
    Weight weight;
    Edge(int src, int dst, Weight weight) 
        :src(src), dst(dst), weight(weight) {}
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

Weight StoerWagner(const Graph &g)
{
    int n = g.size();
    vector< vector<Weight> > h(n, vector<Weight>(n)); //adj matrix
    REP(u, n) FOR(e, g[u]) h[e->src][e->dst] += e->weight;
    vector<int> V(n); REP(u, n) V[u] = u;

    Weight cut = INF;
    for (int m = n; m > 1; m--) {
        vector<Weight> ws(m, 0);
        int u, v;
        Weight w;
        REP(k, m) {
            u = v; v = max_element(ws.begin(), ws.end()) - ws.begin();
            w = ws[v]; ws[v] = 1;
            REP(i, m) if (ws[i] >= 0) ws[i] += h[V[v]][V[i]];
        }

        REP(i, m) {
            h[V[i]][V[u]] += h[V[i]][V[v]];
            h[V[u]][V[i]] += h[V[v]][V[i]];
        }

        V.erase(V.begin()+v);
        cut = min(cut, w);
    }

    return cut;
}

int main(void)
{
    return 0;
}
