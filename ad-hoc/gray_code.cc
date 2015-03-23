//============================================================================
// The gray code is a binary numeral system where two successive values differ
// in only one bit.
//
// Given a non-negative integer n representing the total number of bits in the
// code, print the sequence of gray code. A gray code sequence must begin with
// 0.
//
// For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
//
// 00 - 0
// 01 - 1
// 11 - 3
// 10 - 2
//============================================================================

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

vector<int> gray_code(int n)
{
    vector<int> result;

    int num = 1 << n;
    for (int i = 0; i < num; i++) {
        result.push_back((i >> 1) ^ i);
    }

    return result;
}

unsigned int grayToBinary(unsigned int num)
{
    unsigned int mask;
    for (mask = num >> 1; mask != 0; mask = mask >> 1) {
        num = num ^ mask;
    }
    return num;
}

int main(void)
{
    vector<int> res = gray_code(2);

    copy(res.begin(), res.end(), ostream_iterator<int>(cout, "\n"));
}
