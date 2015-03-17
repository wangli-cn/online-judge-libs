#include <iostream>

using namespace std;

int my_atoi(const char *s)
{
    int value = 0;

    if (s != NULL) {
        while (*s && (*s) <= '9' && (*s) >= '0') {
            value = value * 10 + *s - '0';
            s++;
        }
    }

    return value;
}

int main()
{
    return 0;
}
