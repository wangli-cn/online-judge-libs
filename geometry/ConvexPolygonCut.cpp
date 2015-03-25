#include <iostream>
#include <vector>
#include <complex>
#include <cassert>

using namespace std;

#define curr(P, i) P[i]
#define next(P, i) P[(i+1)%P.size()]

typedef complex<double> Point;
typedef vector<Point> Polygon;

struct L: public vector<Point> 
{
    L(const Point &a, const Point &b) {
        push_back(a); push_back(b);
    }
};

const double EPS = 1e-8;

double dot(const Point &a, const Point &b)
{
    return real(conj(a) * b);
}

double cross(const Point &a, const Point &b)
{
    return imag(conj(a) * b);
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

Point crosspoint(const L &l, const L &m)
{
    double A = cross(l[1] - l[0], m[1] - m[0]);
    double B = cross(l[1] - l[0], l[1] - m[0]);
    if (abs(A) < EPS && abs(B) < EPS) return m[0];
    if (abs(A) < EPS) assert(false);
    return m[0] + B/A * (m[1] - m[0]);
}

Polygon convex_cut(const Polygon &P, const L &l)
{
    Polygon Q;
    for (int i = 0; i < P.size(); ++i) {
        Point A = curr(P, i), B = next(P, i);
        if (ccw(l[0], l[1], A) != -1) Q.push_back(A);
        if (ccw(l[0], l[1], A) * ccw(l[0], l[1], B) < 0)
            Q.push_back(crosspoint(L(A, B), l));
    }
    return Q;
}

int main(void)
{
    Polygon P;

    P.push_back(Point(0, 0));
    P.push_back(Point(2, 0));
    P.push_back(Point(2, 2));
    P.push_back(Point(0, 2));

    L l = L(Point(1,0), Point(1,2));
    Polygon Q = convex_cut(P, l);

    for (int i = 0; i < Q.size(); ++i) {
        cout << real(Q[i]) << " " << imag(Q[i]) << endl;
    }

    return 0;
}
