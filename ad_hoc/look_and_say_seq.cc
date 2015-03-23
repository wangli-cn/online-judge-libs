#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1000000;

void look_and_say_seq(char number[MAXN])
{
    char t[MAXN];
    char *s, *res, *p;
    for (int i = 0; i < 4; i++) {
        printf("%s\n", number);

        res = t;
        p = number;
        while (*p) {
            s = p;

            while (*p == *s) p++;

            *res++ = '0' + p - s;
            *res++ = *s;
            *res = 0;
        }

        strcpy(number, t);
    }
}

int main()
{
    char number[MAXN] = "1";

    look_and_say_seq(number);
    return 0;
}
