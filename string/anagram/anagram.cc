//============================================================================
// Given an array of strings, return all groups of strings that are anagrams.
//
// Note: All inputs will be in lower-case.
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "utils/common.h"

using VS = std::vector<std::string>;
using VVS = std::vector<std::vector<std::string>>;

class Word
{
public:
    Word() = delete;

    explicit Word(const std::string &t) :s(t) {
        std::sort(s.begin(), s.end());
    }

    std::string s;
};

bool operator<(const Word &a, const Word &b)
{
    return a.s < b.s;
}

std::vector<std::vector<std::string>> anagram(const std::vector<std::string> &a)
{
    std::vector<Word> words;

    int n = a.size();
    REP(i, n) {
        words.push_back(Word(a[i]));
    }

    sort(words.begin(), words.end());

    n = words.size();
    VVS res;
    VS tmp;

    tmp.push_back(words[0].s);
    for (int i = 1; i < n; i++) {
        if (words[i].s == words[i-1].s) {
            tmp.push_back(words[i].s);
        } else {
            res.push_back(tmp);
            tmp.clear();
            tmp.push_back(words[i].s);
        }
    }

    if (tmp.size() != 0) {
        res.push_back(tmp);
    }

    return std::move(res);
}

int main(void)
{
    VS words { std::string("star"),
               std::string("arts"),
               std::string("car"),
               std::string("arc"),
               std::string("go") };

    auto&& t = anagram(words);

    FOR(i, t) {
        std::cout << "[";
        FOR(j, *i) {
            std::cout << *j << " ";
        }
        std::cout << "] ";
    }
    std::cout << std::endl;

    return 0;
}
