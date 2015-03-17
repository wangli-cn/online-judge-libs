#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

#define REP(i, n) for(int i = 0; i < (int)n; ++i)
#define FOR(i,c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
typedef int Weight;

struct Edge
{
    int src, dst;
    Edge(int src, int dst) 
        :src(src), dst(dst) {}
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

bool visit(const Graph &g, int v, vector<int> &order, vector<int> &color) 
{
    color[v] = 1;
    FOR(e, g[v]) {
        if (color[e->dst] == 2) continue;
        if (color[e->dst] == 1) return false;
        if (!visit(g, e->dst, order, color)) return false;
    }
    order.push_back(v); color[v] = 2;
    return true;
}

bool TopologicalSort(const Graph &g, vector<int> &order)
{
    int n = g.size();
    vector<int> color(n);
    REP(u, n) if (!color[u] && !visit(g, u, order, color))
        return false;
    reverse(ALL(order));
    return true;
}

int main(void)
{
    int n, m;
    while (scanf("%d %d ", &n, &m) == 2) {
        if (n == 0 && m == 0) break;

        char a, b, rel;
        Graph g(n);
        REP(i, m) {
            cin >> a >> rel >> b;

            if (rel == '>') {
                g[a-'A'].push_back(Edge(a-'A', b-'A'));
            } else if (rel == '<') {
                g[b-'A'].push_back(Edge(b-'A', a-'A'));
            }
        }

        vector<int> order;
        cout << TopologicalSort(g, order) << endl;
    }
    return 0;
}
