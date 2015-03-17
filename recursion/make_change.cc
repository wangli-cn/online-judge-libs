#include <iostream>

using namespace std;

int get_next(int denom)
{
    int next_denom = -1;

    switch (denom) {
        case 25:
            next_denom = 10;
            break;
        case 10:
            next_denom = 5;
            break;
        case 5:
            next_denom = 1;
            break;
    }

    return next_denom;
}

int make_change(int n, int denom)
{
    int next_denom = get_next(denom);

    if (next_denom == -1) return 1;

    int way = 0;
    for (int i = 0; i * denom <= n; ++i) {
        way += make_change(n - i*denom, next_denom);
    }

    return way;
}

int main(void)
{
    cout << make_change(1, 25) << endl;
    cout << make_change(5, 25) << endl;
    cout << make_change(25, 25) << endl;
    return 0;
}
