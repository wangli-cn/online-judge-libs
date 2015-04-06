#include <iostream>
#include <vector>
#include "utils/graph.h"

using Result = std::pair<Weight, int>;

Result visit(int p, int v, const Graph &g)
{
    Result r(0, v);
    FOR(e, g[v]) if (e->dst != p) {
        Result t = visit(v, e->dst, g);
        t.first += e->weight;
        if (r.first < t.first) r = t;
    }

    return r;
}

Weight tree_diameter(const Graph &g)
{
    Result r = visit(-1, 0, g);
    Result t = visit(-1, r.second, g);
    return t.first;
}

int main()
{
    return 0;
}
