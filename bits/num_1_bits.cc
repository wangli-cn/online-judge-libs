#include <iostream>

using namespace std;

int num_1_bits(unsigned x)
{
    int cnt = 0;
    while (x > 0) {
        cnt++; x = x & (x-1);
    }

    return cnt;
}

int main()
{
    cout << num_1_bits(10) << endl;
    return 0;
}
