#include <iostream>

int gcd_recursive(int a, int b)
{
    if (!b) return a;
    else return gcd_recursive(b, a%b);
}

int gcd_iterative(int a, int b)
{
    if (b) while (b ^= a ^= b ^= a %= b);
    return a;
}

int gcd_iterative2(int a, int b)
{
    while (b) { int t = a%b; a = b; b = t; }
    return a;
}

int gcd_iterative3(int a, int b)
{
    int t = 1, c, d;
    while (a != b) {
        if (a < b) std::swap(a, b);
        if (!(a & 1)) { a >>= 1; c = 1; } else { c = 0; }
        if (!(b & 1)) { b >>= 1; d = 1; } else { d = 0; }
        if (c && d) t <<= 1;
        else if (!c && !d) a -= b;
    }
    return t * a;
}

int main()
{
    std::cout << gcd_recursive(10, 32) << std::endl;
    std::cout << gcd_iterative(10, 32) << std::endl;
    std::cout << gcd_iterative2(10, 32) << std::endl;
    std::cout << gcd_iterative3(10, 32) << std::endl;
    return 0;
}
