#include <iostream>
#include <valarray>

using namespace std;

#define PI acos(-1.0)

typedef valarray<double> Point;
const int dim = 3;

double dot(const Point &a, const Point &b)
{
    return (a * b).sum();
}

double GreatCircle(Point a, Point b)
{
    double R = 6378.0;

    bool flip = false;

}

int main(void)
{
    return 0;
}
