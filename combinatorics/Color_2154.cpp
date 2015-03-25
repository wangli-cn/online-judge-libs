#include <iostream>
#include <cstdio>

using namespace std;

int pow_mod(int a, int n, int p)
{
    int ans = 1, d = a % p;
    do {
        if (n & 1) ans = (ans * d) % p;
        d = (d * d) % p;
    } while (n >>= 1);
    return ans;
}

int eulerPhi(int n)
{
    if (n == 0) return 0;
    int ans = n;
    for (int x = 2; x*x <= n; ++x) {
        if (n % x == 0) {
            ans -= ans / x;
            while (n % x == 0) n /= x;
        }
    }

    if (n > 1) ans -= ans / n;
    return ans;
}

int main(void)
{
    int nCase;
    scanf("%d", &nCase);
    while (nCase--) {
        int n, p;
        scanf("%d %d", &n, &p);

        long long ans = 0;
        for (int i = 1; i*i <= n; i++) {
            if (n % i == 0) {
                ans = (ans + (eulerPhi(n/i) % p) * pow_mod(n, i-1, p)) % p;
                if (i*i != n) {
                    ans = (ans + (eulerPhi(i) % p) * pow_mod(n, n/i-1, p)) % p;
                }
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}
