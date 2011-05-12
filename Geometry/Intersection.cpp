#include <iostream>
#include <complex>
#include <vector>

using namespace std;

const double EPS = 1e-8;
const double INF = 1e12;

typedef complex<double> Point;

double cross(const Point &a, const Point &b)
{
    return imag(conj(a) * b);
}

double dot(const Point &a, const Point &b) 
{
    return real(conj(a) * b);
}

struct L: public vector<Point> 
{
    L(const Point &a, const Point &b) {
        push_back(a); push_back(b);
    }
};

int ccw(Point a, Point b, Point c)
{
    b -= a; c -= a;
    if (cross(b, c) > 0) return 1;
    if (cross(b, c) < 0) return -1;
    if (dot(b, c) < 0) return 2;
    if (norm(b) < norm(c)) return -2;
    return 0;
}

bool intersectLL(const L &l, const L &m)
{
    return abs(cross(l[1] - l[0], m[1] - m[0])) > EPS ||
           abs(cross(l[1] - l[0], m[0] - l[0])) < EPS;
}

bool intersectLS(const L &l, const L &s)
{
    return cross(l[1] - l[0], s[0] - l[0]) *
           cross(l[1] - l[0], s[1] - l[0]) < EPS;
}

bool intersectLP(const L &l, const Point &p)
{
    return abs(cross(l[1] - p, l[0] - p)) < EPS;
}

bool intersectSS(const L &s, const L &t) 
{
    return ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) <= 0 &&
           ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) <= 0;
}

bool intersectSP(const L &s, const Point &p)
{
    return abs(s[0] - p) + abs(s[1] - p) - abs(s[1] - s[0]) < EPS;
}

int main(void)
{
    return 0;
}
