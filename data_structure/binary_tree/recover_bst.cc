//============================================================================
// Recover Binary Search Tree
// Two elements of a binary search tree (BST) are swapped by mistake.
//
// Recover the tree without changing its structure.
//============================================================================

#include <iostream>
#include "binarytree.h"
#include "test_util.h"

using namespace std;
using namespace tree_with_normal_ptr;

void go(Node<int> *curr, Node<int> *&prev, Node<int> *&first, Node<int> *&second)
{
    if (curr == nullptr) return;

    go(curr->left, prev, first, second);

    if (prev != nullptr && prev->val > curr->val) {
        if (first == nullptr) first = curr;
        second = curr;
    }

    prev = curr;
    go(curr->right, prev, first, second);
}

void recover(Node<int> *root)
{
    if (root == nullptr) return;

    Node<int> *prev = nullptr, *first = nullptr, *second = nullptr;
    go(root, prev, first, second);
    swap(first->val, second->val);
}

int main()
{
    return 0;
}
