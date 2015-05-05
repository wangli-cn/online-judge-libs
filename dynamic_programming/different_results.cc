// given a list of integers, insert +-*/() to calculate how many different evaluted results

#include <iostream>
#include <vector>
#include <unordered_map>
#include "utils/common.h"


VI f(VI &a, int i, int j)
{
    if (i == j) {
        VI res;
        res.push_back(a[i]);
        return std::move(res);
    }

    std::unordered_map<int, bool> M;

    for (int k = i; k < j; k++) {
        auto r1 = f(a, i, k);
        auto r2 = f(a, k+1, j);

        for (auto t1: r1) {
            for (auto t2: r2) {
                int sum = t1+t2;
                if (M.count(sum) == 0) {
                    M[sum] = true;
                }

                int diff = t1-t2;
                if (M.count(diff) == 0) {
                    M[diff] = true;
                }


                int mul = t1*t2;
                if (M.count(mul) == 0) {
                    M[mul] = true;
                }

                if (t2 != 0) {
                    int div = t1/t2;
                    if (M.count(div) == 0) {
                        M[div] = true;
                    }
                }
            }
        }
    }


    VI res;
    for (auto p: M) {
        res.push_back(p.first);
    }

    return std::move(res);
}


int solve(VI &a)
{
    int n = a.size();
    auto res = f(a, 0, n-1);

    return res.size();
}


int main()
{
    VI a { 1, 2, 3, 4, 5, 6, 10 };

    std::cout << solve(a) << std::endl;

    return 0;
}
