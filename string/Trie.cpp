#include <iostream>

using namespace std;

struct Trie
{
    int value;
    Trie *next[0x100];
    Trie() { fill(next, next+0x100, (Trie *)0); }
};

Trie *find(char *t, Trie *r)
{
    for (int i = 0; t[i]; ++i) {
        char c = t[i];
        if (!r->next[c]) r->next[c] = new Trie;
        r = r->next[c];
    }
    return r;
}

int main(void)
{
    Trie root;
    char s[32] = "NPHardisveryHard";
    Trie *t = find(s, &root);
    t->value = 10;

    Trie *v = find(s, &root);
    cout << v->value << endl;
    return 0;
}
