#include <iostream>
#include <vector>
#include <climits>
#include <cstdio>

using namespace std;

typedef int Weight;

const int INF = INT_MAX;

struct Edge {
    int src, dst;
    Weight weight;

    Edge(int src, int dst, Weight weight) :src(src), dst(dst), weight(weight) {}
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

#define REP(i, n) for (int i = 0; i < (int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)

void visit(Graph &h, int v, int s, int r, vector<int> &no, vector< vector<int> > &comp, vector<int> &prev,
           vector< vector<int> > &next, vector<Weight> &mcost, vector<int> &mark, Weight &cost, bool &found)
{
    const int n = h.size();
    if (mark[v]) {
        vector<int> temp = no;
        found = true;
        do {
            cost += mcost[v];
            v = prev[v];
            if (v != s) {
                while (comp[v].size() > 0) {
                    no[comp[v].back()] = s;
                    comp[s].push_back(comp[v].back());
                    comp[v].pop_back();
                }
            }
        } while (v != s);

        FOR(j, comp[s]) if (*j != r) FOR(e, h[*j])
            if (no[e->src] != s) e->weight -= mcost[temp[*j]];
    }

    mark[v] = true;
    FOR(i, next[v]) if (no[*i] != no[v] && prev[no[*i]] == v)
        if (!mark[no[*i]] || *i == s)
            visit(h, *i, s, r, no, comp, prev, next, mcost, mark, cost, found);
}

Weight MinimumSpanningArborescence(const Graph &g, int r)
{
    const int n = g.size();
    Graph h(n);
    REP(u, n) FOR(e, g[u]) h[e->dst].push_back(*e);

    vector<int> no(n);
    vector< vector<int> > comp(n);
    REP(u, n) comp[u].push_back(no[u] = u);

    for (Weight cost = 0; ;) {
        vector<int> prev(n, -1);
        vector<Weight> mcost(n, INF);

        REP(j, n) if (j != r) FOR(e, h[j])
            if (no[e->src] != no[j])
                if (e->weight < mcost[no[j]])
                    mcost[no[j]] = e->weight, prev[no[j]] = no[e->src];

        vector< vector<int> > next(n);
        REP(u, n) if (prev[u] >= 0)
            next[prev[u]].push_back(u);

        bool stop = true;
        vector<int> mark(n);
        REP(u, n) if (u != r && !mark[u] && !comp[u].empty()) {
            bool found = false;
            visit(h, u, u, r, no, comp, prev, next, mcost, mark, cost, found);
            if (found) stop = false;
        }

        if (stop) {
            REP(u, n) if (prev[u] >= 0) cost += mcost[u];
            return cost;
        }
    }
}

int main(void)
{
    int N, M;
    int x, y, c;

    scanf("%d %d", &N, &M);
    Graph g(N);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &x, &y, &c);
        g[x-1].push_back(Edge(x-1, y-1, c));
    }

    printf("%d\n", MinimumSpanningArborescence(g, 0));
    return 0;
}
