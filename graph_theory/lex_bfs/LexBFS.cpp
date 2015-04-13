/**
 * Author: Meng Chao Hong
 * Email: mno2.csie@gmail.com 
 * Verified: ZJU 1015 Fishing Net 
 */

#include <iostream>
#include <vector>
#include <map>
#include <list>
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

void dumpSet(const set<int> &s) 
{
    printf("{");
    FOR(e, s) {
        printf("%d,", *e);
    }
    printf("}\n");
}

void LexBFS(const Graph &g, vector<int> &ord)
{
    list<int> L;
    map<int, int> _partition;
    vector< set<int> > _sets;
    map<int, list<int>::iterator> list_index;
    int n = g.size();

    set<int> P;
    for (int i = 0; i < n; ++i) P.insert(i);
    _sets.push_back(P);

    for (int i = 0; i < n; i++) 
        _partition.insert(make_pair(i, 0));

    L.push_front(0);
    list_index.insert(make_pair(0, L.begin()));
    while (!L.empty()) {
        int idx = L.front(); 
        int v = *(_sets[idx].begin()); 
        ord.push_back(v);

        _sets[_partition[v]].erase(v);
        _partition.erase(v);

        if (_sets[idx].empty()) { 
            L.erase(list_index[idx]);
            list_index.erase(idx);
        }

        map<int, int> hit;
        vector< set<int> > hit_pool;
        FOR(e, g[v]) {
            if (_partition.count(e->dst) > 0) {
                int set_idx =  _partition[e->dst];
                if (hit.count(set_idx) > 0) {
                    hit_pool[hit[set_idx]].insert(e->dst);
                } else {
                    hit_pool.push_back(set<int>());
                    hit_pool.back().insert(e->dst);
                    hit.insert(make_pair(set_idx, hit_pool.size()-1));
                }
            }
        }

        FOR(p, hit) {
            //we only need to compare their sizes
            if (hit_pool[p->second].size() != _sets[p->first].size()) {
                _sets.push_back(hit_pool[p->second]);
                int k = _sets.size()-1;
                FOR(h, hit_pool[p->second]) {
                    _partition[*h] = k;
                }
               
                set<int> res;
                set_difference(_sets[p->first].begin(), _sets[p->first].end(), hit_pool[p->second].begin(), hit_pool[p->second].end(), inserter(res, res.begin())); 
                _sets[p->first] = res;

                list<int>::iterator t = list_index[p->first];
                L.insert(t, k);
                list_index.insert(make_pair(k, --t));
            }
        }
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
    int nCase = 1;

    while (scanf("%d %d", &N, &M) == 2 && N && M) {
        Graph g(N);

        for (int i = 0; i < M; i++) {
            scanf("%d %d", &x, &y); 
            g[x-1].push_back(Edge(x-1, y-1));
            g[y-1].push_back(Edge(y-1, x-1));
        }

        vector<int> ord;
        LexBFS(g, ord);
        //copy(ord.begin(), ord.end(), ostream_iterator<int>(cout, " "));
        //printf("\n");

        printf("%s\n\n", isChordal(g, ord) ? "Perfect": "Imperfect"); 
    }

    return 0;
}

