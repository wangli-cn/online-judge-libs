#include <cstdio>

using namespace std;

void binary_rep(unsigned n)
{
    int t;
    if (n > 0) {
        t = n % 2;
        binary_rep(n >>= 1);
        printf("%d", t);
    }
}

int main()
{
    binary_rep(10);
    return 0;
}
