#include <iostream>
#include <vector>

using namespace std;

struct Query 
{
    int u, v, w;
    Query(int u, int v) 
        :u(u), v(v), w(-1) {}
};

struct UnionFind
{
    vector<int> data;
    UnionFind(int size)  :data(size, -1) {}
    bool unionSet(int x, int y) {
        x = root(x), y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }

    bool findSet(int x, int y) {
        return root(x) == root(y); 
    }

    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);  
    }

    int size(int x) {
        return -data[root(x)];
    }
};

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


void visit(const Graph &g, int u, int w,
           vector<Query> &qs, vector<int> &color,
           vector<int> &ancestor, UnionFind &uf)
{
    ancestor[uf.root(u)] = u;
    FOR(e, g[u]) if (e->dst != w) {
        visit(g, e->dst, u, qs, color, ancestor, uf);
        uf.unionSet(e->src, e->dst);
        ancestor[uf.root(u)] = u;
    }
    color[u] = 1;
    FOR(q, qs) {
        int w = (q->v == u ? q->u : q->u == u ? q->v : -1);
        if (w >= 0 && color[w]) q->w = ancestor[uf.root(w)];
    }
}

void leastCommonAncestor(const Graph &g, int r, vector<Query> &qs)
{
    UnionFind uf(g.size());
    vector<int> color(g.size()), ancestor(g.size());
    visit(g, r, -1, qs, color, ancestor, uf);
}

int main(void)
{
    return 0;
}
