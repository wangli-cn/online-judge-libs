//============================================================================
// Given two sorted integer arrays A and B, merge B into A as one sorted array.
//
// Note:
// You may assume that A has enough space to hold additional elements from B.
// The number of elements initialized in A and B are m and n respectively.
//============================================================================


#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &a, vector<int> &b)
{
    int m = a.size(), n = b.size();
    int i = m-1, j = n-1, k = m+n-1;

    while (i >= 0 && j >= 0) {
        if (a[i] >= b[j]) a[k--] = a[i--];
        else a[k--] = b[j--];
    }

    while (i >= 0) a[k--] = a[i--];
    while (j >= 0) a[k--] = b[j--];
}

int main()
{
    return 0;
}
