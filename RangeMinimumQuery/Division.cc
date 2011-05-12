/**
 *
 * Complexity: Preprocessing with O(N), Query with O(sqrt(N)) 
 * Test Field: 
 */
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void preProcess(vector<int> &a, vector<int> &b, int L)
{
    int n = a.size();

    for (int i = 0, k = 0; i < n; k++) {
        int upper = min(i + L, n);

        for (int j = i+1; j < upper; j++) {
            if (a[j] > a[i]) i = j;
        }

        b[k] = i;
        i = upper;
    }
}

int RMQ(vector<int> &a, vector<int> &b, int L, int l, int r)
{
    int u = l / L, v = r / L;
    int k = l;

    if (u < v) {
        k = l; 
        int up = (u+1) * L;
        for (int i = u+1; i < v; i++) if (a[b[i]] > a[k]) k = b[i];
        for (int i = l; i < up; i++) if (a[i] > a[k]) k = i;
        for (int i = v * L; i <= r; i++) if (a[i] > a[k]) k = i;
    } else {
        for (int i = l; i <= r; i++) {
            if (a[i] > a[k]) k = i;
        }
    }

    return k;
}

int main(void)
{
    int a[8] = {6, 1, 2, 3, 1, 5, 1000, 1};

    vector<int> arr(a, a+8);
    int L = (int)sqrt(8);
    vector<int> b(L);

    preProcess(arr, b, L);
    cout << RMQ(arr, b, L, 1, 7) << endl;
    return 0;
}
