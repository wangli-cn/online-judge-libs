#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#include "utils/geometry.h"

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

bool isBound(const Rectangle &r, const Rectangle &s)
{
    if ((real(r[0]) >= real(s[0])) && (imag(r[0]) <= imag(s[0])) &&
        (real(r[1]) <= real(s[1])) && (imag(r[1]) >= imag(s[1]))) {
        return true;
    }
    return false;
}

//O(n^2)
double union_area1(std::vector<Rectangle> &r)
{
    int n = r.size();
    std::vector<double> discrete_x;
    std::vector<double> discrete_y;

    for (auto&& i = r.begin(); i != r.end(); ++i) {
        discrete_x.push_back(real((*i)[0])); discrete_y.push_back(imag((*i)[0]));
        discrete_x.push_back(real((*i)[1])); discrete_y.push_back(imag((*i)[1]));
    }

    std::sort(discrete_x.begin(), discrete_x.end());
    std::sort(discrete_y.begin(), discrete_y.end());

    double area = 0.0;
    int t = discrete_x.size();
    for (int i = 0; i < t-1; ++i) {
        for (int j = 0; j < t-1; ++j) {
            for (int k = 0; k < n; ++k) {
                Rectangle s(Point(discrete_x[i], discrete_y[j]), Point(discrete_x[i+1], discrete_y[j+1]));
                if (isBound(s, r[k])) {
                    area += (discrete_x[i+1] - discrete_x[i]) * (discrete_y[j+1] - discrete_y[j]);
                    break;
                }
            }
        }
    }

    return area;
}


double union_area2(std::vector<Rectangle> &r)
{
    int n = r.size();
    std::vector<Event> Qv, Qh;

    for (int i = 0; i < r.size(); i++) {
        Qv.push_back(Event(real(r[i][0]), 0, i));
        Qv.push_back(Event(real(r[i][1]), 1, i));

        Qh.push_back(Event(imag(r[i][0]), 1, i));
        Qh.push_back(Event(imag(r[i][1]), 0, i));
    }

    std::sort(Qv.begin(), Qv.end());
    std::sort(Qh.begin(), Qh.end());

    double area = 0.0;
    std::vector<bool> in_set(n);

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

    return area;
}


int main(void)
{
    int n;
    double x1, y1, x2, y2;

    std::cin >> n;
    std::vector<Rectangle> recs;

    REP(i, n) {
        std::cin >> x1 >> x2 >> y2 >> y1;
        recs.push_back(Rectangle(Point(x1, y1), Point(x2, y2)));
    }

    double area = union_area2(recs);
    std::cout << area << std::endl;
    return 0;
}
