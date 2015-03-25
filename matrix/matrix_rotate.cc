#include <iostream>
#include <vector>

using namespace std;

#define REP(i,n) for (int i = 0; i < (int)n; ++i)
const int N = 5;

void rotate_array(int a[N][N])
{
    int L = N/2;
    REP(l, L) {
        int first = l;
        int last = N-1-l;
        for (int i = first; i < last; i++) {
            int offset = i - first;

            int t = a[i][first];
            a[i][first] = a[first][last-offset];
            a[first][last-offset] = a[last-offset][last];
            a[last-offset][last] = a[last][i];
            a[last][i] = t;
        }
    }
}

int main(void)
{
    int a[5][5] = { {1, 2, 3, 4, 5},
                    {6, 7, 8, 9, 10},
                    {11, 12, 13, 14, 15},
                    {16, 17, 18, 19, 20},
                    {21, 22, 23, 24, 25}};

    REP(i, N) {
        REP(j, N) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    rotate_array(a);

    REP(i, N) {
        REP(j, N) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

