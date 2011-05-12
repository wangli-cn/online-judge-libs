#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef unsigned long long State;
const int N = 50;

struct Indirect 
{
    int *key;
    Indirect(int *key) : key(key) {}
    bool operator()(int a, int b) const {
        return key[a] > key[b];
    }
};

int rec(int n, int ord[N], State D[N], State E[N], int k, State S,
        int acc, int &bound)
{
    if (acc >= bound) return bound;
    if (S == (1ULL << n)-1) {
        bound = min(bound, acc);
        return acc;
    }

    if (k >= n) return bound;
    if ((S | E[ord[k]]) != (1ULL << n)-1) return bound;

    int u = ord[k];
    if ((S & D[u]) == D[u]) return rec(n, ord, D, E, k+1, S, acc, bound);
    else return min(rec(n, ord, D, E, k+1, S | D[u], acc+1, bound),
                    rec(n, ord, D, E, k+1, S, acc, bound));
}

int DominatingSet(int g[N][N], int n)
{
    State D[N];
    fill(D, D+n, 0);
    int C[N];
    for (int i = 0; i < n; ++i) {
        D[i] |= (1ULL << i);
        C[i] = 1;
        for (int j = 0; j < n; ++j) {
            if (g[i][j]) {
                D[i] |= (1ULL << j);
                ++C[i];
            }
        }
    }

    int ord[N];
    for (int i = 0; i < n; ++i)
        ord[i] = i;
    sort(ord, ord+n, Indirect(C));
    ord[n] = n;

    State E[N];
    E[n] = 0;
    for (int i = n-1; i >= 0; --i) 
        E[ord[i]] = E[ord[i+1]] | D[ord[i]];

    int bound = n;
    return rec(n, ord, D, E, 0, 0, 0, bound);
}

int main(void)
{
    int g[N][N];

    memset(g, 0, sizeof(g));
    g[0][1] = g[0][2] = g[0][3] = g[0][4] = 1;
    g[1][0] = g[2][0] = g[3][0] = g[4][0] = 1;
    g[4][5] = g[5][4] = 1;
    cout << DominatingSet(g, 6) << endl;

    return 0;
}
