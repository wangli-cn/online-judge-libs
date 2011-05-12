#include <iostream>
#include <iterator>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; ++i)

void CountingSort(int a[], int n, int K)
{
    int *c = new int[K+1], j = 0;
    REP(i, n) ++c[a[i]];
    REP(k, K) REP(i, c[k]) a[j++] = k;
    delete [] c;
}

int main(void)
{
    int a[8] = {7, 5, 4, 4, 4, 1, 3, 100};

    CountingSort(a, 8, 100);
    copy(a, a+8, ostream_iterator<int>(cout, " "));

    return 0;
}

