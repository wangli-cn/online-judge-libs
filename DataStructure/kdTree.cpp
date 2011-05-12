#include <iostream>
#include <complex>

using namespace std;

typedef complex<double> Point;

struct kdTree
{
    struct Node {
        Point p;
        Node *l, *r;
        Node(const Point &p)
            :p(p), l(NULL), r(NULL) {}
    } *root;
    kdTree() :root(NULL) {}

#define compare(d, p, q) (d ? real(p) < real(q) : imag(p) < imag(q))
    void insert(const Point &p) {
        root = insert(root, 0, p);
    }

    Node *insert(Node *t, int d, const Point &p) {
        if (t == NULL) return new Node(p);
        if (compare(d, p, t->p)) t->l = insert(t->l, !d, p);
        else t->r = insert(t->r, !d, p);
        return t;
    }

    template <class OUT>
    void search(const Point &ld, const Point &ru, OUT out) {
        search(root, 0, ld, ru, out);
    }
    
    template <class OUT>
    void search(Node *t, int d, const Point &ld, const Point &ru, OUT out) {
        if (t == NULL) return;

        const Point &p = t->p;
        if (real(ld) <= real(p) && real(p) <= real(ru) &&
            imag(ld) <= imag(p) && imag(p) <= imag(ru)) *out++ = p;

        if (!compare(d, p, ld)) search(t->l, !d, ld, ru, out);
        if (!compare(d, ru, p)) search(t->r, !d, ld, ru, out);
    }
};

int main(void)
{
    return 0;
}
