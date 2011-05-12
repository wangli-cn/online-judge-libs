#include <iostream>
#include <sstream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>

#define CLR(x, v) memset(x, v, sizeof(x))

#define REP(i,n) for (int i = 0; i < (int)n; ++i)
#define FOR(i,c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

typedef long long LL;
typedef long double LD;

typedef vector<int> VI;
typedef vector<long long> VLL;
typedef vector<string> VS;

template <class Type>
void print_elements(Type elem) { cout << elem << " "; }

const double EPS = 1e-8; 
const double INF = 1e12;

typedef complex<double> Point;
typedef vector<Point> Polygon;

double dot(const Point &a, const Point &b)
{
    return real(conj(a) * b);
}

double cross(const Point &a, const Point &b)
{
    return imag(conj(a) * b);
}

enum { OUT = 0, ON, IN };

int convexContains(const Polygon &P, const Point &p)
{
    int n = P.size();
    Point g = (P[0] + P[n/3] + P[2*n/3]) / 3.0;

    int a = 0, b = n;
    while (a + 1 < b) {
        int c = (a+b)/2;

        if (cross(P[a] - g, P[c] - g) > 0) {
            if (cross(P[a] - g, p - g) > 0 && cross(P[c] - g, p - g) < 0) b = c;
            else a = c;
        } else {
            if (cross(P[a] - g, p - g) < 0 && cross(P[c] - g, p - g) > 0) a = c;
            else b = c;
        }
    }

    b %= n;
    if (cross(P[a] - p, P[b] - p) < 0) return OUT;
    if (cross(P[a] - p, P[b] - p) > 0) return IN;
    return ON;
}

#define EQ(x,y) (fabs((double)(x-y)) < EPS)
#define GE(x,y) ((x-y) > -EPS)
#define LE(x,y) ((y-x) > -EPS)

bool intersect1Pt(const Point &a, const Point &b,
                  const Point &c, const Point &d, Point &r)
{
    double D = cross(b-a, d-c);

    if (EQ(D, 0)) return false;

    double t = cross(c-a, d-c) / D;
    double s = -cross(a-c, b-a) / D;
    r = a + t * (b-a);

    return GE(t, 0) && LE(t, 1) && GE(s, 0) && LE(s, 1);
}

Polygon convexIntersect(const Polygon &P, const Polygon &Q) 
{
    int n = P.size(), m = Q.size();
    int a = 0, b = 0, aa = 0, ba = 0;
    enum { Pin, Qin, Unknown } in = Unknown;

    Polygon R;

    do {
        int a1 = (a+n-1) % n, b1 = (b+m-1) % m;
        double C = cross(P[a] - P[a1], Q[b] - Q[b1]);
        double A = cross(P[a1] - Q[b], P[a] - Q[b]);
        double B = cross(Q[b1] - P[a], Q[b] - P[a]);
        Point r;

        if (intersect1Pt(P[a1], P[a], Q[b1], Q[b], r)) {
            if (in == Unknown) aa = ba = 0;
            R.push_back(r);
            in = B > 0 ? Pin : A > 0 ? Qin : in;
        }

        if (C == 0 && B == 0 && A == 0) {
            if (in == Pin) { b = (b+1) % m; ++ba; }
            else { a = (a+1) % n; ++aa; }
        } else if (C >= 0) {
            if (A > 0) {
                if (in == Pin) 
                    R.push_back(P[a]); 
                a = (a+1)%n; ++aa; 
            } else {
                if (in == Qin)
                    R.push_back(Q[b]);
                b = (b+1)%m; ++ba;
            }
        } else {
            if (B > 0) {
                if (in == Qin)
                    R.push_back(Q[b]);
                b = (b+1)%m; ++ba;
            } else {
                if (in == Pin)
                    R.push_back(P[a]);
                a = (a+1)%n; ++aa;
            }
        }
    } while ( (aa < n || ba < m) && aa < 2*n && ba < 2*m );

    if (in == Unknown) {
        if (convexContains(Q, P[0])) return P;
        if (convexContains(P, Q[0])) return Q;
    }

    return R;
}

#define curr(P,i) P[i]
#define next(P,i) P[(i+1)%P.size()]

double area(const Polygon &P)
{
    double A = 0;
    REP(i, P.size()) {
        A += cross(curr(P,i), next(P,i));
    }

    return A/2.0;
}

int main(void)
{

    return 0;
}
