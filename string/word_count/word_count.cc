#include <iostream>
#include <string>

int count_words(const std::string &s)
{
    bool in_word = false;
    int word_cnt = 0;

    for (int i = 0; i < s.length(); i++) {
        if (!in_word && isalpha(s[i])) {
            in_word = true;
            word_cnt += 1;
        } else if (in_word && s[i] == ' ') {
            in_word = false;
        }
    }

    return word_cnt;
}

int main()
{
    const std::string s("ab d    fe  grq ");
    std::cout << count_words(s) << std::endl;
    return 0;
}
