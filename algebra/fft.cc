#include <iostream>
#include <complex>
#include <cmath>

using namespace std;

const double PI = 4.0 * atan(1.0);

typedef complex<double> Complex;
const Complex I(0, 1);

void FFT(int n, double theta, Complex a[])
{
    for (int m = n; m >= 2; m >>= 1) {
        int mh = m >> 1;
        for (int i = 0; i < mh; i++) {
            Complex w = exp(i * theta * I);
            for (int j = i; j < n; j += m) {
                int k = j + mh;
                Complex x = a[j] - a[k];
                a[j] += a[k];
                a[k] = w * x;
            }
        }
        theta *= 2;
    }
    int i = 0;
    for (int j = 1; j < n-1; j++) {
        for (int k = n >> 1; k > (i ^= k); k >>= 1);
        if (j < i) swap(a[i], a[j]);
    }
}

int main(void)
{
    return 0;
}
