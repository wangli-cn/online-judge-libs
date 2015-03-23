#include <iostream>

using namespace std;

//============================================================================
// Implement strStr().
//
// Returns a pointer to the first occurrence of needle in haystack,
// or null if needle is not part of haystack.
//============================================================================
char *strstr(char *haysack, char *needle)
{
    if (haysack == nullptr || needle == nullptr) return haysack;

    int n = strlen(haysack);
    int m = strlen(needle);

    int i = 0;
    while (i < n-m+1) {
        int j = 0;
        while (j < m && haysack[i+j] == needle[j]) {
            j++;
        }

        if (j == m) return haysack + i;

        i++;
    }

    return nullptr;
}

int my_strlen(char *s)
{
    char *p = s;
    while (*p != '\0') { p++; }

    return (p-s);
}

int my_strcmp(const char *s1, const char *s2)
{
    while (*s1 == *s2) {
        if (*s1 == '\0') return 0;
        s1++; s2++;
    }

    return (*s1 - *s2);
}

char *my_strcpy(char *dst, const char *src)
{
    char *ptr = dst;
    while (*dst++ = *src++);
    return ptr;
}

int main()
{
    const char a[] = "default";
    const char b[] = "au";

    char *r = strstr(a, b);

    cout << r << endl;
    return 0;
}
