// Field Test: http://tioj.ck.tp.edu.tw/problems/1004
//
#include <iostream>

int joseph(int n, int m)
{
    int i = 0;
    for (int k = 1; k <= n; k++) {
        i = (i+m) % k;
    }
    return i;
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << joseph(n, 2)+1 << std::endl;

    return 0;
}
