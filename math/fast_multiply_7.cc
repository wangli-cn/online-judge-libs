#include <iostream>

using namespace std;

unsigned fast_multiply7(unsigned n)
{
    return (n << 3) - n;
}

int main()
{
    std::cout << fast_multiply7(3) << std::endl;
    return 0;
}
