#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Edge
{
    Edge(int src, int dst, string s): src(src), dst(dst), s(s) {}
    int src, dst;
    string s;
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

Graph build_graph(vector<string> &vs)
{
    Graph g(26, Edges());

    for (int i = 0; i < vs.size(); i++) {
        string s = vs[i];
        int from = s[0] - 'a';
        int to = s[s.length()-1] - 'a';

        g[from].push_back(Edge(from, to, s));
    }

    return g;
}


void visit(Graph &g, int a, vector<int> &path)
{
    while (!g[a].empty()) {
        int b = g[a].back().dst;
        g[a].pop_back();
        visit(g, b, path);
    }

    path.push_back(a);
}


bool eulerian(Graph &g, int s, vector<int> &path)
{
    int n = g.size(), m = 0;
    vector<int> deg(n);

    for (int i = 0; i < n; i++) {
        m += g[i].size();

        for (int j = 0; j < g[i].size(); j++) deg[g[i][j].dst] -= 1;
        deg[i] += g[i].size();
    }

    int k = n - count(deg.begin(), deg.end(), 0);
    if (k == 0 || (k == 2 && deg[s] == 1)) {
        path.clear();
        visit(g, s, path);
        reverse(path.begin(), path.end());
        return path.size() == m+1;
    }

    return false;
}


int main()
{
    vector<string> vs;

    vs.push_back(string("sdfg"));
    vs.push_back(string("dfgs"));
    vs.push_back(string("ghjhk"));

    Graph g = build_graph(vs);
    vector<int> path;

    int s = vs[1][0] - 'a';
    cout << eulerian(g, s, path);

    return 0;
}
