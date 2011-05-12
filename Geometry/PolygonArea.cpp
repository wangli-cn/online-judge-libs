#include <iostream>
#include <complex>
#include <vector>

using namespace std;

typedef complex<double> Point;
typedef vector<Point> Polygon;

double cross(const Point &a, const Point &b)
{
    return imag(conj(a) * b);
}

#define curr(P,i) P[i]
#define next(P,i) P[(i+1)%P.size()]

double area2(const Polygon &P)
{
    double A = 0;
    for (int i = 0; i < P.size(); ++i)
        A += cross(curr(P, i), next(P, i));
    return A;
}

int main(void)
{
    return 0;
}
