#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include "utils/common.h"


const int MAXN = 10005;
const int LOGMAXN = 15;

class Node
{
public:
    explicit Node() {}

    int son;
    int next;

} tree[MAXN];

int S[MAXN];
int depth[MAXN];
int P[MAXN][LOGMAXN];

void DFS(int v, int d)
{
    S[d] = v; depth[v] = d;
    for (int i = 1; (1 << i) <= d; i++) {
        P[v][i] = S[d - (1 << i)];
    }

    for (int i = tree[v].son; i > 0; i = tree[i].next) {
        DFS(i, d+1);
    }
}

int leastCommonAncestor(int p, int q)
{
    int tmp, log, i;

    if (depth[p] < depth[q]) swap(p, q);

    for (log = 1; (1 << log) <= depth[p]; log++);
    log--;

    for (i = log; i >= 0; i--) {
        if (depth[p] - (1 << i) >= depth[q])
            p = P[p][i];
    }

    if (p == q) return p;

    for (i = log; i >= 0; i--) {
        if (P[p][i] > 0 && P[p][i] != P[q][i])
            p  = P[p][i], q = P[q][i];
    }

    return P[p][0];
}

int main(void)
{
    int nCase, N;
    int a, b;
    int parent, child;

    cin >> nCase;
    while (nCase--) {
        cin >> N;

        for (int i = 1; i <= N; i++) {
            tree[i].son = tree[i].next = 0;

            int h = LOGMAXN;
            for (int j = 0; j < h; j++) {
                P[i][j] = 0;
            }
        }

        for (int i = 1; i < N; i++) {
            cin >> parent >> child;

            P[child][0] = parent;
            tree[child].next = tree[parent].son;
            tree[parent].son = child;
        }

        int root = -1;
        for (int i = 1; i <= N; i++) {
            if (P[i][0] == 0) {
                root = i;
                break;
            }
        }

        DFS(root, 0);

        cin >> a >> b;
        cout << leastCommonAncestor(a, b) << endl;
    }

    return 0;
}
