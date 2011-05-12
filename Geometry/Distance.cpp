#include <iostream>
#include <complex>
#include <vector>
#include <cassert>

using namespace std;

const double EPS = 1e-8;
const double INF = 1e12;

typedef complex<double> Point;

struct L: public vector<Point>
{
    L(const Point &a, const Point &b) {
        push_back(a); push_back(b);
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

bool intersectSS(const L &s, const L &t)
{
    return ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) <= 0 &&
           ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) <= 0;
}

bool intersectSP(const L &s, const Point &p)
{
    return abs(s[0] - p) + abs(s[1] - p) - abs(s[1] - s[0]) < EPS;
}

Point projection(const L &l, const Point &p)
{
    double t = dot(p - l[0], l[0] - l[1]) / norm(l[0] - l[1]);
    return l[0] + t * (l[0] - l[1]);
}

Point reflection(const L &l, const Point &p)
{
    Point a = (projection(l, p) - p);
    real(a) *= 2; imag(a) *= 2;
    return p + a;
}

double distanceLP(const L &l, const Point &p)
{
    return abs(p - projection(l, p));
}

double distanceLL(const L &l, const L &m) 
{
    return intersectLL(l, m) ? 0 : distanceLP(l, m[0]);
}

double distanceLS(const L &l, const L &s)
{
    if (intersectLS(l, s)) return 0;
    return min(distanceLP(l, s[0]), distanceLP(l, s[1]));
}

double distanceSP(const L &s, const Point &p)
{
    const Point r = projection(s, p);
    if (intersectSP(s, r)) return abs(r - p);
    return min(abs(s[0] - p), abs(s[1] - p));
}

double distanceSS(const L &s, const L &t)
{
    if (intersectSS(s, t)) return 0;
    return min(min(distanceSP(s, t[0]), distanceSP(s, t[1])),
               min(distanceSP(t, s[0]), distanceSP(t, s[1])));
}

Point crosspoint(const L &l, const L &m)
{
    double A = cross(l[1] - l[0], m[1] - m[0]);
    double B = cross(l[1] - l[0], l[1] - m[0]);

    if (abs(A) < EPS && abs(B) < EPS) return m[0]; //same line
    if (abs(A) < EPS) assert(false);
    return m[0] + B / A * (m[1] - m[0]);
}

int main(void)
{
    return 0;
}
