#include <iostream>
#include <vector>
#include <memory>
#include "utils/common.h"


class HuffmanTree
{
public:

    class Node {
    public:
        Weight weight;
        unique_ptr<Node> left, right;

        explicit Node(Weight weight) :weight(weight) {
            left = right = nullptr;
        }

        bool operator<(const Node &e) {
            return weight > e.weight;
        }
    };

    vector<Weight> w;
    unique_ptr<Node> root;

    HuffmanTree(std::vector<int> a) :w(std::move(a)) {
        root = build_tree();
    }

    void build_tree() {
        std::priority_queue<shared_ptr<Node>> Q;

        int n = w.size();
        for (int i = 0; i < n; ++i) {
            Q.push(make_shared<Node>(w[i]));
        }

        for (int i = 0; i < n; ++i) {
            Node v1 = Q.top(); Q.pop();
            Node v2 = Q.top(); Q.pop();

            unique_ptr<Node> v = make_unique<Node>(v1.weight + v2.weight, v1, v2);
            Q.push(v);
        }
    }
};


int main(void)
{
    return 0;
}

