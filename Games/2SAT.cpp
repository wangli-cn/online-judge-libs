#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define VAR(x) ((x) << 1)
#define NOT(x) ((x) ^ 1)

struct Edge 
{
    int src, dst;
    Edge(int src, int dst) 
        :src(src), dst(dst)  {}
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void visit(int v, const Graph &g, vector<int> &ord, vector<int> &num, int k)
{
    if (num[v] >= 0) return;
    num[v] = k;
    for (int i = 0; i < g[v].size(); ++i)
        visit(g[v][i].dst, g, ord, num, k);
    ord.push_back(v);
}

typedef pair<int, int> Clause;

bool TwoSAT(int m, const vector<Clause> &cs)
{
    int n = m * 2; //m positvie vars and m negative vars
    Graph g(n), h(n);
    for (int i = 0; i < cs.size(); ++i) {
        int u = cs[i].first, v = cs[i].second;
        g[NOT(u)].push_back(Edge(NOT(u), v));
        g[NOT(v)].push_back(Edge(NOT(v), u));
        h[v].push_back(Edge(v, NOT(u)));
        h[u].push_back(Edge(u, NOT(v)));
    }

    vector<int> num(n, -1), ord, dro;
    for (int i = 0; i < n; ++i)
        visit(i, g, ord, num, i);
    reverse(ord.begin(), ord.end());
    fill(num.begin(), num.end(), -1);
    for (int i = 0; i < n; ++i)
        visit(ord[i], h, dro, num, i);
    for (int i = 0; i < n; ++i)
        if (num[i] == num[NOT(i)])
            return false;
    return true;
}

int main(void)
{
    vector<Clause> cs;

    cs.push_back(Clause(VAR(0), NOT(VAR(1))));
    cs.push_back(Clause(VAR(0), VAR(1)));
    cs.push_back(Clause(NOT(VAR(0)), NOT(VAR(1))));
    cs.push_back(Clause(NOT(VAR(0)), VAR(1)));

    cout << TwoSAT(2, cs) << endl;
    return 0;
}
