#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (b) while (b ^= a ^= b ^= a %= b);
    return a;
}

int main(void)
{
    int c, s;
    while (cin >> c >> s && c && s) {
        int powc[64];
        int answer = 0;

        powc[0] = 1;
        for (int i = 0; i <= s; ++i)
            powc[i+1] = powc[i] * c;

        if (s % 2 == 1) answer = s * powc[s/2 + 1];
        else answer = (s/2) * powc[s/2] + (s/2) * powc[s/2 + 1];

        for (int i = 1; i <= s; ++i)
            answer += powc[gcd(i, s)];

        cout << answer / (2 * s) << endl;
    }

    return 0;
}
