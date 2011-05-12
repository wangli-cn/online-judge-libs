#include <iostream>
#include <vector>

using namespace std;

int select(vector<int> &a, int k)
{
    for (int l = 0, r = a.size()-1; l <= r; ) {
        int p = a[(l+r)/2];
        int i = l-1, j = r+1;
        while (1) {
            while (a[++i] < p);
            while (a[--j] > p);
            if (i >= j) break;
            swap(a[i], a[j]);
        }

        if (k == i-l) return a[i];
        else if (k < i-l) { r = i-1; }
        else if (k > i-l) { k -= (i-l+1); l = j+1; }
    }
    return -99999999;
}

int main(void)
{
    int a[8] = {1000, 999, 1001, 7, 3, 2, 1, 10000};
    vector<int> vec(a, a+8);
    cout << select(vec, 0) << endl;
    return 0;
}
