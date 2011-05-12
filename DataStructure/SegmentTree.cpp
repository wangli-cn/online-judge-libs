#include <iostream>
#include <cstdio>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

const int NEG_INF = INT_MIN;
typedef int Position;
typedef int Content;

struct Interval 
{
    Position low, high;
    Interval(Position low, Position high)
        :low(low), high(high) {}
};

struct SegmentTree
{
    vector<Position> pos;

    struct Node {
        Content c;
        Position B, M, E;
        Node *left, *right;
    } *root;

    template <class IN>
    SegmentTree(IN begin, IN end) : pos(begin, end) {
        root = build_tree(0, pos.size()-1);
    }
    ~SegmentTree() { release(root); }

    Node *build_tree(int l, int r) {
        int m = (l + r) / 2;

        Node *t = new Node;
        t->B = pos[l]; t->E = pos[r]; t->M = pos[m];
        t->c = 0;
        t->left = (l+1 < r) ? build_tree(l, m) : (t->B + 1 < t->E) ? external_node(l, r) : NULL;
        t->right = (l+1 < r) ? build_tree(m, r) : external_node(r, r);
        return t;
    }

    Node *external_node(int l, int r) {
        Node *t = new Node;
        t->B = pos[l]; t->E = pos[r]; t->M = pos[l];
        t->c = 0;
        t->left = t->right = NULL;
        return t;
    }

    void insert(int l, int r, Content c) {
        insert(root, l, r, c);
    }

    void insert(Node *v, int l, int r, Content c) {
        if (!v) return;

        if (v->B >= l && r >= v->E) {
            v->c = c;
            return;
        }

        if (v->c > 0) {
            if (v->left) v->left->c = v->c;
            if (v->right) v->right->c = v->c;
        }
        v->c = -1;

        if (r <= v->M) {
            insert(v->left, l, r, c);
        } else if (l > v->M) {
            insert(v->right, l, r, c);
        } else {
            insert(v->left, l, v->M, c);
            insert(v->right, v->M, r, c);
        }
    }

    void query(vector<Content> &res) {
        query(root, res);
    }

    void query(Node *v, vector<Content> &res) {
        if (!v) return;

        //printf("(%d, %d) = %d\n", v->B, v->E, v->c);
        if (v->c == 0) {
            return;
        }

        if (v->c > 0) {
            res.push_back(v->c);
            return;
        }

        query(v->left, res);
        query(v->right, res);
    }

    void release(Node *t) {
        if (t->left) release(t->left);
        if (t->right) release(t->right);
        delete t;
    }
};


int main(void)
{
    int nCase;
    int n;

    scanf("%d", &nCase);
    while (nCase--) {
        scanf("%d", &n);

        vector<int> pos;
        pos.push_back(NEG_INF);
        vector<Interval> intervals;
        for (int i = 0, r, l; i < n; ++i) {
            scanf("%d %d", &l, &r);

            intervals.push_back(Interval(l, r));
            pos.push_back(l);
            pos.push_back(r);
        }
        sort(pos.begin(), pos.end());
        pos.resize(unique(pos.begin(), pos.end()) - pos.begin());

        SegmentTree tree(pos.begin(), pos.end());
        for (int i = 0; i < n; i++) {
            tree.insert(intervals[i].low, intervals[i].high, i+1);
        }

        vector<Content> res;
        tree.query(res);
        sort(res.begin(), res.end());
        //for (int i = 0 ; i < res.size(); i++) {
            //printf("%d ", res[i]);
        //}
        int ans = unique(res.begin(), res.end()) - res.begin();
        printf("%d\n", ans);
    }

    return 0;
}
