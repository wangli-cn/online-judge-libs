
void print_sum(int candidates[], int idx[], int n)
{
    for (int i = 1; i <= n; i++) {
        cout << candidates[idx[i]] << ((i == n) ? "" : "+");
    }
    cout << endl;
}

void solve(int target, int sum, int candidates[], int sz, int idx[], int n)
{
    if (sum > target) return;
    if (sum == target) print_sum(candidates, idx, n);

    for (int i = idx[n]; i < sz; i++) {
        idx[n+1] = i;
        solve(target, sum + candidates[i], candidates, sz, idx, n+1);
    }
}

void solve(int target, int candidates[], int sz)
{
    int idx[10000];
    idx[0] = 0;
    solve(target, 0, candidates, sz, idx, 0);
}
