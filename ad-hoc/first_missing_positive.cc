//============================================================================
// Given an unsorted integer array, find the first missing positive integer.
//
// For example,
// Given [1,2,0] return 3,
// and [3,4,-1,1] return 2.
//
// Your algorithm should run in O(n) time and uses constant space.
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

int first_missing(vector<int> a)
{
    int n = a.size();

    int i = 0;
    while (i < n) {
        if (a[i] != i+1 && a[i] >= 0 && a[i] < n && a[a[i]-1] != a[i]) {
            swap(a[i], a[a[i] - 1]);
        } else {
            i++;
        }
    }

    for (i = 0; i < n; i++) {
        if (a[i] != i+1) break;
    }

    return i+1;
}

int main(void)
{
    vector<int> input {1,7,2,4,5,3,10,9};
    cout << first_missing(input) << endl;
}
