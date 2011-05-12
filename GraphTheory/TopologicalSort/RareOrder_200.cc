#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>

#define REP(i,n) for (int i = 0; i < (int)n; ++i)
#define FOR(i,c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

typedef vector<int> VI;

const int MAXN = 30;

bool G[MAXN][MAXN];
int N;

bool visit(int v, vector<int> &order, vector<int> &color)
{
    color[v] = 1;
    REP(w, N) if (G[v][w]) {
        if (color[w] == 2) continue;
        if (color[w] == 1) return false;
        if (!visit(w, order, color)) return false;
    }

    order.push_back(v); color[v] = 2;
    return true;
}

bool TopologicalSort(vector<int> &order)
{
    vector<int> color(N);

    REP(i, N) if (!color[i] && !visit(i, order, color)) {
        return false;
    }

    reverse(ALL(order));
    return true;
}

int main(void)
{
    string line;
    vector<string> vec;

    while (cin >> line) {
        if (line == "#") break;
        vec.push_back(line);
    }

    pair<string::iterator, string::iterator> p; 
    map<char, int> c2i; 
    char i2c[30];
    int uid = 0;

    for (int i = 1, l = vec.size(); i < l; i++) {
         p = mismatch(vec[i-1].begin(), vec[i-1].end(), vec[i].begin());

         //cout << int(p.first - vec[i-1].begin()) << " " << int(p.second - vec[i].begin()) << endl;
         if (p.first == vec[i-1].end()) continue;

         if (c2i.find(*(p.first)) == c2i.end()) {
            c2i.insert(make_pair(*(p.first), uid));
            i2c[uid] = *(p.first);
            uid++;
         }

         if (c2i.find(*(p.second)) == c2i.end()) {
            c2i.insert(make_pair(*(p.second), uid));
            i2c[uid] = *(p.second);
            uid++;
         }

         G[c2i[*(p.first)]][c2i[*(p.second)]] = true;
    }

    vector<int> order;
    N = uid;
    TopologicalSort(order);

    REP(i, N) cout << i2c[order[i]];
    cout << endl;

    return 0;
}
