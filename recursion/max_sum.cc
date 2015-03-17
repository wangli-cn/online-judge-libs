#include <iostream>

using namespace std;

int max_sum(int a[], int n, int &start, int &end)
{
    int sum = -99999999;
    int b = 0;
    int s = 0;
    for (int i = 0; i < n; i++) {
        b += a[i];

        if (b > sum) {
            sum = b;
            start = s;
            end = i;
        }

        if (b < 0) {
            b = 0;
            s = i+1;
        }
    }

    return sum;
}

int main()
{
    return 0;
}
