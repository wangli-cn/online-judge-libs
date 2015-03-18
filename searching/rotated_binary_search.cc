#include <iostream>
#include <vector>

using namespace std;

const int INF = 999999999;

int binary_search(vector<int> &a, int l, int r, int v)
{
    if (l <= r) {
        int mid = l + (r-l)/2;
        if (a[mid] == v) {
            return mid;
        } else if (a[l] <= a[mid]) {
            if (v > a[mid]) {
                return binary_search(a, mid+1, r, v);
            } else if (a[l] <= v) {
                return binary_search(a, l, mid-1, v);   
            } else {
                return binary_search(a, mid+1, r, v);
            }
        } else {
            if (v < a[mid]) {
                return binary_search(a, l, mid-1, v);
            } else if (v <= a[r]) {
                return binary_search(a, mid+1, r, v);
            } else {
                return binary_search(a, l, mid-1, v);
            }
        }
    }

    return INF;
}

int main(void) 
{
    int arr[8] = {4,5,6,7,0,1,2,3};
    vector<int> a(arr, arr+8);

    cout << binary_search(a, 0, 7, 3) << endl;
    return 0;
}
