#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

typedef int Position;
typedef int Content;

struct Interval
{
    Position low, high;
    Interval(Position low, Position high)
      :low(low), high(high) {}
};

struct IntervalTree
{
    vector<Position> pos; 

    struct Node {
        vector<Content> values;
        Position B, M, E;
        Node *left, *right;
    } *root;
    
    template <class IN>
    IntervalTree(IN begin, IN end) : pos(begin, end) {
        root = build_tree(0, pos.size()-1);
    }
    ~IntervalTree() { release(root); }

    Node *build_tree(int i, int j) {
        int m = (i+j)/2;
        Node *t = new Node;
        t->B = pos[i]; t->E = pos[j]; t->M = pos[m];
        t->left = (i+1 < j ? build_tree(i, m) : NULL);
        t->right = (i+1 < j ? build_tree(m, j) : NULL);
    }

    void insert(const Interval &I, Content c) {
        insert(root, I, c); 
    }
    
    void insert(Node *v, const Interval &I, Content c) {
        if (!v) return;
        
        if (I.low <= v->B && v->E <= I.high) {
            v->values.push_back(c);
        } else {
            if (I.low < v->M) insert(v->left, I, c);
            if (I.high > v->M) insert(v->right, I, c);
        }
    }

    template <class OUT>
    void query(Position p, OUT out) {
        query(root, p, out);
    }

    template <class OUT>
    void query(Node *t, Position p, OUT out) {
        if (!t || p < t->B || p >= t->E)
            return;

        copy(t->values.begin(), t->values.end(), out);

        if (p < t->M) query(t->left, p, out);
        else query(t->right, p, out);
    }

    void release(Node *t) {
        if (t->left) release(t->left);
        if (t->right) release(t->right);
        delete t;
    }
};

int main(void)
{
    int a[7] = {0, 8, 10, 11, 1000, 1006, 1009};
    vector<int> pos(a, a+7);
    IntervalTree T(pos.begin(), pos.end());

    T.insert(Interval(8, 10), 1);
    T.insert(Interval(8, 1000), 2);
    
    vector<int> output;
    T.query(9, back_inserter(output));

    sort(output.begin(), output.end());
    copy(output.begin(), output.end(), ostream_iterator<int>(cout, " "));

    return 0;
}

