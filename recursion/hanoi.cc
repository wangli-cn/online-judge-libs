#include <cstdio>

void tower_of_hanoi(int n, char from, char to, char tmp)
{
    if (n > 0) {
        tower_of_hanoi(n-1, from, tmp, to);
        std::printf("Move disk %d from %c to %c\n", n, from, to);
        tower_of_hanoi(n-1, tmp, to, from);
    }
}

int main()
{
    tower_of_hanoi(3, '1', '3', '2');
    return 0;
}
