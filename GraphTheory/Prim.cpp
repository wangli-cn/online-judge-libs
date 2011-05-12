#include <iostream>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;
typedef int Weight;

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

pair<Weight, Edges> Prim(const Graph &g, int r = 0)
{
    int n = g.size();
    Edges T;
    Weight total = 0;

    vector<bool> visited(n);
    priority_queue<Edge> Q;
    for (Q.push(Edge(-1, r, 0)); !Q.empty(); ) {
        Edge e = Q.top(); Q.pop();
        if (visited[e.dst]) continue;
        T.push_back(e);
        total += e.weight;
        visited[e.dst] = true;
        FOR(f, g[e.dst]) if (!visited[f->dst]) Q.push(*f);
    }
    return pair<Weight, Edges>(total, T);
}

int main(void)
{
    return 0;
}
