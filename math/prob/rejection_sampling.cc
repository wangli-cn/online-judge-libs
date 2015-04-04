#include <iostream>
#include <random>

int rand7()
{
    static std::random_device rd;
    static std::mt19937 mt(rd());
    static std::uniform_int_distribution<> dist(1, 7);
    return dist(mt);
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
        std::cout << rand10() << " "
    }
    std::cout << std::endl;

    for (int i = 0; i < 20; i++) {
        std::cout << optimized_rand10() << " "
    }
    std::cout << std::endl;

    return 0;
}
