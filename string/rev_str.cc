#include <iostream>

void reverse_str(char *buf, int s, int e)
{
    char t;

    if (s >= e) return;

    t = *(buf + s);
    *(buf + s) = *(buf + e);
    *(buf + e) = t;

    reverse_str(buf, ++s, --e);
}

int main()
{
    char s[] = "abcdef";
    std::cout << s << std::endl;
    reverse_str(s, 0, 5);
    std::cout << s << std::endl;
    return 0;
}
