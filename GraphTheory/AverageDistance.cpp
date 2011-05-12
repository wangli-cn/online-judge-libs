#include <iostream>
#include <vector>

using namespace std;

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

int visit(const Graph &g, int u, vector<bool> &visited, int &sum)
{
    int n = g.size();
    int nNode = 0, curr;
    
    visited[u] = true;
    FOR(e, g[u]) {
        if (!visited[e->dst]) {
            curr = visit(g, e->dst, visited, sum);
            sum += curr * (n - curr) * e->weight;
            nNode += curr;
        }
    }
    return (nNode+1);
}

double AverageDistance(const Graph &g)
{
    int n = g.size();
    int sum = 0;

    vector<bool> visited(n, false);
    visit(g, 0, visited, sum);
    return ((double)sum * 2.0) / (double)(n * (n-1));
}

int main(void)
{
    return 0;
}
