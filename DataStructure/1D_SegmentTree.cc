struct vertex {
    vertex * l, * r;
    int sum;

    vertex (int val)
        : l(NULL), r(NULL), sum(val)
    { }

    vertex (vertex * l, vertex * r)
        : l(l), r(r), sum(0)
    {
        if (l)  sum += l->sum;
        if (r)  sum += r->sum;
    }
};

vertex * build (int a[], int tl, int tr) {
    if (tl == tr)
        return new vertex (a[tl]);
    int tm = (tl + tr) / 2;
    return new vertex (
            build (a, tl, tm),
            build (a, tm+1, tr)
            );
}

int get_sum (vertex * t, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && tr == r)
        return t->sum;
    int tm = (tl + tr) / 2;
    return get_sum (t->l, tl, tm, l, min(r,tm))
        + get_sum (t->r, tm+1, tr, max(l,tm+1), r);
}

vertex * update (vertex * t, int tl, int tr, int pos, int new_val) {
    if (tl == tr)
        return new vertex (new_val);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return new vertex (
                update (t->l, tl, tm, pos, new_val),
                t->r
                );
    else
        return new vertex (
                t->l,
                update (t->r, tm+1, tr, pos, new_val)
                );
}

