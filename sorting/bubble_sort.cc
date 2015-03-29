#include <vector>
#include "utils/common.h"

void bubble_sort(std::vector<int> &a)
{
    int n = a.size();
    bool swapped;

    do {
        swapped = false;
        n -= 1;
        for (int i = 0; i < n; i++) {
            if (a[i] > a[i+1]) {
                std::swap(a[i], a[i+1]);
                swapped = true;
            }
        }
    } while (swapped);
}

int main()
{
    std::vector<int> a { 6, 5, 4, 3, 2, 1 };
    bubble_sort(a);
    print_container(a);
    return 0;
}
