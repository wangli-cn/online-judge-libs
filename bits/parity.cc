#include <iostream>

using namespace std;

bool get_parity(unsigned n)
{
    bool parity = false;

    while (n > 0) {
        parity = !parity;
        n = n & (n-1);
    }
    return parity;
}

int main()
{
    unsigned n = 64;

    cout << get_parity(n) << endl;
    return 0;
}
