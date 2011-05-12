#include <iostream>

using namespace std;

int binary_search1(vector<int> &a, int l, int r, int v)
{
    while (l < r) {
        int mid = l + ((r-l)/2);
        if (a[mid] < v) l = mid+1;
        else r = mid;
    }
    //r == l, using r or l depends on taste
    if ((l < a.size()) && a[l] == v) return l;
    else return -1;
}

int binary_search2(vector<int> &a, int l, int r, int v)
{
    if (r < l) return -1;
    int mid = l + ((r - l)/2); 
    if (a[mid] > v) return binary_search2(a, l, mid-1, v);
    else if (a[mid] < v) return binary_search2(a, mid+1, r, v);
    else return mid;
}

int main(void)
{
    return 0;
}
