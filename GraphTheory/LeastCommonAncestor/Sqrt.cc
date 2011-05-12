#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>

#define REP(i,n) for (int i = 0; i < (int)n; ++i)
#define FOR(i,c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)

using namespace std;

const int MAXN = 10005;

struct Node 
{
    int son;
    int next;

} tree[MAXN];

int depth[MAXN], parent[MAXN];
int P[MAXN];

void DFS(int v, int d, int nr)
{
    int i, j;

    depth[v] = d;

    if (d < nr) {
        P[v] = 1;
    } else {
        if (d % nr == 0) P[v] = parent[v];
        else P[v] = P[parent[v]];
    }

    for (int i = tree[v].son; i > 0; i = tree[i].next) {
        DFS(i, d+1, nr);
    }
}

int leastCommonAncestor(int x, int y) 
{
    while (P[x] != P[y]) {
        if (depth[x] > depth[y]) {
            x = P[x];
        } else {
            y = P[y];
        }
    }

    while (x != y) {
        if (depth[x] > depth[y]) {
            x = parent[x];
        } else {
            y = parent[y];
        }
    }

    return x;
}

int main(void)
{
    int nCase, N;
    int a, b;
    int x, y;

    cin >> nCase;
    while (nCase--) {
        cin >> N;

        for (int i = 1; i <= N; i++) {
            tree[i].son = tree[i].next = 0;
            parent[i] = P[i] = 0;
        }

        for (int i = 1; i < N; i++) {
            cin >> x >> y;

            parent[y] = x;

            tree[y].next = tree[x].son;
            tree[x].son = y;
        }

        int root = -1;
        for (int i = 1; i <= N; i++) {
            if (parent[i] == 0) {
                root = i;
                break;
            }
        }

        int nr = (int) sqrt((double)N);
        DFS(root, 0, nr);

        cin >> a >> b;  
        cout << leastCommonAncestor(a, b) << endl;
    }
    return 0;
}
