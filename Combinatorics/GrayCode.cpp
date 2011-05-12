#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void gray_code(int n)
{
    vector<bool> bits(n, false);

    int i;
    bool even = true;
    while (1) {
        if (even) 
            bits[0] = !bits[0];
        else {
            for (i = 0; i < n && !bits[i]; ++i);
            if (i == n-1) break;
            bits[i+1] = !bits[i+1];
        }

        for (i = n-1; i >= 0; --i) {
            putchar(bits[i] ? '1' : '0');
        }
        putchar('\n');
        even = !even;
    }
}

int main(void)
{
    int n;
    cin >> n;
    gray_code(n);
    return 0;
}
