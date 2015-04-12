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
#include <queue>
#include "binarytree.h"
#include "test_util.h"

using namespace std;

vector<vector<int> > zigzag(Node<int> *root)
{
    vector<vector<int> > res;
    vector<int> row;

    if (root == nullptr) return res;

    bool left_to_right = true;
    stack<Node<int> *> currQ, nextQ;
    currQ.push(root);
    while (!currQ.empty()) {
        Node<int> *front = currQ.front(); currQ.pop();

        if (front != nullptr) {
            row.push_back(front->val);

            if (left_to_right) {
                if (front->left) nextQ.push(front->left.get());
                if (front->right) nextQ.push(front->right.get());
            } else {
                if (front->right) nextQ.push(front->right.get());
                if (front->left) nextQ.push(front->left.get());
            }
        }

        if (currQ.empty()) {
            res.push_back(row);
            row.clear();
            left_to_right = !left_to_right;
            swap(nextQ, currQ);
        }
    }

    return std::move(res);
}

int main()
{
    std::unique_ptr<Node<int> > root = build_binary_tree();

    vector<vector<int> > res = zigzag(root.get());
    for (auto &r: res) {
        for (auto &c: r) {
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
