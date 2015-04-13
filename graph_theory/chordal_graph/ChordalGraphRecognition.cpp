/**
 * Author: Meng Chao Hong
 * Email: mno2.csie@gmail.com 
 * Verified: ZJU 1015 Fishing Net 
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <cstdio>

using namespace std;

#define FOR(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define REP(i, n) for(int i = 0; i < (int)n; ++i)


struct Edge
{
    int src, dst;
    Edge(int src, int dst) :src(src), dst(dst) {}
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void maximumCardinalitySearch(const Graph &g, vector<int> &ord)
{
    int i, j, k;
    int n = g.size();

    vector<int> deg(n, 0);
    vector<bool> used(n, false);

    REP(i, n) {
        for (j = 0, k = -1; j < n; j++) {
            if (!used[j] && (k < 0 || deg[j] > deg[k])) k = j;
        }

        used[k] = true; ord.push_back(k);
        FOR(e, g[k]) if (!used[e->dst]) deg[e->dst]++;
    }
}

bool isChordal(const Graph &g, vector<int> &ord)
{
    vector<int> dro(ord.rbegin(), ord.rend());
    int n = g.size();
    int *inverse = new int[n];
    REP(i, n) inverse[dro[i]] = i;

    REP(i, n) {
        int v = dro[i];
        int w = -1;
        int minimum = n;
        FOR(e, g[v]) {
            if (inverse[e->dst] > inverse[v] && minimum > inverse[e->dst]) {
                minimum = inverse[e->dst];
                w = e->dst;
            }
        }

        if (w >= 0) {
            set<int> v_early, w_early;
            FOR(e, g[v]) {
                if (e->dst != w && inverse[e->dst] > inverse[v])
                    v_early.insert(e->dst);
            }

            FOR(e, g[w]) {
                if (inverse[e->dst] > inverse[w])
                    w_early.insert(e->dst);
            }
        
            if (!includes(w_early.begin(), w_early.end(), v_early.begin(), v_early.end())) return false;
        }
    }
    
    delete [] inverse;
    return true;
}

int main(void)
{
    int N, M;
    int x, y;

    while (scanf("%d %d", &N, &M) == 2 && N && M) {

        Graph g(N);

        for (int i = 0; i < M; i++) {
            scanf("%d %d", &x, &y); 
            g[x-1].push_back(Edge(x-1, y-1));
            g[y-1].push_back(Edge(y-1, x-1));
        }

        vector<int> ord;
        maximumCardinalitySearch(g, ord);
        //copy(ord.begin(), ord.end(), ostream_iterator<int>(cout, " "));
        //printf("\n");
        printf("%s\n\n", isChordal(g, ord) ? "Perfect": "Imperfect"); 
    }

    return 0;
}
