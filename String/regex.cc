
bool is_match(char *s, char *p)
{
    if (*p == '\0') return *s == '\0';

    if (*(p+1) != '*') {
        return ((*p == *s) || (*p == '.' && *s != '\0')) && is_match(s+1, p+1);
    }

    while ((*p == *s) || (*p == '.' && *s != '\0')) {
        if (is_match(s, p+2)) return true;
        s++;
    }

    return is_match(s, p+2);
}
