//============================================================================
// Validate Binary Search Tree
// Given a binary tree, determine if it is a valid binary search tree (BST).
//
// Assume a BST is defined as follows:
//
// The left subtree of a node contains only nodes with keys less than the
// node's key. The right subtree of a node contains only nodes with keys
// greater than the node's key. Both the left and right subtrees must also be
// binary search trees.
//============================================================================

#include <iostream>
#include <memory>
#include <limits>
#include "binarytree.h"
#include "test_util.h"

using namespace std;

bool go(Node<int> *root, Node<int> *&prev)
{
    if (root == nullptr) return true;

    if (go(root->left.get(), prev)) {
        if (prev->val < root->val) {
            prev = root;
            return go(root->right.get(), prev);
        }
    }

    return false;
}

bool is_bst(Node<int> *root)
{
    std::unique_ptr< Node<int> > sentinel( new Node<int>(std::numeric_limits<int>::min()) );
    Node<int> *prev = sentinel.get();
    bool res = go(root, prev);

    return res;
}

int main()
{
    std::unique_ptr<Node<int> > root = build_binary_tree();

    std::cout << std::boolalpha << is_bst(root.get()) << std::endl;

    root->val = 100;

    std::cout << std::boolalpha << is_bst(root.get()) << std::endl;

    return 0;
}
