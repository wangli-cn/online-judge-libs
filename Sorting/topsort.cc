#include <iostream>
#include <vector>
#include <algorithm>

#define REP(i,n) for (int i = 0; i < (int)n; ++i)

using namespace std;

const int MAXN = 10;

bool G[MAXN][MAXN];

bool visit(int v, vector<int> &order, vector<int> &color)
{
    const int n = MAXN;
    color[v] = 1;
    REP(w, n) if (G[v][w]) {
        if (color[w] == 2) continue;
        if (color[w] == 1) return false;
        if (!visit(w, order, color)) return false;
    }

    order.push_back(v); color[v] = 2;
    return true;
}

bool topsort(vector<int> &order)
{
    const int n = MAXN;
    vector<int> color(n, 0);
    REP(i, n) if (!color[i] && !visit(i, order, color)) {
        return false;
    }

    reverse(order.begin(), order.end());
    return true;
}

int main()
{
    return 0;
}
