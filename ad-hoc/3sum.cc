#include <vector>
#include <set>

using namespace std;

set< vector<int> > find_triplets(vector<int> &a)
{
    sort(a.begin(), a.end());
    set< vector<int> > triplets;
    vector<int> triplet(3);

    int n = a.size();
    for (int i = 0; i < n; i++) {
        int j = i+1, k = n-1;
        while (j < k) {
            int sum_two = a[i] + a[j];
            if (sum_two + a[k] < 0) {
                j++;
            } else if (sum_two + a[k] > 0) {
                k--;
            } else {
                triplet[0] = a[i]; triplet[1] = a[j]; triplet[2] = a[k];
                triplets.insert(triplet);
                j++; k--;
            }
        }
    }

    return triplets;
}
