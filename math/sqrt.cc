#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

double sqrt(double x)
{
    double t1 = 1.0, t2;

    for (int i = 0; i < 10000; i++) {
        t2 = 0.5 * (t1 + x / t1);
        t1 = t2;
    }

    return t2;
}

double sqrt_bsearch(double x)
{
    assert(x > 0.0);
    double u, l;

    if (x >= 1.0) {
        l = 1.0;
        u = x;
    } else {
        l = 0.0;
        u = 1.0;
    }

    double epsilon = 1e-5;

    while (fabs(u-l) > epsilon) {
        double m = (u+l) / 2.0;

        if (m * m > x) {
            u = m;
        } else {
            l = m;
        }
    }

    return l;
}

int main()
{
    printf("%lf\n", sqrt(50));
    printf("%lf\n", sqrt_bsearch(50));
    return 0;
}
