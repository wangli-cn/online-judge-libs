#include <iostream>

using namespace std;

bool find_sub_range(int A[], int len, int sum, int &start, int &end)
{
    int cur_start = 0, cur_end, cur_num = 0;
    int i = 0;

    while (A[i] > sum) i++;
    if (i >= len) return false;

    for (; i < len; i++) {
        if (cur_num + A[i] == sum) {
            start = cur_start;
            end = i;
            return true;
        }

        if (cur_num + A[i] < sum) {
            cur_num += A[i];
            continue;
        }

        cur_num += A[i];
        while (cur_num > sum) {
            cur_num -= A[cur_start];
            cur_start += 1;
        }

        if (cur_num == sum) {
            start = cur_start;
            end = i;
            return true;
        }
    }

    return false;
}

int main()
{
    return 0;
}
