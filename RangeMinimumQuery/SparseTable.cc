/**
 *
 * Complexity: Preprocessing with O(N log N), Query with O(1)
 * Test Field: 
 */
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void buildSparseTable(vector<int> &a, vector< vector<int> > &M)
{
    int n = a.size();
    int i, j;
    
    for (i = 0; i < n; ++i)
        M[i][0] = i;

    for (j = 1; (1 << j) <= n; ++j) {
        for (i = 0; i+(1<<j)-1 < n; ++i) {
            if (a[M[i][j-1]] > a[M[i+(1<<(j-1))][j-1]])
                M[i][j] = M[i][j-1];
            else 
                M[i][j] = M[i+(1<<(j-1))][j-1];
        }
    }
}

int RMQ(vector<int> &a, vector< vector<int> > &M, int l, int r)
{
    int range = abs(r-l)+1;

    int k;
    for (k = 0; (1 << k) <= range; ++k);
    k--;

    if (a[M[l][k]] > a[M[r-(1<<k)+1][k]])
        return a[M[l][k]];
    else 
        return a[M[r-(1<<k)+1][k]];
}

int main(void)
{
    int a[8] = {6, 1, 2, 3, 1, 5, 1000, 1};

    vector<int> arr(a, a+8);
    vector< vector<int> > M(8, vector<int>(4));

    buildSparseTable(arr, M);
    cout << RMQ(arr, M, 1, 7) << endl;

    return 0;
}
