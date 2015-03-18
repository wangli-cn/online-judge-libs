#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int NEG_INF = INT_MIN;
typedef int Position;
typedef int Content;

struct Interval
{
    Position low, high;
    Interval(Position low, Position high) :low(low), high(high) {}
};

struct SegmentTree
{
    vector<Position> pos;

    struct Node
    {
        vector<Content> c;
        Position B, M, E;
        Node *left, *right;
    } *root;

    template <class IN>
    SegmentTree(IN begin, IN end) :pos(begin, end) {
        root = build_tree(0, pos.size()-1);
    }

    ~SegmentTree() { release(root); }

    Node *build_tree(int l, int r) {
        int m = l + (r-l) / 2;
        Node *t = new Node;
        t->B = pos[l]; t->E = pos[r]; t->M = pos[m];
        t->left = (l+1 < r) ? build_tree(l, m) : (t->B + 1 < t->E) ? external_node(l, r) : NULL;
        t->right = (l+1 < r) ? build_tree(m, r) : external_node(r, r);

        return t;
    }

    Node *external_node(int l, int r) {
        Node *t = new Node;
        t->B = pos[l]; t->E = pos[r]; t->M = pos[l];
        t->left = t->right = NULL;
        return t;
    }

    void insert(int l, int r, Content c)
    {
        insert(root, l, r, c);
    }

    void insert(Node *v, int l, int r, Content c)
    {
        if (v == NULL) return ;

        if (v->B >= l && r >= v->E) {
            v->c.push_back(c);
            return;
        }

        if (r <= v->M) {
            insert(v->left, l, r, c);
        } else if (l > v->M) {
            insert(v->right, l, r, c);
        } else {
            insert(v->left, l, v->M, c);
            insert(v->right, v->M, r, c);
        }
    }

    void query(Node *v, Position p, vector<Position> &res) {
        if (v == NULL) return;

        if (p < v->B || p > v->E) {
            return;
        }

        if (v->c.size() > 0) {
            for (int i = 0; i < v->c.size(); i++) {
                res.push_back(v->c[i]);
            }
        }

        if (p <= v->M) {
            query(v->left, p, res);
        }

        if (p >= v->M) {
            query(v->right, p, res);
        }
    }

    vector<Content> query(Position p)
    {
        vector<Content> res;

        query(root, p, res);
        return res;
    }

    void release(Node *t) {
        if (t->left) release(t->left);
        if (t->right) release(t->right);
        delete t;
    }
};


int main()
{
    vector<Position> pos;
    pos.push_back(NEG_INF);

    vector<Interval> intervals;
    intervals.push_back(Interval(1, 100));
    intervals.push_back(Interval(2, 3));
    intervals.push_back(Interval(50, 60));
    intervals.push_back(Interval(90, 100));

    for (int i = 0; i < intervals.size(); i++) {
        pos.push_back(intervals[i].low);
        pos.push_back(intervals[i].high);
    }

    sort(pos.begin(), pos.end());
    pos.resize(unique(pos.begin(), pos.end()) - pos.begin());

    SegmentTree tree(pos.begin(), pos.end());
    for (int i = 0; i < intervals.size(); i++) {
        tree.insert(intervals[i].low, intervals[i].high, i+1);
    }

    vector<Content> res = tree.query(55);

    for (int i = 0; i < res.size(); i++) {
        cout << intervals[res[i]-1].low << ", " << intervals[res[i]-1].high << endl;
    }

    return 0;
}
