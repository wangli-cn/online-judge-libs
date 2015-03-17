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
    return 0;
}
