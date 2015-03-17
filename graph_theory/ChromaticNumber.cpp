#include <iostream>
#include <vector>

using namespace std;

typedef int Color;

#define FOR(i,c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)

struct Edge 
{
    int src, dst;
    Edge(int src, int dst) 
        :src(src), dst(dst) {}
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

bool OK(const Graph &g, int u, Color color, vector<Color> &colors)
{
    FOR(e, g[u]) if (colors[e->dst] == color) {
        return false;
    }
    return true;
}

void visit(const Graph &g, vector<Color> &colors, int v, int acc, int &bound)
{
    int n = g.size();

    if (v == n) bound = acc;
    else if (acc < bound) {
        int f = 1;
        for ( ; f <= acc; ++f) {
            if (OK(g, v, f, colors)) {
                colors[v] = f;
                visit(g, colors, v+1, acc, bound);
                colors[v] = 0;
            }
        }

        if (acc < bound) {
            for ( ; f <= bound; ++f) {
                if (OK(g, v, f, colors)) {
                    colors[v] = f;
                    visit(g, colors, v+1, f, bound);
                    colors[v] = 0;
                }
            }
        }
    }
}

int ChromaticNum(const Graph &g)
{
    int n = g.size();
    vector<int> colors(n, 0);
    
    int chromaticNum = n;
    colors[0] = 1;
    visit(g, colors, 1, 1, chromaticNum);
    return chromaticNum;
}

int main(void)
{
    Graph g;
    g.resize(3);
    g[0].push_back(Edge(0, 1));
    g[0].push_back(Edge(0, 2));
    g[1].push_back(Edge(1, 0));
    g[2].push_back(Edge(2, 0));

    cout << ChromaticNum(g) << endl;
    return 0;
}
