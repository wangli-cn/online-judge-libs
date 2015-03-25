#include <iostream>

using namespace std;

void replace_space(char *s)
{
    char *p = s;
    int cnt = 0, l = 0;
    while (*p) {
        if (*p == ' ') cnt += 1;
        l += 1;
        p += 1;
    }

    int l_prime = l + cnt + cnt;
    s[l_prime] = '\0';

    for (int i = l_prime-1; i >= 0; ) {
        if (s[i - cnt -cnt] == ' ') {
            s[i-2] = '%'; s[i-1] = '2'; s[i] = '0';
            i -= 3;
            cnt -= 1;
        } else {
            s[i] = s[i-cnt-cnt];
            i -= 1;
        }
    }
}

int main()
{
    char s[] = "abc  def fe f";
    replace_space(s);
    cout << s << endl;
    return 0;
}
