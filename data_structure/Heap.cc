#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <cstdio>
#include <cassert>

#define REP(i,n) for (int i = 0; i < (int)n; ++i)
#define FOR(i,c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

typedef long long LL;
typedef long double LD;

typedef vector<int> VI;
typedef vector<long long> VLL;
typedef vector<string> VS;

void MinHeapify(vector<int> &a, int i)
{
    int n = a.size();
    int j;

    for (j = 2*i+1; j < n; i = j, j = 2*i+1) {
        if ((j+1 < n) && a[j+1] < a[j]) j++;
        if (a[j] > a[i]) break;

        swap(a[i], a[j]);
    }
}

void BuildMinHeap(vector<int> &a)
{
    for (int i = (a.size()-1) / 2; i >= 0; i--) 
        MinHeapify(a, i);
}

int ExtractMin(vector<int> &a)
{
    int n = a.size();

    assert(n >= 1);

    int m = a[0];
    a[0] = a[n-1];
    a.resize(n-1);
    MinHeapify(a, 0);
    return m;
}


int main(void)
{
    int a[8] = {8, 6, 7, 1, 2, 4, 3, 5};
    vector<int> vec(a, a+8);

    BuildMinHeap(vec);
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    REP(i, 8) cout << ExtractMin(vec) << " ";
    cout << endl;

    return 0;
}
