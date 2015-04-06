#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cassert>
#include "utils/geometry.h"

struct Event
{
    double x;
    int type;
    Segment seg;
    Event(double x, int type, const Segment &seg) :
        x(x), type(type), seg(seg) {}
    bool operator<(const Event &e) const {
        return x != e.x ? x > e.x : type > e.type;
    }
};


Point crosspoint(const Segment &l, const Segment &m)
{
    double A = cross(l[1] - l[0], m[1] - m[0]);
    double B = cross(l[1] - l[0], l[1] - m[0]);
    if (abs(A) < EPS && abs(B) < EPS) return m[0];
    if (abs(A) < EPS) assert(false);
    return m[0] + B/A * (m[1] - m[0]);
}

bool intersectSS(const Segment &s, const Segment &t)
{
    return ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) <= 0 &&
           ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) <= 0;
}

template <class OUT>
int segment_intersects(const std::vector<Segment> &segs, OUT out)
{
    std::priority_queue<Event> Q;
    for (int i = 0; i < segs.size(); ++i) {
        double x1 = real(segs[i][0]), x2 = real(segs[i][1]);
        Q.push(Event(std::min(x1, x2), 0, segs[i]));
        Q.push(Event(std::max(x1, x2), 1, segs[i]));
    }

    int cnt = 0;
    std::set<Segment> T;
    while (!Q.empty()) {
        Event e = Q.top(); Q.pop();
        if (e.type == 0) {
            for (auto&& itr = T.begin(); itr != T.end(); ++itr) {
                if (intersectSS(*itr, e.seg)) {
                    *out++ = crosspoint(*itr, e.seg);
                    ++cnt;
                }
            }
            T.insert(e.seg);
        } else {
            T.erase(e.seg);
        }
    }
    return cnt;
}

int main(void)
{
    return 0;
}
