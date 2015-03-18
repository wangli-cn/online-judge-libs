//============================================================================
// Search in Rotated Sorted Array
// Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
// You are given a target value to search. If found in the array return its
// index, otherwise return -1.
//
// You may assume no duplicate exists in the array.
//============================================================================

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
            } else { //v < a[l]
                return binary_search(a, mid+1, r, v);
            }
        } else {
            if (v < a[mid]) {
                return binary_search(a, l, mid-1, v);
            } else if (v <= a[r]) {
                return binary_search(a, mid+1, r, v);
            } else { //v > a[r]
                return binary_search(a, l, mid-1, v);
            }
        }
    }

    return INF;
}

int iterative_binary_search(vector<int> &a, int v)
{
    int l = 0, r = a.size()-1;
    while (l <= r) {
        int mid = l + (r-l)/2;

        if (a[mid] == v) {
            return mid;
        } else if (a[l] <= a[mid]) {
            if (a[l] <= v && v <= a[mid]) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        } else {
            if (a[mid] < v && v <= a[r]) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
    }

    return INF;
}

int main(void)
{
    vector<int> a {4,5,6,7,0,1,2,3};

    cout << binary_search(a, 0, 7, 3) << endl;
    cout << iterative_binary_search(a, 3) << endl;
    return 0;
}
