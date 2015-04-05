#ifndef __GEOMETRY
#define __GEOMETRY

#include <vector>
#include <complex>
#include "utils/common.h"

using Point = std::complex<double>;
using Polygon = std::vector<Point>;

class Segment: public std::vector<Point>
{
public:
    Segment() = delete;
    explicit Segment(const Point &a, const Point &b) {
        push_back(a);
        push_back(b);
    }
};

class Rectangle: public std::vector<Point>
{
public:
    Rectangle() = delete;
    explicit Rectangle(const Point a, const Point b) {
        push_back(a);
        push_back(b);
    }
};


double cross(const Point &a, const Point &b)
{
    return imag(conj(a) * b);
}

double dot(const Point &a, const Point &b)
{
    return real(conj(a) * b);
}

int ccw(Point a, Point b, Point c)
{
    b -= a; c -= a;
    if (cross(b, c) > 0) return 1;
    if (cross(b, c) < 0) return -1;
    if (dot(b, c) < 0) return 2;
    if (norm(b) < norm(c)) return -2;
    return 0;
}

#endif
