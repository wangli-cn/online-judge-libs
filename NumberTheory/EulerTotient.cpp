#include <iostream>

using namespace std;

#define REP(i, n) for(int i = 0; i < (int) n; ++i)

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

const int N = 1000000;
int eulerPhi_LookUp(int n)
{
    static int lookup = false, p[N], f[N];
    if (!lookup) {
        REP(i, N) p[i] = true, f[i] = i;
        for (int i = 2; i < N; ++i) {
            if (p[i]) {
                f[i] -= f[i] / i;
                for (int j = i+i; j < N; j+= i) 
                    p[j] = false, f[j] -= f[j] / i;
            }
        }
        lookup = true;
    }
    return f[n];
}

int main(void)
{
    cout << eulerPhi(420) << endl;
    cout << eulerPhi(7869) << endl;
    cout << eulerPhi_LookUp(39) << endl;
    cout << eulerPhi_LookUp(13) << endl;
    return 0;
}
