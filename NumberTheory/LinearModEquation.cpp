#include <iostream>

using namespace std;

int egcd(int a, int b, int &x, int &y)
{
    if (!b) { x = 1; y = 0; return a; }
    else {
        int d = egcd(b, a%b, y, x);
        y -= (a/b)*x;
    }
}

void linear_mod_equation(int a, int b, int n, int sol[])
{
    int d = egcd(a, n, x, y);
    if (b % d) d = 0;
    else {
        sol[0] = x * (b/d) % n;
        for (int i = 1; i < d; ++i)
            sol[i] = (sol[i-1] + n/d) % n;
    }
}
