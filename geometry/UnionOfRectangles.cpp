#include <iostream>
#include <vector>
#include <set>
#include <complex>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef complex<double> Point;

struct Rectangle: public vector<Point>
{
    Rectangle(const Point &a, const Point &b) {
        push_back(a); push_back(b);
    }
};

struct Event 
{
    double x;
    int type;
    int id;

    Event(int x, int type, int id)
        :x(x), type(type), id(id) {}
    bool operator<(const Event &e) const {
        return x != e.x ? x < e.x : type > e.type;
    }
};

const double EPS = 1e-8;

int main(void)
{
    int n;
    double x1, y1, x2, y2;

    scanf("%d", &n);
    vector<Rectangle> recs;

    vector<Event> Qv, Qh;
    for (int i = 0; i < n; ++i) {
        scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
        recs.push_back(Rectangle(Point(x1, y1), Point(x2, y2)));
        
        Qv.push_back(Event(x1, 0, i));
        Qv.push_back(Event(x2, 1, i));

        Qh.push_back(Event(y1, 0, i));
        Qh.push_back(Event(y2, 1, i));
    }

    sort(Qv.begin(), Qv.end());
    sort(Qh.begin(), Qh.end());
    vector<bool> in_set(n);

    double area = 0.0;

    in_set[Qv[0].id] = true;
    for (int i = 1; i < Qv.size(); ++i) {
        int cnt = 0;
        double delta_x = Qv[i].x - Qv[i-1].x;
        double begin_y;

        if (delta_x < EPS) {
            in_set[Qv[i].id] = (Qv[i].type == 0);
            continue;
        }

        for (int j = 0; j < Qh.size(); ++j) {
            if (in_set[Qh[j].id]) {
                if (Qh[j].type == 0) {
                    if (cnt == 0) begin_y = Qh[j].x;
                    ++cnt;
                } else {
                    --cnt;
                    if (cnt == 0) {
                        double delta_y = Qh[j].x - begin_y;
                        area += delta_x * delta_y;
                    }
                }
            }
        }

        in_set[Qv[i].id] = (Qv[i].type == 0);
    }

    printf("%lf\n", area);

    return 0;
}
