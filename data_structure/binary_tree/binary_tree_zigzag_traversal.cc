//============================================================================
// Binary Tree Zigzag Level Order Traversal
// Given a binary tree, return the zigzag level order traversal of its nodes'
// values. (ie, from left to right, then right to left for the next level and
// alternate between).
//
//For example:
// Given binary tree {3,9,20,#,#,15,7},
//    3
//   / \
//  9  20
//    /  \
//   15   7
// return its zigzag level order traversal as:
// [
//   [3],
//   [20,9],
//   [15,7]
// ]
//============================================================================

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include "utils/common.h"
#include "utils/binary_tree.h"

using namespace tree_with_unique_ptr;

VVI zigzag(Node<int> *root)
{
    VVI res;
    VI row;

    if (root == nullptr) return res;

    bool left_to_right = false;
    std::queue<Node<int> *> currQ;
    std::stack<Node<int> *> nextS;

    currQ.push(root);
    while (!currQ.empty()) {
        Node<int> *front = currQ.front(); currQ.pop();

        if (front != nullptr) {
            row.push_back(front->val);

            if (left_to_right) {
                if (front->right) nextS.push(front->right.get());
                if (front->left) nextS.push(front->left.get());
            } else {
                if (front->left) nextS.push(front->left.get());
                if (front->right) nextS.push(front->right.get());
            }
        }

        if (currQ.empty()) {
            res.push_back(row);
            row.clear();
            left_to_right = !left_to_right;

            while (!nextS.empty()) {
                auto e = nextS.top(); nextS.pop();
                currQ.push(e);
            }
        }
    }

    return std::move(res);
}


int main()
{
    std::unique_ptr<Node<int> > root = build_binary_tree();

    VVI res = zigzag(root.get());
    for (auto &r: res) {
        for (auto &c: r) {
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
