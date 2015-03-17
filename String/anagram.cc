#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef vector< vector<string> > VVS;

#define REP(i, n) for(int i = 0; i < (int)n; ++i) 
#define FOR(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)

struct Word
{
    Word(const string &t) :s(t) { 
        sort(s.begin(), s.end()); 
    }

    string s;
};

bool operator<(const Word &a, const Word &b)
{
    return a.s < b.s; 
}

vector< vector<string> > anagram(const vector<string> &a)
{
    vector<Word> words;

    int n = a.size();
    REP(i, n) {
        words.push_back(Word(a[i]));
    }

    sort(words.begin(), words.end());

    n = words.size();
    vector< vector<string> > res;
    vector<string> tmp; 

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

    return res;
}

int main(void) 
{
    vector<string> words;

    words.push_back(string("star"));
    words.push_back(string("arts"));
    words.push_back(string("car"));
    words.push_back(string("arc"));
    words.push_back(string("go"));

    VVS t = anagram(words);
    FOR(i, t) { 
        cout << "[";
        FOR(j, *i) {
            cout << *j << " ";
        } 
        cout << "]";
    }
    cout << endl;

    return 0;
}
