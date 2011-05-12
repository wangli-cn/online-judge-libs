#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 10005;

int tree[MAXN];

int leastCommonAncestor(int p, int q)
{
    vector<int> v1, v2;
    int i;

    v1.push_back(p); v2.push_back(q);

    while (tree[p] > 0) {
        p = tree[p];
        v1.push_back(p);
    }

    while (tree[q] > 0) {
        q = tree[q];
        v2.push_back(q);
    }

    reverse(v1.begin(), v1.end());
    reverse(v2.begin(), v2.end());

    for (i = 0; v1[i] == v2[i]; i++);

    return v1[i-1];
}


int main(void)
{
    int nCase, N;
    int a, b;
    int parent, child;

    cin >> nCase;
    while (nCase--) {
        cin >> N;
        memset(tree+1, 0, N * sizeof(int));

        for (int i = 1; i < N; i++) {
            cin >> parent >> child;
            tree[child] = parent;
        }

        cin >> a >> b;

        cout << leastCommonAncestor(a, b) << endl;
    }

    return 0;
}
