#include <iostream>

using namespace std;

int egcd(int a, int b, int &x, int &y)
{
    if (!b) { x = 1; y = 0; return a; }
    else {
        int d = egcd(b, a%b, y, x);
        y -= (a/b)*x;
        return d;
    }
}

int mod(int x, int n)
{
    return (x % n + n) % n;
}

int inverse(int a, int n)
{
    int d, x, y;
    d = egcd(a, n, x, y);
    return d == 1 ? mod(x, n) : -1;
}

int main()
{
    return 0;
}
