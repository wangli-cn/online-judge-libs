#include <iostream>
#include <cmath>

using namespace std;

double TriangleAreaFromMedians(double m1, double m2, double m3)
{
    double x = 0.5 * (m1 + m2 + m3);
    double a = x * (x - m1) * (x - m2) * (x - m3);
    if (a < 0.0) return -1.0;
    else return sqrt(a) * 4.0 / 3.0;
}

int main(void)
{
    //should be 5.196
    cout << TriangleAreaFromMedians(3, 3, 3) << endl;
    return 0;
}
