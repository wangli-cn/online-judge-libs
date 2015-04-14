#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>

using namespace std;

#define REP(i,n) for(int i = 0; i < (int)n; ++i)
#define ALL(c) (c).begin(), (c).end()

const double EPS = 1e-8;
const double INF = 1e12;
typedef complex<double> Point;

namespace std {
    bool operator<(const Point &a, const Point &b) {
        return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
    }
}

pair<Point, Point> closestPair(vector<Point> p)
{
    int n = p.size();
    int s = 0, t = 1, m = 2;
    int S[n];
    S[0] = 0, S[1] = 1;
    sort(ALL(p));  //p < q <=> p.x < q.x

    double d = norm(p[s] - p[t]);
    for (int i = 2; i < n; S[m++] = i++) REP(j, m) {
        if (norm(p[S[j]] - p[i]) < d) d = norm(p[s = S[j]] - p[t = i]);
        if (real(p[S[j]]) < real(p[i]) - d) S[j--] = S[--m];
    }
    return make_pair(p[s], p[t]);
}

int main(void)
{
    vector<Point> p;
    p.push_back(Point(0, 1));
    p.push_back(Point(1, 1));
    p.push_back(Point(100, 0));
    p.push_back(Point(-10, 1));
    p.push_back(Point(10, 10));

    pair<Point, Point> res = closestPair(p);
    cout << real(res.first) << ", " << imag(res.first) << endl;
    cout << real(res.second) << ", " << imag(res.second) << endl;

    return 0;
}
