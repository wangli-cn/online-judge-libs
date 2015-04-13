//Write an efficient C program to find smallest and second smallest element in an array.

#include <iostream>
#include <vector>
#include <limits>

std::pair<int, int> first_two_smallest(std::vector<int> &a)
{
    int f1 = std::numeric_limits<int>::max(), f2 = std::numeric_limits<int>::max();
    int n = a.size();

    for (int i = 0; i < n; i++) {
        if (a[i] < f1) {
            f2 = f1;
            f1 = a[i];
        } else if (a[i] < f2 && f1 != a[i]) {
            f2 = a[i];
        }
    }

    return std::make_pair(f1, f2);
}

int main()
{
    return 0;
}
