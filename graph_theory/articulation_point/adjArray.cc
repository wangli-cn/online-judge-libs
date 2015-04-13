#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

#define REP(i,n) for (int i = 0; i < (int)n; ++i)
#define FOR(i,c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

const int MAXN = 105;

bool G[MAXN][MAXN];
int n;
int num[MAXN], low[MAXN];

void visit(int v, int u, vector<int> &art, int &time)
{
    low[v] = num[v] = ++time;

    REP(w, n) if (G[v][w] && w != u) {
        if (num[w] == 0) {
            visit(w, v, art, time);
            low[v] = min(low[v], low[w]);

            if ((num[v] == 1 && num[w] != 2) || (num[v] != 1 && low[w] >= num[v])) {
                art.push_back(v);
            }
        } else {
            low[v] = min(low[v], num[w]);
        }
    }

}

void articulationPoint(vector<int> &art)
{
    REP(u, n) if (num[u] == 0) {
        int time = 0;
        visit(u, -1, art, time); 
    }
}

int main(void)
{
    while (cin >> n) {
        if (n == 0) break;
        cin.ignore(1);

        memset(G, 0, sizeof(G));
        memset(low, 0, sizeof(low));
        memset(num, 0, sizeof(num));

        string line;
        while (getline(cin, line)) {
            stringstream sin(line);

            int u, v;
            sin >> u;
            if (u == 0) break;

            while (sin >> v) {
                G[u-1][v-1] = G[v-1][u-1] = true;
            }
        }

        vector<int> art;
        articulationPoint(art);

        sort(art.begin(), art.end());
        art.erase(unique(art.begin(), art.end()), art.end());

        cout << art.size() << endl;
    }
   
    return 0;
}
