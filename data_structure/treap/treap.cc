#include <iostream>
#include <random>

int rand()
{
    static std::random_device rd;
    static std::mt19937 mt(rd());
    static std::uniform_int_distribution<> dist(1, 7);
    return dist(mt);
}

using Key = int;
using Value = int;
using Result = int;

class Treap
{
public:
    Key key;
    Value value;
    int p;
    bool cached;
    Result cache;
    Treap *ch[2];

    explicit Treap(const Key &key, const Value &value) :key(key), value(value), p(rand()), cached(0)
    {
        ch[0] = ch[1] = nullptr;
    }
};

Treap *rotate(Treap *t, int b)
{
    Treap *s = t->ch[1-b]; t->ch[1-b] = s->ch[b]; s->ch[b] = t;
    s->cached = t->cached = false;
    return s;
}

Treap *find(Treap *t, const Key &key)
{
    return !t || key == t->key ? t : find(t->ch[key < t->key], key);
}

Treap *insert(Treap *t, const Key &key, const Value &value)
{
    if (!t) return new Treap(key, value);
    else if (key == t->key) return t;

    int b = !(key < t->key);
    t->ch[b] = insert(t->ch[b], key, value);
    if (t->p > t->ch[b]->p) t = rotate(t, 1-b);
    t->cached = false;
    return t;
}

Treap *erase(Treap *t, const Key &key)
{
    if (!t) return nullptr;
    if (key == t->key) {
        if (!t->ch[0] && !t->ch[1]) return NULL;
        else if (!t->ch[0]) t = rotate(t, 0);
        else if (!t->ch[1]) t = rotate(t, 1);
        else t = rotate(t, t->ch[0]->p < t->ch[1]->p);
        t = erase(t, key);
    } else {
        int b = !(key < t->key);
        t->ch[b] = erase(t->ch[b], key);
    }

    t->cached = false;
    return t;
}

Result eval(Treap *t)
{
    if (!t) return 0;
    if (!t->cached)
        t->cache = eval(t->ch[0]) + eval(t->ch[1]) + 1; //CHANGE IT FLEXIBLE
    t->cached = true;
    return t->cache;
}

Treap *nth(Treap *t, int n) //NTH ELEMENT
{
    int l = eval(t->ch[0]);
    if (n < l) return nth(t->ch[0], n);
    if (n > l) return nth(t->ch[1], n-l-1);
    return t;
}

int main(void)
{
    return 0;
}
