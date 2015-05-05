#include <iostream>
#include "utils/binary_tree.h"

using namespace tree_with_unique_ptr;

int go(Node<int> *root, int &max_so_far)
{
    if (root == nullptr) return 0;

    int left_max = go(root->left.get(), max_so_far);
    int right_max = go(root->right.get(), max_so_far);

    int max_under_this_node = root->val;

    if (left_max > 0) max_under_this_node += left_max;
    if (right_max > 0) max_under_this_node += right_max;
    if (max_so_far < max_under_this_node) max_so_far = max_under_this_node;

    int res = root->val;
    return std::max(res, res + std::max(left_max, right_max));
}

int max_path(Node<int> *root)
{
    if (root == nullptr) return 0;
    int max_so_far = root->val;
    go(root, max_so_far);

    return max_so_far;
}

int main()
{
    std::unique_ptr<Node<int> > root = build_binary_tree();

    std::cout << std::boolalpha << max_path(root.get()) << std::endl;

    return 0;
}
