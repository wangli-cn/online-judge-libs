//============================================================================
// Search for a Range
// Given a sorted array of integers, find the starting and ending position of
// a given target value.
//
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// If the target is not found in the array, return [-1, -1].
//
// For example,
// Given [5, 7, 7, 8, 8, 10] and target value 8,
// return [3, 4].
//============================================================================


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int recursive_upper_bound(vector<int> &a, int l, int r, int target)
{
    if (l < r) {
        int m = l + (r-l)/2 + 1;

        if (a[m] <= target) return recursive_upper_bound(a, m, r, target);
        else return recursive_upper_bound(a, l, m-1, target);
    } else {
        if (r >= 0 && a[r] == target) return r+1;
        else return r+1;
    }
}

int iterative_upper_bound(vector<int> &a, int target)
{
    int n = a.size();

    int l = 0, r = n-1;
    while (l < r) {
        int m = l + (r-l)/2 + 1;

        if (a[m] <= target) l = m;
        else r = m-1;
    }

    if (r >= 0 && a[r] == target) return r+1;
    else return r+1;
}

int recursive_lower_bound(vector<int> &a, int l, int r, int target)
{
    if (l < r) {
        int m = l + (r-l) / 2;

        if (a[m] < target) return recursive_lower_bound(a, m+1, r, target);
        else return recursive_lower_bound(a, l, m, target);
    } else {
        if (l < a.size() && a[l] == target) return l;
        else return l;
    }
}

int iterative_lower_bound(vector<int> &a, int target)
{
    int n = a.size();

    int l = 0, r = n-1;
    while (l < r) {
        int m = l + (r-l)/2;

        if (a[m] < target) l = m+1;
        else r = m;
    }

    if (l < a.size() && a[l] == target) return l;
    else return l;
}

pair<int, int> recursive_search_range(vector<int> &a, int target)
{
    int n = a.size();
    int l = recursive_lower_bound(a, 0, n-1, target);
    int r = recursive_upper_bound(a, 0, n-1, target);

    return make_pair(l, r);
}

pair<int, int> search_range(vector<int> &a, int target)
{
    int l = iterative_lower_bound(a, target);
    int r = iterative_upper_bound(a, target);

    return make_pair(l, r);
}


int main(void)
{
    vector<int> input {5,7,7,8,8,8,10};

    cout << distance(input.begin(), lower_bound(input.begin(), input.end(), 6)) << endl;
    cout << distance(input.begin(), upper_bound(input.begin(), input.end(), 6)) << endl;

    auto p = search_range(input, 8);
    cout << p.first << " " << p.second << endl;

    auto q = recursive_search_range(input, 8);
    cout << q.first << " " << q.second << endl;
    return 0;
}
