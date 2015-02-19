#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <limits>
#include <algorithm>

using namespace std;

const int INF = std::numeric_limits<int>::max();
typedef int Weight;

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

void Dijkstra(const Graph &g, int s, vector<Weight> &dist, vector<int> &prev)
{
    const int n = g.size();
    dist.assign(n, INF); dist[s] = 0;
    prev.assign(n, -1);

    priority_queue<Edge> Q;
    for (Q.push(Edge(-2, s, 0)); !Q.empty(); ) {
        Edge e = Q.top(); Q.pop();
        if (prev[e.dst] != -1) continue;

        prev[e.dst] = e.src;
        FOR(f, g[e.dst]) if (dist[f->dst] > e.weight + f->weight) {
            dist[f->dst] = e.weight + f->weight;
            Q.push(Edge(f->src, f->dst, e.weight + f->weight));
        }
    }
}

vector<int> buildPath(const vector<int> &prev, int t)
{
    vector<int> path;
    for (int u = t; u >= 0; u = prev[u])
        path.push_back(u);
    reverse(path.begin(), path.end());
    return path;
}

int main(void)
{
    vector<Weight> dist;
    vector<int> prev;
    Graph g;

    g.resize(3);
    g[0].push_back(Edge(0, 1, 101));
    g[1].push_back(Edge(1, 2, 1));
    g[2].push_back(Edge(2, 0, 10000));

    Dijkstra(g, 0, dist, prev);
    vector<int> path = buildPath(prev, 2);

    cout << dist[2] << endl;
    copy(path.begin(), path.end(), ostream_iterator<int>(cout, " "));

    return 0;
}

