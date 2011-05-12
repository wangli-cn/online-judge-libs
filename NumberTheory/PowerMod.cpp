#include <iostream>
#include <cmath>

using namespace std;

int mul_mod1(int x, int y, int n)
{
    //guarantee not to overflow
    int T = floor(sqrt(n) + 0.5);
    int t = T*T - n;

    int a = x/T; int b = x%T;
    int c = y/T; int d = y%T;
    int e = a*c/T; int f = a*c%T;

    int v = ((a*d + b*c)%n + e*t) % n;
    int g = v/T; int h = v%T;
    int ans = (((f + g)*t % n + b*d) % n + h*T) % n;
    while (ans < 0) ans += n;
    return ans;
}

int mul_mod2(int x, int y, int n)
{
    //possibly overflow in x*y
    return (x*y) % n;
}

// a^n mod p
int pow_mod1(int a, int n, int p)
{
    int ans = 1, d = a % p;
    do {
        if (n & 1) ans = mul_mod1(ans, d, p);
        d = mul_mod1(d, d, p);
    } while (n >>= 1);
    return ans;
}

int pow_mod2(int a, int n, int p)
{
    int ans = 1, d = a % p;
    do {
        if (n & 1) ans = mul_mod2(ans, d, p);
        d = mul_mod2(d, d, p);
    } while (n >>= 1);
    return ans;
}

int main(void)
{
    int a, n, p;
    while (cin >> a >> n >> p) {
        cout << pow_mod1(a, n, p) << endl;
        cout << pow_mod2(a, n, p) << endl;
    }
    return 0;
}
