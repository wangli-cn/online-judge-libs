#include <iostream>
#include <vector>
#include <complex>

using namespace std;

#define curr(P,i) P[(i) % P.size()]
#define next(P,i) P[(i+1) % P.size()]
#define prev(P,i) P[(i+P.size()-1) % P.size()]

typedef complex<double> Point;
typedef vector<Point> Polygon;

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

bool isConvex(const Polygon &P)
{
    for (int i = 0; i < P.size(); ++i) 
        if (ccw(prev(P, i), curr(P, i), next(P, i)) > 0) return false;
    return true;
}

int main(void)
{
    return 0;
}
