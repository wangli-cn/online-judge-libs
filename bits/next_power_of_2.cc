#include <iostream>

using namespace std;

unsigned next_pow2(unsigned n)
{
    unsigned cnt = 0;

    if (n && !(n & (n-1))) return n;

    while (n > 0) {
        n >>= 1;
        cnt += 1;
    }

    return (1 << cnt);
}


unsigned next_pow2_(unsigned n)
{
    unsigned p = 1;

    if (n && !(n & (n-1))) return n;

    while (p < n) {
        p <<= 1;
    }
    return p;
}

unsigned next_pow2_32bit(unsigned n)
{
    n--;

    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;

    n++;
    return n;
}

int main()
{
    unsigned n = 31;

    cout << next_pow2(n) << endl;
    cout << next_pow2_(n) << endl;
    cout << next_pow2_32bit(n) << endl;

    return 0;
}
