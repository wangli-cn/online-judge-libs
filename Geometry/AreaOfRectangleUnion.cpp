#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>

using namespace std;

typedef complex<double> Point;

struct Rectangle
{
    Point a; //upper-left
    Point b; //lower-right
    Rectangle(Point a, Point b)
        :a(a), b(b) {}
};

bool isBound(const Rectangle &r, const Rectangle &s)
{
    if ((real(r.a) >= real(s.a)) && (imag(r.a) <= imag(s.a)) && 
        (real(r.b) <= real(s.b)) && (imag(r.b) >= imag(s.b))) {
        return true;
    }
    return false;
}

//O(n^2)
double unionArea(vector<Rectangle> &r)
{
    int n = r.size();
    vector<double> discrete_x;
    vector<double> discrete_y;

    for (vector<Rectangle>::iterator i = r.begin(); i != r.end(); ++i) {
        discrete_x.push_back(real(i->a)); discrete_y.push_back(imag(i->a));
        discrete_x.push_back(real(i->b)); discrete_y.push_back(imag(i->b));
    }
    
    sort(discrete_x.begin(), discrete_x.end());
    sort(discrete_y.begin(), discrete_y.end());

    double area = 0.0;
    int t = discrete_x.size();
    for (int i = 0; i < t-1; ++i) {
        for (int j = 0; j < t-1; ++j) {
            for (int k = 0; k < n; ++k) {
                Rectangle s(Point(discrete_x[i], discrete_y[j]), Point(discrete_x[i+1], discrete_y[j+1]));
                if (isBound(s, r[k])) {
                    area += (discrete_x[i+1] - discrete_x[i]) * (discrete_y[j+1] - discrete_y[j]);
                    break;
                }
            }
        }
    }
}

int main(void)
{
    return 0;
}
