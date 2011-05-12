#include <iostream>
#include <cstdio>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int l, r, h;

    Interval(int l, int r, int h) :l(l), r(r), h(h) {}
};

struct Event {
    int x; 
    int type;
    int idx;

    Event(int x, int type, int idx) 
        :x(x), type(type), idx(idx) {}
    bool operator<(const Event &e) const {
        return x != e.x ? x > e.x : type > e.type;
    }
};
    
vector<Interval> ints;

struct Cmp {
    bool operator()(int i, int j) {
        if (ints[i].h != ints[j].h) {
            return ints[i].h < ints[j].h;
        } else {
            if (ints[i].l != ints[j].l) {
                return ints[i].l < ints[j].l;
            } else {
                return ints[i].r < ints[j].r;
            }
        }
    }
};

long long sweep_line()
{
    priority_queue<Event> Q;
    for (int i = 0; i < ints.size(); ++i) {
        int x1 = ints[i].l; int x2 = ints[i].r;
        Q.push(Event(min(x1, x2), 0, i));
        Q.push(Event(max(x1, x2), 1, i));
    }

    set<int, Cmp> T;
    long long ans = 0;
    while (!Q.empty()) {
        Event e = Q.top(); Q.pop();
        if (e.type == 0) {
            T.insert(e.idx);
        } else {
            T.erase(e.idx);
        }

        if (T.size() > 0) {
            set<int, Cmp>::reverse_iterator itr = T.rbegin();
            long long h = ints[*itr].h;
            if (!Q.empty()) {
                Event e_peek = Q.top();
                ans += (e_peek.x - e.x) * h;
                //printf("(%d, %d) = %lld\n", e.x, e_peek.x, h);
            }
        }
    }
    return ans;
}

int main(void)
{
    int N;
    int l, r, h;

    scanf("%d", &N);
    ints.clear();
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &l, &r, &h);
        ints.push_back(Interval(l, r, h));
    }
    long long ans = sweep_line();
    printf("%lld\n", ans);
    return 0;
}
