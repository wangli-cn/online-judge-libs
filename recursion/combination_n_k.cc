#include <iostream>

using namespace std;

void gen_combination(int n, int k, int pos, int idx[], int sz)
{
    if (pos > n) return;

    if (pos == n) {
        if (sz == k) {
            cout << "[";
            for (int i = 0; i < sz; i++) cout << idx[i] << ((i == sz-1) ? "" : " ");
            cout << "]" << endl;
        }
        return;
    }

    idx[sz++] = pos;
    gen_combination(n, k, pos+1, idx, sz);
    sz--;

    gen_combination(n, k, pos+1, idx, sz);
}

void solve(int n, int k)
{
    int idx[10000];

    gen_combination(n, k, 0, idx, 0);
}

int main()
{
    solve(4, 2);
    return 0;
}
