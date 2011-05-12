#include <iostream>
#include <vector>

using namespace std;

typedef int Weight;

#define FOR(i,c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)

struct Edge
{
    int src, dst;
    Weight weight;
    Edge(int src, int dst, Weight weight) 
        :src(src), dst(dst), weight(weight) {}
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef pair<Weight, int> Result;

Result visit(int p, int v, const Graph &g)
{
    Result r(0, v);
    FOR(e, g[v]) if (e->dst != p) {
        Result t = visit(v, e->dst, g);
        t.first += e->weight;
        if (r.first < t.first) r = t;
    }
    return r;
}

Weight tree_diameter(const Graph &g)
{
    Result r = visit(-1, 0, g);
    Result t = visit(-1, r.second, g);
    return t.first;
}

int main(void)
{
    return 0;
}
