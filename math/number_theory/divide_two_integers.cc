//============================================================================
// Divide two integers without using multiplication, division and mod operator.
//============================================================================

#include <iostream>

using namespace std;

unsigned int unsigned_divide(unsigned int dividend, unsigned int divisor)
{
    unsigned int quotient = 0;
    while (dividend >= divisor) {
        unsigned int tmp = divisor;
        unsigned int shift = 0;
        while ((tmp << 1) <= dividend) {
            tmp <<= 1;
            shift += 1;
        }
        dividend -= tmp;
        quotient |= (1 << shift);
    }

    return quotient;
}

int main()
{
    unsigned int a = 100, b = 2;

    cout << unsigned_divide(a, b) << endl;
    return 0;
}
