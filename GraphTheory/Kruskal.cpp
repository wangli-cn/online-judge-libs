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

struct UnionFind
{
    vector<int> data;
    UnionFind(int size) :data(size, -1) {}
    bool unionSet(int x, int y) {
        x = root(x); y = root(y);
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

pair<Weight, Edges> Kruskal(const Graph &g)
{
    int n = g.size();
    UnionFind uf(n);
    priority_queue<Edge> Q;
    REP(u, n) FOR(e, g[u]) if (u < e->dst) Q.push(*e);

    Weight total = 0;
    Edges F;
    while (F.size() < n-1 && !Q.empty()) {
        Edge e = Q.top(); Q.pop();
        if (uf.unionSet(e.src, e.dst)) {
            F.push_back(e);
            total += e.weight;
        }
    }

    return pair<Weight, Edges>(total, F);
}

int main(void)
{
    return 0;
}
