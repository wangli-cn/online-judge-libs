#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

#define REP(i,n) for (int i = 0; i < (int)n; ++i)
#define FOR(i,c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)

using namespace std;

struct Edge 
{
    int src, dst;
    Edge(int src, int dst) 
        :src(src), dst(dst) {}
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

int N, M;

void visit(int v, const Graph &g, vector<int> &ord, vector<int> &num, int k)
{
    if (num[v] >= 0)
        return;

    num[v] = k;
    for (int i = 0; i < g[v].size(); ++i) {
        visit(g[v][i].dst, g, ord, num, k);
    }
    ord.push_back(v);
}

void stronglyConnectedCompoments(const Graph &g, int &size, vector<int> &num)
{
    int n = g.size();

    Graph h(n);
    REP(u, n) FOR(e, g[u]) {
        h[e->dst].push_back(Edge(e->dst, e->src));
    }

    vector<int> ord, dro;
    num.assign(n, -1);
    for (int i = 0; i < n; ++i)
        visit(i, g, ord, num, i);

    reverse(ord.begin(), ord.end());
    fill(num.begin(), num.end(), -1);
    size = 0;
    for (int i = 0; i < n; ++i) {
        if (num[ord[i]] == -1) {
            visit(ord[i], h, dro, num, size);
            size += 1;
        }
    }
}

int main(void)
{
    int nCase;
    int a, b;

    cin >> nCase;
    while (nCase--) {
        cin >> N >> M;

        Graph g(N);
        REP(i, M) {
            cin >> a >> b;
            a -= 1; b -= 1;
            g[a].push_back(Edge(a, b));
        }

        int size = 0;
        vector<int> num;
        stronglyConnectedCompoments(g, size, num);
        if (size == 1) {
            cout << 0 << endl;
            continue;
        }

        vector<int> nIN(size), nOUT(size);
        REP(i, N) {
            FOR(e, g[i]) if (num[e->src] != num[e->dst]) {
                nOUT[num[e->src]] += 1;
                nIN[num[e->dst]] += 1;
            }
        }

        int nIN0 = 0, nOUT0 = 0;
        REP(i, size) {
            if (nIN[i] == 0) nIN0 += 1;
            if (nOUT[i] == 0) nOUT0 += 1;
        }

        cout << max(nIN0, nOUT0) << endl;
    }

    return 0;
}
