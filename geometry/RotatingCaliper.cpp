#include <iostream>
#include <vector>
#include <complex>

using namespace std;

#define curr(P, i) P[i]
#define next(P, i) P[(i+1)%P.size()]
#define diff(P, i) (next(P,i) - curr(P,i))

typedef complex<double> Point;
typedef vector<Point> Polygon;

double cross(const Point &a, const Point &b)
{
    return imag(conj(a) * b);
}

double RotatingCaliper(const Polygon &pt)
{
    const int n = pt.size();
    int is = 0, js = 0;
    for (int i = 1; i < n; ++i) {
        if (imag(pt[i]) > imag(pt[is])) is = i;
        if (imag(pt[i]) < imag(pt[js])) js = i;
    }

    double maxd = norm(pt[is] - pt[js]);

    int i, maxi, j, maxj;
    i = maxi = is;
    j = maxj = js;
    do {
        if (cross(diff(pt, i), diff(pt, j)) >= 0) j = (j+1) % n;
        else i = (i+1) % n;

        if (norm(pt[i] - pt[j]) > maxd) {
            maxd = norm(pt[i] - pt[j]);
            maxi = i; maxj = j;
        }
    } while (i != is || j != js);
    return maxd; //farthest pair is (maxi, maxj)
}

int main(void)
{
    return 0;
}
