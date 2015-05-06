//============================================================================
// Balanced Binary Tree
// Given a binary tree, determine if it is height-balanced.
//
// An example of a height-balanced tree. A height-balanced tree is a tree
// whose subtrees differ in height by no more than one and the subtrees are
// height-balanced, too.
//============================================================================

#include <iostream>
#include "utils/binary_tree.h"

using namespace tree_with_unique_ptr;

bool go(Node<int> *root, int &height)
{
    if (nullptr == root) {
        height = 0;
        return true;
    }

    int left_height = 0, right_height = 0;
    bool is_left_balanced = go(root->left.get(), left_height);
    bool is_right_balanced = go(root->right.get(), right_height);

    height = 1 + std::max(left_height, right_height);

    return (is_left_balanced && is_right_balanced && abs(left_height - right_height) <= 1);
}

bool is_bst_balanced(Node<int> *root)
{
    int height = 0;
    return go(root, height);
}

int main(void)
{
    std::unique_ptr<Node<int> > root = build_binary_tree();

    std::cout << std::boolalpha << is_bst_balanced(root.get()) << std::endl;
    return 0;
}

