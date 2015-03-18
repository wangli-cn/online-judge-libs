#include <iostream>
#include <vector>

using namespace std;

int lower_bound(vector<int> &a, int val)
{
    int n = a.size();
    int l = 0, r = n-1;

    while (l < r) {
        int mid = l + ((r-l) / 2);
        if (a[mid] < val) l = mid+1;
        else r = mid;
    }

    if (l < n && a[l] == val) return l;
    else return -1;
}

bool check(vector<int> &a, int x)
{
    int n = a.size();
    int idx = lower_bound(a, x);
    if (idx == -1) return false;

    if ( ((idx+n/2) <= n-1) && (a[idx+n/2] == x)) {
        return true;
    } else {
        return false;
    }
}

int main()
{
    return 0;
}
