#include <vector>
#include <complex>

using namespace std;

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
