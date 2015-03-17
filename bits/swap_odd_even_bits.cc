#include <iostream>

using namespace std;

unsigned int swap_odd_even_bits(unsigned x)
{
    return ( (x & 0xAAAAAAAA) >> 1 ) | ( (x & 0x55555555) << 1);
}

int main()
{
    unsigned x = 0x00000001;

    cout << swap_odd_even_bits(x) << endl;

    return 0;
}
