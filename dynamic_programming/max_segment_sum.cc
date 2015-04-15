#include <iostream>

using namespace std;

const int MAXN = 50005;

int curr_best[MAXN];
int prev_best[MAXN];

int a[MAXN];
int m, n;

int Max_M_segment_Sum(int a[], int n, int m)
{
    int sum;

    a--;
    curr_best[0] = 0;
    for(int i = 0; i <= n; i++) 
        prev_best[i] = 0;

    for(int i = 1; i <= m; i++) {
        sum = INT_MIN;
        for(int j = i; j <= n; j++) {
            if(curr_best[j-1] < prev_best[j-1])
                curr_best[j] = prev_best[j - 1] + a[j];
            else
                curr_best[j] = curr_best[j - 1] + a[j];

            prev_best[j-1] = sum;
            if(sum < curr_best[j])
                sum = curr_best[j];
        }
        prev_best[n] = sum;
    }

    return sum;
}

int main(void)
{
    int nCase;

    scanf("%d", &nCase);
    while(nCase--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        printf("%d\n", Max_M_segment_Sum(a, n, 2));
    }

    return 0;
}

