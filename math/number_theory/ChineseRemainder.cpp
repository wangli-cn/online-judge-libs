int chinese_remainder(int n, int a[], int m[])
{
    int M = 1, dummy;
    for (int i = 0; i < n; ++i) M *= m[i];
    for (int i = 0; i < n; ++i) {
        w = M / m[i];
        dummy = egcd(m[i], w, dummy, y);
        x = (x + y * w * a[i]) % M;
    }
    return (n + x % M) % M;
}
