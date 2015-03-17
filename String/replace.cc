
bool is_match(char *str, const char *pattern)
{
    while (*pattern) {
        if (*str++ != *pattern++) return false;
    }
    return true;
}

void replace(char str[], const char *pattern)
{
    if (str == NULL || pattern == NULL) return;

    char *p1 = str, *p2 = str;
    int plen = strlen(pattern);

    while (*p2 != '\0') {
        bool matched = false;

        while (is_match(p2, pattern)) {
            matched = true;
            p2 += plen;
        }

        if (matched) *p1++ = 'X';

        if (*p2 != '\0') *p1++ = *p2++;
    }

    *p1 = '\0';
}
