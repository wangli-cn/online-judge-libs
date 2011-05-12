#include <iostream>
#include <vector>
#include <complex>

using namespace std;

#define curr(P,i) P[i]
#define next(P,i) P[(i+1)%P.size()]

typedef complex<double> Point;
typedef vector<Point> Polygon;

enum {OUT, ON, IN};

double cross(const Point &a, const Point &b)
{
    return imag(conj(a) * b);
}

double dot(const Point &a, const Point &b)
{
    return real(conj(a) * b);
}

int SimplePolygonContains(const Polygon &P, const Point &p)
{
    bool in = false;
    for (int i = 0; i < P.size(); ++i) {
        Point a = curr(P,i) - p, b = next(P,i) - p;
        if (imag(a) > imag(b)) swap(a, b);
        if (imag(a) <= 0 && 0 < imag(b))
            if (cross(a, b) < 0) in = !in;
        if (cross(a, b) == 0 && dot(a, b) <= 0) return ON;
    }
    return in ? IN : OUT;
}

int main(void)
{
    return 0;
}
