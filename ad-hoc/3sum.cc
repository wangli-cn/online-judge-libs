//============================================================================
// Given an array S of n integers, are there elements a, b, c in S such that
// a + b + c = 0?
// Find all unique triplets in the array which gives the sum of zero.
//
// Note:
// Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
// The solution set must not contain duplicate triplets.
// For example, given array S = {-1 0 1 2 -1 -4},
//
// A solution set is:
// (-1, 0, 1)
// (-1, -1, 2)
//============================================================================


#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

typedef unordered_map<int, pair<int, int> > HashMap;

set< vector<int> > find_triplets_using_hashmap(vector<int> &a)
{
    int n = a.size();
    HashMap hmap;

    for (int i = 0; i <= n-2; i++) {
        for (int j = i+1; j <= n-1; j++) {
            int two_sum = -(a[i] + a[j]);
            hmap[two_sum] = make_pair(i, j);
        }
    }

    set<vector<int> > results;
    HashMap::iterator it;
    for (int i = 0; i < n; i++) {
        if ((it = hmap.find(a[i])) != hmap.end()) {
            if ((*it).second.first != i && (*it).second.second != i) {
                vector<int> sol;
                sol.push_back(a[i]);
                sol.push_back(a[(*it).second.first]);
                sol.push_back(a[(*it).second.second]);
                sort(sol.begin(), sol.end());

                results.insert(sol);
            }
        }
    }

    return results;
}

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

int main(void)
{
    vector<int> input {-1, 0, 1, 2, -1, -4};
    set<vector<int> > results1 = find_triplets_using_hashmap(input);

    for (auto it = results1.begin(); it != results1.end(); ++it) {
        cout << "(" << (*it)[0] << "," << (*it)[1] << "," << (*it)[2] << ")" << endl;
    }

    return 0;
}
