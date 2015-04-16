#include <iostream>

const int MAXN = 100;

long long C(int n, int r)
{
    long long c[MAXN];
    for (int i = 0; i <= r; ++i)
        c[i] = 1LL;

    for (int i = 0; i <= n-r; ++i) {
        for (int j = 1; j <= r; ++j)
            c[j] += c[j-1];
    }

    return c[r];
}

int main()
{
    return 0;
}
