#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <algorithm>

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

struct UndirectionalCompare {
    bool operator() (const Edge &e, const Edge &f) const {
        if (min(e.src, e.dst) != min(f.src, f.dst))
            return min(e.src, e.dst) < min(f.src, f.dst);
        return max(e.src, e.dst) < max(f.src, f.dst);
    }
};

typedef set<Edge, UndirectionalCompare> Edgeset;

void visit(const Graph &g, int v, int u, 
           vector<int> &art, vector<Edgeset> &bcomp,
           stack<Edge> &S, vector<int> &num, vector<int> &low, int &time)
{
    low[v] = num[v] = ++time;
    FOR(e, g[v]) {
        int w = e->dst;
        if (num[w] < num[v]) S.push(*e);
        if (num[w] == 0) {
            visit(g, w, v, art, bcomp, S, num, low, time);
            low[v] = min(low[v], low[w]);
            if ((num[v] == 1 && num[w] != 2) ||
                (num[v] != 1 && low[w] >= num[v])) art.push_back(v);
            if (low[w] >= num[v]) {
                bcomp.push_back(Edgeset());
                while (1) {
                    Edge f = S.top(); S.pop();
                    bcomp.back().insert(f);
                    if (f.src == v && f.dst == w) break;
                }
            } 
        } else {
            low[v] = min(low[v], num[w]);
        }
    }
}

void articulationPoint(const Graph &g, vector<int> &art, vector<Edgeset> &bcomp) 
{
    const int n = g.size();
    vector<int> low(n), num(n);
    stack<Edge> S;
    REP(u, n) if (num[u] == 0) {
        int time = 0;
        visit(g, u, -1, art, bcomp, S, num, low, time);
    }
}

int main(void)
{
    int n;

    while (cin >> n) {
        if (n == 0) break;
        cin.ignore(1);

        Graph g(n);

        cout << "n = " << n << endl;
        string line;
        while (getline(cin, line)) {
            stringstream sin(line);

            int u, v;
            sin >> u;
            if (u == 0) break;

            while (sin >> v) {
                g[u-1].push_back(Edge(u-1, v-1));
                g[v-1].push_back(Edge(v-1, u-1));
            }
        }

        vector<int> art;
        vector<Edgeset> bcomp;
        articulationPoint(g, art, bcomp);

        sort(art.begin(), art.end());
        art.erase(unique(art.begin(), art.end()), art.end());

        cout << art.size() << endl;
    }

    return 0;
}
