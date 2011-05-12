#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define FOR(i,c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define REP(i,n) for(int i = 0; i < (int)n; ++i)

struct Edge 
{
    int src, dst;
    Edge(int src, int dst) 
        :src(src), dst(dst) {}
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void visit(const Graph &g, int v, vector< vector<int> > &scc,
           stack<int> &S, vector<bool> &inS,
           vector<int> &low, vector<int> &num, int &time)
{
    low[v] = num[v] = ++time;
    S.push(v); inS[v] = true;
    FOR(e, g[v]) {
        int w = e->dst;
        if (num[w] == 0) {
            visit(g, w, scc, S, inS, low, num, time);
            low[v] = min(low[v], low[w]);
        } else if (inS[w]) {
            low[v] = min(low[v], num[w]);
        }
    }

    if (low[v] == num[v]) {
        scc.push_back(vector<int>());
        while (1) {
            int w = S.top(); S.pop(); inS[w] = false;
            scc.back().push_back(w);
            if (v == w) break;
        }
    }
}

void stronglyConnectedComponents(const Graph &g, vector< vector<int> > &scc)
{
    const int n = g.size();
    vector<int> num(n), low(n);
    stack<int> S;
    vector<bool> inS(n);
    int time = 0;
    REP(u, n) if (num[u] == 0)
        visit(g, u, scc, S, inS, low, num, time);
}

int main(void)
{
    return 0;
}
