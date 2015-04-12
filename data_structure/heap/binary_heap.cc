#include <iostream>
#include <vector>
#include <cassert>

void min_heapify(std::vector<int> &a, int i)
{
    const int n = a.size();
    int j;

    for (j = i+i+1; j < n; i = j, j = i+i+1) {
        if (j+1 < n && a[j] > a[j+1]) j++;
        if (a[j] > a[i]) break;
        std::swap(a[i], a[j]);
    }
}

void build_minheap(std::vector<int> &a)
{
    for (int i = (a.size()-1)/2; i >= 0; i--) {
        min_heapify(a, i);
    }
}

int extract_min(std::vector<int> &a)
{
    const int n = a.size();
    assert(n >= 1);

    int m = a[0];
    a[0] = a[n-1];
    a.resize(n-1);
    min_heapify(a, 0);
    return m;
}

int main()
{
    std::vector<int> a {1,2,3,4,5,6,7,8,9};

    build_minheap(a);

    int n = a.size();
    for (int i = 0; i < n; i++) {
        auto elm = extract_min(a);
        std::cout << elm << " ";
    }
    std::cout << std::endl;


    return 0;
}
