#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

#define REP(i,n) for (int i = 0; i < (int)n; ++i)
#define FOR(i,c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

const int MAXN = 27;

bool G[MAXN][MAXN];
int inDeg[MAXN];
int n;

void TopologicalSort(vector<int> &order)
{
    int zeroCnt, zero;

    REP(i, n) inDeg[i] = 0;

    REP(i, n) REP(j, n) if (G[i][j]) {
        inDeg[j] += 1;
    }

    REP(i, n) {
        zeroCnt = 0;
        REP(j, n) if (inDeg[j] == 0) {
            zeroCnt += 1; zero = j;
        }

        order.push_back(zero);
        inDeg[zero] = -1;

        REP(j, n) if (G[i][j]) {
            inDeg[j] -= 1;
        }
    }
}


int main(void)
{
    int m;
    while (scanf("%d %d ", &n, &m) == 2) {
        if (n == 0 && m == 0) break;

        REP(i, n) REP(j, n) G[i][j] = 0;
    
        char a, b, rel;
        REP(i, m) {
            cin >> a >> rel >> b;

            if (rel == '>') {
                G[a-'A'][b-'A'] = true;
            } else if (rel == '<') {
                G[b-'A'][a-'A'] = true;
            }
        }

        vector<int> order;
        TopologicalSort(order);
    }

    return 0;
}
