#ifndef __INTERVAL_TREE
#define __INTERVAL_TREE

#include <iostream>
#include <vector>
#include <list>
#include "utils/geometry.h"

using Position = int;

class Interval
{
public:
    Position low, high;

    Interval() = delete;
    explicit Interval(Position low, Position high)
      :low(low), high(high) {}
};


template <class Content>
class IntervalTree
{
public:
    std::vector<Position> pos;

    class Node {
    public:
        std::vector<Content> values;
        Position B, M, E;

    private:
        std::unique_ptr<Node> left, right;

        friend class IntervalTree;
    };

    std::unique_ptr<Node> root;

    explicit IntervalTree(std::vector<Position> pos): pos(std::move(pos)) {
        root = build_tree(0, this->pos.size()-1);
    }
    ~IntervalTree() {}


    std::unique_ptr<Node> build_tree(int i, int j) {
        int m = (i+j)/2;

        std::unique_ptr<Node> t = std::make_unique<Node>();

        t->B = pos[i];
        t->E = pos[j];
        t->M = pos[m];

        t->left = (i+1 < j ? build_tree(i, m) : nullptr);
        t->right = (i+1 < j ? build_tree(m, j) : nullptr);

        return t;
    }

    void insert(const Interval &I, Content c) {
        insert(root.get(), I, c);
    }

    void insert(Node *v, const Interval &I, Content c) {
        if (v == nullptr) return;

        if (I.low <= v->B && v->E <= I.high) {
            v->values.push_back(c);
        } else {
            if (I.low < v->M) insert(v->left.get(), I, c);
            if (I.high > v->M) insert(v->right.get(), I, c);
        }
    }

    std::vector<Content> query(Position p) {
        std::vector<Content> out;
        query(root.get(), p, out);
        return out;
    }

    void query(Node *t, Position p, std::vector<Content>& out) {
        if (t == nullptr || p < t->B || p >= t->E)
            return;

        std::copy(t->values.begin(), t->values.end(), std::back_inserter(out));

        if (p < t->M) query(t->left.get(), p, out);
        else query(t->right.get(), p, out);
    }
};

#endif
