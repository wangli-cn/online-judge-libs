//============================================================================
// Minimum Depth of Binary Tree
//
// Given a binary tree, find its minimum depth.
//
// The minimum depth is the number of nodes along the shortest path from the
// root node down to the nearest leaf node.
//============================================================================

#include <iostream>
#include "utils/binary_tree.h"

using namespace tree_with_unique_ptr;

void go(Node<int> *root, int curr_depth, int &min_depth)
{
    if (root == nullptr) return;

    if (root->left.get() == nullptr && root->right.get() == nullptr) {
        min_depth = std::min(min_depth, curr_depth);
    }

    go(root->left.get(), curr_depth+1, min_depth);
    go(root->right.get(), curr_depth+1, min_depth);
}

int min_depth(Node<int> *root)
{
    int res = std::numeric_limits<int>::max();
    go(root, 0, res);
    return res;
}

int main()
{
    std::unique_ptr<Node<int> > root = build_binary_tree();

    std::cout << min_depth(root.get()) << std::endl;
    return 0;
}
