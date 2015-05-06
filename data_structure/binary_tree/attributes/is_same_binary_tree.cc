//============================================================================
// Same Tree
// Given two binary trees, write a function to check if they are equal or not.
//
// Two binary trees are considered equal if they are structurally identical
// and the nodes have the same value.
//============================================================================

#include <iostream>
#include "utils/binary_tree.h"

using namespace tree_with_unique_ptr;

bool is_same(Node<int> *root1, Node<int> *root2)
{
    if (root1 == nullptr || root2 == nullptr) return root1 == root2;
    return (root1->val == root2->val) &&
           is_same(root1->left.get(), root2->left.get()) &&
           is_same(root1->right.get(), root2->right.get());
}

int main()
{
    std::unique_ptr<Node<int> > root1 = build_binary_tree();
    std::unique_ptr<Node<int> > root2 = build_binary_tree();

    std::cout << std::boolalpha << is_same(root1.get(), root2.get())<< std::endl;

    return 0;
}
