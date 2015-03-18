#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

vector<int> reservoir_sampling(vector<int> &a, int K)
{
    vector<int> res(K);

    for (int i = 0; i < K; i++) {
        res[i] = a[i];
    }

    for (int i = K; i < a.size(); i++) {
        int j = rand() % (i+1);
        if (j < K) {
            res[j] = a[i];
        }
    }

    return res;
}

int main()
{
    vector<int> input {1,2,3,4,5,6,7,8,9,10};
    vector<int> res = reservoir_sampling(input, 3);
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, "\n"));
    return 0;
}
