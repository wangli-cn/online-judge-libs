#include <iostream>
#include <cstring>

using namespace std;

int *buildFail(char *p)
{
    int m = strlen(p);
    int *fail = new int[m+1];
    int j = fail[0] = -1;
    for (int i = 1; i <= m; ++i) {
        while (j >= 0 && p[j] != p[i-1]) j = fail[j];
        fail[i] = ++j;
    }
    return fail;
}

int match(char *t, char *p, int *fail)
{
    int n = strlen(t), m = strlen(p);
    int cnt = 0;
    for (int i = 0, k = 0; i < n; ++i) {
        while (k >= 0 && p[k] != t[i]) k = fail[k];
        if (++k >= m) {
            ++cnt;
            k = fail[k];
        }
    }
    return cnt;
}

int main(void)
{
    char p[5] = "fail";
    char t[256] = "dsareafaildsarefail";
    int *fail = buildFail(p);
    int cnt = match(t, p, fail);
    cout << cnt << endl;
    return 0;
}
