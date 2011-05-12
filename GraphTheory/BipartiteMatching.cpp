#include <iostream>
#include <vector>

using namespace std;

#define REP(i,n) for(int i = 0; i < (int)n; ++i)
#define FOR(i,c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)

struct Edge 
{
    int src, dst;
    Edge(int src, int dst) 
        :src(src), dst(dst) {}
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

bool augment(const Graph &g, int u, vector<int> &matchTo, vector<bool> &visited)
{
    if (u < 0) return true;
    FOR(e, g[u]) if (!visited[e->dst]) {
        visited[e->dst] = true;
        if (augment(g, matchTo[e->dst], matchTo, visited)) {
            matchTo[e->src] = e->dst;
            matchTo[e->dst] = e->src;
            return true;
        }
    }
    return false;
}

int bipartiteMatching(const Graph &g, int L, Edges &matching)
{
    const int n = g.size();
    vector<int> matchTo(n, -1);
    int match = 0;
    REP(u, L) {
        vector<bool> visited(n);
        if (augment(g, u, matchTo, visited)) ++match;
    }

    REP(u, L) if (matchTo[u] >= 0) //make explicit matching
        matching.push_back(Edge(u, matchTo[u]));
    return match;
}

int main(void)
{
    return 0;
}
