#include <iostream>

using namespace std;

const int MAXN = 100005;

int MaxSum(int a[], int n, int &start, int &end)
{
    int sum = -1001;
    int b = 0;

    int s = 0;
    for(int i = 0; i < n; i++) {
        b += a[i];
        if(b > sum) {sum = b; start = s; end = i;}
        if(b < 0) {b = 0; s = i+1;}
    }

    return sum;
}

int main(void)
{
    int nCase;
    int a[MAXN];
    int N;

    scanf("%d", &nCase);
    for(int c = 1; c <= nCase; c++) {
        scanf("%d", &N);

        for(int i = 0; i < N; i++) {
            scanf("%d", &a[i]);
        }

        printf("Case %d:\n", c);
        int start, end;
        int answer = MaxSum(a, N, start, end);
        printf("%d %d %d\n", answer, start+1, end+1);

        if(c != nCase)
            printf("\n");
    }

    return 0;
}

