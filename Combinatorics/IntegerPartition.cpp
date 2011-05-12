#include <iostream>
#include <vector>

using namespace std;

int n;

void display(vector<int> &part, vector<int> &times, int last)
{
    for (int i = 1; i <= last; ++i) {
        for (int j = 1; j <= times[i]; ++j)
            printf("%3d", part[i]);
    }
    printf("\n");
}

void DFS(vector<int> &part, vector<int> &times, int last, int &cnt)
{
    if (part[last] == 1 && times[last] == n) {
        return;
    }

    int rest, next, remainder;
    if (part[last] == 1) {
        rest = times[last--]+1;
        next = part[last]-1;
        if (times[last] != 1)
            times[last++]--;

        part[last] = next;
        times[last] = rest / next + 1;
        remainder = rest % next;

        if (remainder != 0) {
            part[++last] = remainder;
            times[last] = 1;
        }
    } else {
        rest = part[last];
        next = part[last]-1;
        if (times[last] != 1)
            times[last++]--;

        part[last] = next;
        times[last] = rest / next;
        remainder = rest % next;
        if (remainder != 0) {
            part[++last] = remainder;
            times[last] = 1;
        }
    }

    cnt += 1;
    display(part, times, last);
    DFS(part, times, last, cnt);
}

int main(void)
{
    cin >> n;
    vector<int> part(n+1), times(n+1);

    part[1] = n;
    times[1] = 1;
    int cnt = 1;
    DFS(part, times, 1, cnt);
    cout << cnt << endl;
    return 0;
}
