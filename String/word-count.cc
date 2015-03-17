int count_words(const char *s)
{
    bool in_word = false;
    int word_cnt = 0;

    while (*s) {
        if (!in_word && isalpha(*s)) {
            in_word = true;
            word_cnt += 1;
        } else if (in_word && *s == ' ') {
            in_word = false;
        }
        s++;
    }

    return word_cnt;
}
