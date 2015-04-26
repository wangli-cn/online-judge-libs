#ifndef __SEGMENT_TREE
#define __SEGMENT_TREE

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


class IntervalTree
{
public:
    std::vector<Position> pos;

    class Node {
    public:
        std::vector<Interval> sorted_by_left;
        std::vector<Interval> sorted_by_right;

    private:
        std::unique_ptr<Node> left, right;

        friend class IntervalTree;
    };

    std::unique_ptr<Node> root;

    explicit IntervalTree(std::vector<Interval> intervals, int b, int e): {
        root = build_tree(intervals, b, e);
    }
    ~IntervalTree() {}


    std::unique_ptr<Node> build_tree(intervals, Position b, Position e) {
        Position m = (b+e)/2;

        std::unique_ptr<Node> t = std::make_unique<Node>();

        for (auto i: intervals) {
            if (intersect(i, m)) {
                t->sorted_by_left.push_back(i);
                t->sorted_by_right.push_back(i);
            } else if (at_left(i, m)) {
                left_parts.push_back(i);
            } else {
                right_parts.push_back(i);
            }
        }

        t->left = build_tree(left_parts, b, m);
        t->right = build_tree(right_parts, m, e);

        return t;
    }


    std::vector<Interval> query(Position p) {
        query(root.get(), p, out);
        return out;
    }

    void query(Node *t, Position p, std::vector<Interval>& out) {
    }
};

#endif
