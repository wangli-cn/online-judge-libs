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
#define ALL(c) (c).begin(), (c).end()

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
typedef vector<Weight> Array;
typedef vector<Array> Matrix;

void FloydWarshall(const Matrix &g, Matrix &dist, vector< vector<int> > &inter)
{
    int n = g.size();
    dist = g;
    inter.assign(n, vector<int>(n, -1));
    REP(k, n) REP(i, n) REP(j, n) {
        if (dist[i][j] < dist[i][k] + dist[k][j]) {
            dist[i][j] = dist[i][k] + dist[k][j];
            inter[i][j] = k;
        }
    }
}

void buildPath(const vector< vector<int> > &inter, int s, int t, vector<int> &path)
{
    int u = inter[s][t];
    if (u < 0) path.push_back(s);
    else buildPath(inter, s, u, path), buildPath(inter, u, t, path);
}

vector<int> buildPath(const vector< vector<int> > &inter, int s, int t)
{
    vector<int> path;
    buildPath(inter, s, t, path);
    path.push_back(t);
    return path;
}

int main()
{
    return 0;
}
