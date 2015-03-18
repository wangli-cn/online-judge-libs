//============================================================================
// Remove Duplicates from Sorted Array II
// Follow up for "Remove Duplicates":
// What if duplicates are allowed at most twice?
//
// For example,
// Given sorted array A = [1,1,1,2,2,3],
//
// Your function should return length = 5, and A is now [1,1,2,2,3].
//============================================================================

int remove_duplicate(int a[], int n)
{
    if (n < 2) return n;
    int i = 1, j = 0;
    bool first = true;
    while (i < n) {
        if (a[i] != a[j]) {
            a[++j] = a[i++];
            first = true;
        } else {
            if (first) {
                a[++j] = a[i++];
                first = false;
            } else {
                i++;
            }
        }
    }

    return j+1;
}

int main()
{
    return 0;
}
