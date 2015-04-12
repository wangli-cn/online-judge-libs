//============================================================================
// Binary Tree Inorder Traversal
// Given a binary tree, return the inorder traversal of its nodes' values.
//
// For example:
// Given binary tree {1,#,2,3},
//   1
//    \
//     2
//    /
//   3
// return [1,3,2].
//
// Note: Recursive solution is trivial, could you do it iteratively?
//
// Reference:
// http://www.leetcode.com/2010/04/binary-search-tree-in-order-traversal.html
//
//============================================================================

#include <iostream>
#include <vector>
#include <stack>
#include "utils/binary_tree.h"

using namespace tree_with_normal_ptr;

void iterative_inorder(Node<int> *root)
{
    bool done = false;
    Node<int> *curr = root;
    std::stack<Node<int> *> S;

    while (!done) {
        if (curr != nullptr) {
            S.push(curr);
            curr = curr->left;
        } else {
            if (!S.empty()) {
                curr = S.top(); S.pop();
                std::cout << curr->val << std::endl;
                curr = curr->right;
            } else {
                done = true;
            }
        }
    }
}

int main()
{
    Node<int> *root = build_binary_tree();
    iterative_inorder(root);

    return 0;
}

