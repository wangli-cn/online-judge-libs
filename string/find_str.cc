bool brute_force(char *x, int m, int char *y, int n)
{
    int i, j;
    for (j = 0; j <= (n-m); ++j) {
        for (i = 0; i < m && x[i] == y[j+i]; ++i);
        if (i >= m) return true;
    }
    return false;
}
