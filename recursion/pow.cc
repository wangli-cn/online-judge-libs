//============================================================================
// Pow(x, n)
// Implement pow(x, n).
//============================================================================

#include <iostream>

double go(double x, int n)
{
    if (n == 0) return 1;
    else if (n % 2 == 0) return go(x, n/2) * go(x, n/2);
    else return x * go(x, n/2) * go(x, n/2);
}

double pow(double x, int n)
{
    int sign = 1;
    if (n < 0) sign = -sign, n = -n;
    double res = go(x, n);
    if (sign < 0) return 1.0 / res;
    else return res;
}


int main()
{
    std::cout << pow(2, -10) << std::endl;
}
