#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <climits>
#include <algorithm>

using namespace std;

const int INF = INT_MAX;
typedef int Weight;

#define REP(i,n) for(int i = 0; i < (int)n; ++i)
#define FOR(i,c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()

struct Edge 
{
    int src, dst;
    Weight weight;
    Edge(int src, int dst, Weight weight) 
        :src(src), dst(dst), weight(weight) {}
};

bool operator<(const Edge &e, const Edge &f)
{
    return (e.weight != f.weight) ? e.weight > f.weight :
           (e.src != f.src) ? e.src > f.src : e.dst > f.dst;
}

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
typedef vector<Weight> Array;
typedef vector<Array> Matrix;

bool Johnson(const Graph &g, Matrix &dist, vector< vector<int> > &prev)
{
    int n = g.size();
    Array h(n+1);
    REP(k, n) REP(i, n) FOR(e, g[i]) {
        if (h[e->dst] > h[e->src] + e->weight) {
            h[e->dst] = h[e->src] + e->weight;
            if (k == n-1) return false; //negative cycle
        }
    }

    dist.assign(n, Array(n, INF));
    prev.assign(n, vector<int>(n, -2));
    REP(s, n) {
        priority_queue<Edge> Q;
        for (Q.push(Edge(s, s, 0)); !Q.empty(); ) {
            Edge e = Q.top(); Q.pop();
            if (prev[s][e.dst] != -2) continue;
            prev[s][e.dst] = e.src;
            FOR(f, g[e.dst]) {
                if (dist[s][f->dst] > e.weight + f->weight) {
                    dist[s][f->dst] = e.weight + f->weight;
                    Q.push(Edge(f->src, f->dst, e.weight + f->weight));
                }
            }
        }
        REP(u, n) dist[s][u] += h[u] - h[s];
    }
}

vector<int> buildPath(const vector< vector<int> > &prev, int s, int t)
{
    vector<int> path;
    for (int u = t; u >= 0; u = prev[s][u]) 
        path.push_back(u);
    reverse(ALL(path));
    return path;
}

int main(void)
{
    return 0;
}
