#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <climits>
#include <algorithm>
#include "utils/graph.h"

void FloydWarshall(const Matrix &g, Matrix &dist, std::vector< std::vector<int> > &inter)
{
    int n = g.size();
    dist = g;
    inter.assign(n, std::vector<int>(n, -1));
    REP(k, n) REP(i, n) REP(j, n) {
        if (dist[i][j] < dist[i][k] + dist[k][j]) {
            dist[i][j] = dist[i][k] + dist[k][j];
            inter[i][j] = k;
        }
    }
}

void buildPath(const std::vector< std::vector<int> > &inter, int s, int t, std::vector<int> &path)
{
    int u = inter[s][t];
    if (u < 0) path.push_back(s);
    else buildPath(inter, s, u, path), buildPath(inter, u, t, path);
}

std::vector<int> buildPath(const std::vector< std::vector<int> > &inter, int s, int t)
{
    std::vector<int> path;
    buildPath(inter, s, t, path);
    path.push_back(t);
    return path;
}

int main()
{
    return 0;
}
