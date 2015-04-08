#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

std::vector<int> fisher_yates(std::vector<int> &a)
{
    std::vector<int> res(a.size());

    res[0] = a[0];
    for (int i = 1; i < a.size(); i++) {
        int j = rand() % (i+1);

        if (j != i) res[i] = res[j];
        res[j] = a[i];
    }

    return res;
}

int main()
{
    std::vector<int> input {1,2,3,4,5,6,7,8,9,10};
    std::vector<int> res = fisher_yates(input);

    std::copy(res.begin(), res.end(), std::ostream_iterator<int>(std::cout, "\n"));
    return 0;
}
