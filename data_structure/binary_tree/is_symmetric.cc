//============================================================================
// Given a binary tree, check whether it is a mirror of itself (ie, symmetric
// around its center).
//
// For example, this binary tree is symmetric:
//
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// But the following is not:
//    1
//   / \
//  2   2
//   \   \
//   3    3
// Note:
// Bonus points if you could solve it both recursively and iteratively.
//
//============================================================================

#include <iostream>
#include "binarytree.h"
#include "test_util.h"

bool is_symmetric(Node<int> *p, Node<int> *q)
{
    if (p == nullptr || q == nullptr) return p == q;
    return (p->val) == (q->val) &&
           is_symmetric(p->left.get(), q->right.get()) &&
           is_symmetric(p->right.get(), q->left.get());
}

int main()
{
    std::unique_ptr<Node<int> > root1 = build_binary_tree();
    std::unique_ptr<Node<int> > root2 = build_binary_tree();

    std::cout << std::boolalpha << is_symmetric(root1.get(), root2.get()) << std::endl;

    return 0;
}
