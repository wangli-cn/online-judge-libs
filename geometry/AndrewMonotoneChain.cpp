#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#include <iterator>

using namespace std;

const double EPS = 1e-8;
const double INF = 1e12;
typedef complex<double> Point;

namespace std {
    bool operator<(const Point &a, const Point &b) {
        return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
    }
}

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

vector<Point> AndrewMonotoneChain(vector<Point> ps)
{
    int n = ps.size(), k = 0;
    sort(ps.begin(), ps.end());
    vector<Point> ch(2*n);
    for (int i = 0; i < n; ch[k++] = ps[i++])
        while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
    for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]) 
        while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
    ch.resize(k-1);
    return ch;
}

int main(void)
{
    int N;
    while (cin >> N && N) {
        vector<Point> ps;
        
        int x, y;
        for (int i = 0; i < N; ++i) {
            cin >> x >> y;
            ps.push_back(Point(x, y));
        }
        vector<Point> ch = AndrewMonotoneChain(ps); 
        for (int i = 0; i < ch.size(); ++i) {
            cout << real(ch[i]) << " " << imag(ch[i]) << endl;
        }
    }

    return 0;
}
