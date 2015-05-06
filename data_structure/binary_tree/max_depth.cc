//============================================================================
// Maximum Depth of Binary Tree
// Given a binary tree, find its maximum depth.
//
// The maximum depth is the number of nodes along the longest path from the
// root node down to the farthest leaf node.
//============================================================================

#include <iostream>
#include "utils/binary_tree.h"

using namespace tree_with_unique_ptr;

int max_depth(Node<int> *root)
{
    if (root == nullptr) return 0;
    return 1 + std::max(max_depth(root->left.get()), max_depth(root->right.get()));
}

int main()
{
    std::unique_ptr<Node<int> > root = build_binary_tree();
    std::cout << max_depth(root.get()) << std::endl;
    return 0;
}
