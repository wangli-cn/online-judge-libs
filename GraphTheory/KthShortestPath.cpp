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

Weight k_shortestPath2(const Graph &g, int s, int t, int k)
{
    const int n = g.size();
    Graph h(n); //make reverse graph
    REP(u, n) FOR(e, g[u]) {
        h[e->dst].push_back(Edge(e->dst, e->src, e->weight));
    }

    vector<Weight> d(n, INF); d[t] = 0; //make potential
    vector<int> p(n, -1);
    priority_queue<Edge> Q; Q.push(Edge(t, t, 0));
    while (!Q.empty()) {
        Edge e = Q.top(); Q.pop();
        if (p[e.dst] >= 0) continue;
        p[e.dst] = e.src;
        FOR(f, h[e.dst]) if (d[f->dst] > e.weight + f->weight) {
            d[f->dst] = e.weight + f->weight;
            Q.push(Edge(f->src, f->dst, e.weight + f->weight));
        }
    }

    int l = 0; //forward dijkstra-like method
    priority_queue<Edge> R; R.push(Edge(-1, s, 0));
    while (!R.empty()) {
        Edge e = R.top(); R.pop();
        if (e.dst == t && ++l == k) return e.weight + d[s];
        FOR(f, g[e.dst]) {
            R.push(Edge(f->src, f->dst, e.weight + f->weight - d[f->src] + d[f->dst]));
        }
    }
    return -1; //not found
}

Weight k_shortestPath1(const Graph &g, int s, int t, int k)
{
    const int n = g.size();

    vector< vector<Weight> > dist(n);
    priority_queue<Edge> Q;
    for (Q.push(Edge(-1, s, 0)); !Q.empty(); ) {
        Edge e = Q.top(); Q.pop();
        if (dist[e.dst].size() >= k) continue;
        dist[e.dst].push_back(e.weight);
        FOR(f, g[e.dst]) 
            Q.push(Edge(f->src, f->dst, f->weight + e.weight));
    }
}

int main(void)
{
    return 0;
}
