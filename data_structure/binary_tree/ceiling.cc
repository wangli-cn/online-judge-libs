#include <iostream>
#include "utils/binary_tree.h"

using namespace tree_with_unique_ptr;

int ceiling(Node<int> *root, int target)
{
    if (root == nullptr) {
        return -1;
    }

    if (root->val == target) {
        return root->val;
    }

    if (root->val < target) {
        return ceiling(root->right.get(), target);
    } else {
        int t = ceiling(root->left.get(), target);
        return (t >= target) ? t : root->val;
    }
}

int main(void)
{
    std::unique_ptr<Node<int> > root = build_binary_tree();

    std::cout << ceiling(root.get(), 8) << std::endl;

    return 0;
}
