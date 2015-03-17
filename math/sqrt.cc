#include <cstdio>
#include <cstring>

double sqrt(double x)
{
    double t1 = 1.0, t2;

    for (int i = 0; i < 10000; i++) {
        t2 = 0.5 * (t1 + x / t1);
        t1 = t2;
    }

    return t2;
}

int main()
{
    printf("%lf", sqrt(50));
    return 0;
}
