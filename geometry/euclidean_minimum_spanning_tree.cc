#include <iostream>
#include <vector>
#include <map>
#include "utils/geometry.h"


using Edge = std::pair<Point, Point>;

class Triangle
{
public:
    Triangle() = delete;
    explicit Triangle(const Point a, const Point b, const Point c) {
        points.push_back(a);
        points.push_back(b);
        points.push_back(c);

        std::sort(points.begin(), points.end());

        edges.push_back(std::make_pair(a, b));
        edges.push_back(std::make_pair(b, c));
        edges.push_back(std::make_pair(a, c));
    }

    bool has_vertex(const Point p) {
        if (points[0] == p || points[1] == p || points[2] == p) {
            return true;
        } else {
            return false;
        }
    }

    std::vector<Point> points;
    std::vector<Edge> edges;
};


bool operator<(const Point &a, const Point &b)
{
    if (real(a)!= real(b)) {
        return real(a) < real(b);
    } else {
        return imag(a) < imag(b);
    }
}


bool operator<(const Triangle &a, const Triangle &b)
{
    for (int i = 0; i < 3; i++) {
        if (a.points[i] != b.points[i]) {
            return a.points[i] < b.points[i];
        }
    }

    return false;
}


bool in_circumcircle(const Point p, const Triangle t)
{
    return true;
}

std::vector<Triangle> BowyerWatson(std::vector<Point> points)
{
    std::map<Triangle, bool> triangulation;
    Triangle big_t(Point(0, 0), Point(1000000000, 0), Point(0, 1000000000));
    triangulation[big_t] = true;

    for (auto p: points) {
        std::vector<Triangle> bad_triangles;

        for (auto t: triangulation) {
            if (in_circumcircle(p, t.first)) {
                bad_triangles.push_back(t.first);
            }
        }

        std::vector<Edge> polygon;
        std::map<Edge, bool> is_used;
        for (auto t: bad_triangles) {
            for (auto e: t.edges) {
                if (!is_used[e]) {
                    is_used[e] = true;
                    polygon.push_back(e);
                }
            }
        }

        for (auto t: bad_triangles) {
            triangulation.erase(t);
        }

        for (auto e: polygon) {
            Triangle t(e.first, e.second, p);
            triangulation[t] = true;
        }
    }

    std::vector<Triangle> results;
    for (auto tri: triangulation) {
        auto t = tri.first;
        if (t.has_vertex(big_t.points[0]) || t.has_vertex(big_t.points[1]) || t.has_vertex(big_t.points[2])) {
            continue;
        } else {
            results.push_back(t);
        }
    }

    return std::move(results);
}


int main()
{
    int n;
    std::cin >> n;
    std::vector<Point> p;
    for (int i = 0; i < n; i++) {
        int a1, a2;
        std::cin >> a1 >> a2;
        p.push_back(Point(a1, a2));
    }

    return 0;
}
