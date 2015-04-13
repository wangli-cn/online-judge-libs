#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>
#include <climits>

using namespace std;

const int INF = 9999999;

#define REP(i, n) for(int i = 0; i < (int)n; ++i)
#define FOR(i,c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)

typedef int Weight;

struct Edge 
{
    int src, dst;
    Weight weight;
    Edge(int src, int dst, Weight weight) 
        :src(src), dst(dst), weight(weight) {}
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;
#define RESIDUE(s,t) (capacity[s][t] - flow[s][t])

int RelabelToFront(const Graph &g, int s, int t)
{
    const int n = g.size();
    Matrix flow(n , Array(n)), capacity(n, Array(n));
    REP(u, n) FOR(e, g[u]) capacity[e->src][e->dst] += e->weight;
    
    vector<bool> inqueue(n, false);
    vector<int> excess(n, 0), h(n, 0);
    queue<int> Q;
   
    h[s] = n; h[t] = 0;
    FOR(e, g[s]) {
        excess[e->dst] = flow[s][e->dst] = capacity[s][e->dst];
        flow[e->dst][s] = - flow[s][e->dst];

        if (!inqueue[e->dst]) {
            inqueue[e->dst] = true;
            Q.push(e->dst);
        }
    }

    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        while (excess[u] > 0) {
            //push flow
            FOR(e, g[u]) {
                if (excess[u] <= 0) break;
                if (RESIDUE(u, e->dst) > 0 && h[u] == h[e->dst] + 1) {
                    int inc = min(excess[u], RESIDUE(u, e->dst));

                    flow[u][e->dst] += inc; flow[e->dst][u] -= inc;
                    excess[e->dst] += inc; excess[u] -= inc;
                    if (excess[e->dst] > 0 && !inqueue[e->dst] && e->dst != s && e->dst != t) {
                        Q.push(e->dst);
                        inqueue[e->dst] = true;
                    }
                }
            }
            
            if (excess[u]) {
                //relabel
                int value = INF, v = u;
                FOR(e, g[u]) {
                    if (h[e->dst] < value && RESIDUE(u, e->dst) > 0) {
                        value = h[e->dst];
                        v = e->dst;
                    }
                }
                h[u] = h[v] + 1;
            }
        }
        inqueue[u] = false;
    }

    int sum = 0;
    FOR(e, g[s]) {
        sum += flow[s][e->dst];
    }
    return sum;
}

int main(void)
{
    int N, M;
    int src, dst;

    while (cin >> N && N) {
        Graph g;
        g.resize(N);

        cin >> src >> dst >> M;
        REP(i, M) {
            int x, y, c;
            cin >> x >> y >> c;
            g[x].push_back(Edge(x, y, c)); g[y].push_back(Edge(y, x, 0));
        }

        cout << RelabelToFront(g, src, dst) << endl;
    }
    return 0;
}
