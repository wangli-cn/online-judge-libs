//============================================================================
// Pascal's Triangle II
// Given an index k, return the kth row of the Pascal's triangle.
//
// For example, given k = 3,
// Return [1,3,3,1].
//
// Note:
// Could you optimize your algorithm to use only O(k) extra space?
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

vector<int> get(int n)
{
    vector<int> row;
    row.reserve(n+1);
    row.push_back(1);

    if (n < 1) return row;

    row.push_back(1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            row[i] += row[i+1];
        }

        row.insert(row.begin(), 1);
    }

    return row;
}

int main()
{
    get(3);

    return 0;
}
