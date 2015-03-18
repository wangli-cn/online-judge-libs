#include <iostream>
#include <cstdlib>

using namespace std;

int rand7()
{
    return 1+(rand() % 7);
}

int rand10()
{
    int row, col, idx;

    do {
        row = rand7();
        col = rand7();
        idx = col + (row-1)*7;
    } while (idx > 40);

    return 1 + (idx-1) % 10;
}

int optimized_rand10()
{
    int a, b, idx;

    while (1) {
        a = rand7();
        b = rand7();
        idx = b+(a-1)*7;

        if (idx <= 40) return 1+(idx-1)%10;

        a = idx - 40;
        b = rand7();
        idx = b+(a-1)*7;

        if (idx <= 60) return 1+(idx-1)%10;

        a = idx - 60;
        b = rand7();
        idx = b+(a-1)*7;

        if (idx <= 20) return 1+(idx-1)%10;
    }
}

int main()
{
    for (int i = 0; i < 20; i++) {
        cout << rand10() << endl;
    }

    cout << endl;

    for (int i = 0; i < 20; i++) {
        cout << optimized_rand10() << endl;
    }

    return 0;
}
