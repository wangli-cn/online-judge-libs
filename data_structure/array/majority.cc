//A majority element in an array A[] of size n is an element that appears more than n/2 times (and hence there is at most one such element).

#include <iostream>
#include <vector>

using namespace std;

int find_candidate(vector<int> &a)
{
    auto n = a.size();
    int maj_idx = 0, cnt = 0;

    for (decltype(n) i = 1; i < n; i++) {
        if (a[maj_idx] == a[i]) cnt += 1;
        else cnt -= 1;

        if (cnt == 0) maj_idx = i, cnt = 1;
    }

    return a[maj_idx];
}

bool is_majority(vector<int> &a, int x)
{
    auto n = a.size();
    int cnt = 0;

    for (decltype(n) i = 0; i < n; i++) {
        if (a[i] == x) cnt += 1;
    }

    if (cnt > n/2) return true;
    else return false;
}

int main()
{
    vector<int> input {1,1,1,1,3,2};
    int candidate = find_candidate(input);
    std::cout << is_majority(input, candidate) << std::endl;
    return 0;
}
