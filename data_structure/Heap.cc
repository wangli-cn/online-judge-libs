#include <iostream>

using namespace std;

void min_heapify(vector<int> &a, int i)
{
    const int n = a.size();
    int j;

    for (j = i+i+1; j < n; i = j, j = i+i+1) {
        if (j+1 < n && a[j] > a[j+1]) j++;
        if (a[j] > a[i]) break;
        swap(a[i], a[j]);
    }
}

void build_minheap(vector<int> &a)
{
    for (int i = (a.size()-1)/2; i >= 0; i--) {
        min_heapify(a, i);
    }
}

int extract_min(vector<int> &a)
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
    return 0;
}
