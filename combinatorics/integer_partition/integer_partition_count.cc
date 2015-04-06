#include <iostream>

int integer_partition(int n, int m)
{
    if (n == 1 || m == 1) return 1;
    if (n < m) return integer_partition(n, n);
    if (n == m) return 1 + integer_partition(n, m-1);
    else return integer_partition(n, m-1) + integer_partition(n-m, m);
}

int main(void)
{
    int n;

    std::cin >> n;
    std::cout << integer_partition(n, n) << std::endl;
    return 0;
}
