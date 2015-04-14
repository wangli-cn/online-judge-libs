#include <iostream>
#include <complex>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>

const double pi = 2 * std::acos(0);
const double EPS = 1e-9;

using Point = std::complex<double>;

Point pivot;

std::ostream& operator<<(std::ostream& out, const Point& c)
{
    out << "(" << real(c) << "," << imag(c) << ")";
    return out;
}

double dot(const Point a, const Point b)
{
    return real(conj(a) * b);
}

double cross(const Point a, const Point b)
{
    return imag(conj(a) * b);
}

double dist(const Point a, const Point b){
    return std::sqrt(dot(b-a, b-a));
}

double distsqr(const Point a, const Point b){
    return dot(b-a, b-a);
}


bool angle_cmp(const Point self, const Point that){
    int t = cross(that - pivot, self - pivot);
    if (std::fabs(t) < EPS){
        return (distsqr(pivot, self) < distsqr(pivot, that));
    } else if (t < EPS) {
        return true;
    } else {
        return false;
    }
}

std::vector<Point> graham(std::vector<Point> p){
    for (int i = 1; i < p.size(); ++i) {
        if (imag(p[i]) < imag(p[0]) || (imag(p[i]) == imag(p[0]) && real(p[i]) < real(p[0]))) {
            std::swap(p[0], p[i]);
        }
    }

    pivot = p[0];
    std::sort(p.begin(), p.end(), angle_cmp);

    std::vector<Point> chull(p.begin(), p.begin()+3);
    for (int i = 3; i < p.size(); ++i) {
        while (chull.size() >= 2 && cross(chull[chull.size()-1] - chull[chull.size()-2], p[i] - chull[chull.size()-2]) <= 0) {
            chull.pop_back();
        }
        chull.push_back(p[i]);
    }

    return std::move(chull);
}


int main()
{
    int n;

    std::cin >> n;
    std::vector<Point> p;

    for (int i = 1; i <= n; ++i) {
        int x, y;
        std::cin >> x >> y;
        p.push_back(Point(static_cast<double>(x), static_cast<double>(y)));
    }

    if (n <= 2) {
        std::cout << 0 << std::endl;
    } else {
        std::vector<Point> chull = graham(std::move(p));
        std::cout << chull.size() << std::endl;
    }

    return 0;
}
