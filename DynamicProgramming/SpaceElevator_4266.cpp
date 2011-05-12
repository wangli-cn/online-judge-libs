#include <iostream>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>

using namespace std;

const int MAXN = 105;

struct Station
{
    int profit;
    int loc;
} Sx[MAXN], Sy[MAXN];

struct State
{
    int lb, rb;
    bool left;
    int time;
    int value;

    State(int lb, int rb, bool left, int time, int value) :lb(lb), rb(rb), left(left), time(time), value(value) {}
};

bool operator<(const State &a, const State &b)
{
    return a.value > b.value;
}

int f[MAXN][MAXN][2];

int cmp(const void *a, const void *b)
{
    return ((Station *)a)->loc > ((Station *)b)->loc;
}

int main(void)
{
    int nCase;
    int r, q;
    int location, profit;

    scanf("%d", &nCase);
    for (int c = 1; c <= nCase; ++c) {
        memset(f, 0, sizeof(f));

        scanf("%d %d", &r, &q);
        for (int i = 1; i <= r; ++i) {
            scanf("%d %d", &location, &profit);

            Sx[i].loc = location;
            Sx[i].profit = profit;
        }
        Sx[0].loc = Sx[0].profit = 0;
        qsort(Sx+1, r, sizeof(Station), cmp);

        for (int i = 1; i <= q; ++i) {
            scanf("%d %d", &location, &profit);

            Sy[i].loc = location;
            Sy[i].profit = profit;
        }
        Sy[0].loc = Sy[0].profit = 0;
        qsort(Sy+1, q, sizeof(Station), cmp);

        priority_queue<State> Q;
        Q.push(State(0, 0, false, 0, 0));
        Q.push(State(0, 0, true, 0, 0));
        while (!Q.empty()) {
            State t = Q.top(); Q.pop();
            
            if (t.left) {
                //at left
                if (t.rb == r) {
                    continue;
                }

                int v = t.value;
                for (int i = t.rb+1; i <= r; i++) {
                    int new_value = Sx[i].profit - t.time - Sx[i].loc - Sy[t.lb].loc + v;
                    if (new_value > v) {
                        if (f[t.lb][i][0] < new_value) {
                            f[t.lb][i][0] = new_value;
                            Q.push(State(t.lb, i, false, t.time + Sx[i].loc + Sy[t.lb].loc, new_value));
                            v = new_value;
                        }
                    }
                }
            } else {
                if (t.lb == q) {
                    continue;
                }

                int v = t.value;
                for (int i = t.lb+1; i <= q; i++) {
                    int new_value = Sy[i].profit - t.time - Sy[i].loc - Sx[t.rb].loc + v;
                    if (new_value > v) {
                        if (f[i][t.rb][1] < new_value) {
                            f[i][t.rb][1] = new_value;
                            Q.push(State(i, t.rb, true, t.time + Sx[t.rb].loc + Sy[i].loc, new_value));
                            v = new_value;
                        }
                    }
                }
            }
        }
        
        int maximum = INT_MIN;
        for (int i = 0; i <= q; i++) {
            for (int j = 0; j <= r; j++) {
                for (int k = 0; k < 2; k++) {
                    if (f[i][j][k] > maximum) maximum = f[i][j][k];
                }
            }
        }

        printf("Case %d: %d\n", c, maximum);
        int t;
        scanf("%d", &t);
    }

    return 0;
}
