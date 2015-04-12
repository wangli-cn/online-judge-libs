//============================================================================
// Populating Next Right Pointers in Each Node<int>
//¿
// Given a binary tree
//
// struct TreeLinkNode<int> {
//     TreeLinkNode<int> *left;
//     TreeLinkNode<int> *right;
//     TreeLinkNode<int> *next;
// }
//
// Populate each next pointer to point to its next right node. If there is no¿
// next right node, the next pointer should be set to NULL.
//
// Initially, all next pointers are set to NULL.
//
// Note:
//
// You may only use constant extra space.
// You may assume that it is a perfect binary tree (ie, all leaves are at the¿
// same level, and every parent has two children).
//¿
// For example, given the following perfect binary tree:
//  "     1     "
//  "    / \    "
//  "   2   3   "
//  "  / \ / \  "
//  " 4  5 6  7 "
// After calling your function, the tree should look like:
//  "      1 -> NULL      "
//  "     /  \            "
//  "    2 -> 3 -> NULL   "
//  "   / \  / \          "
//  "  4->5->6->7 -> NULL "
//============================================================================

#include <iostream>

using namespace std;

void populate(Node<int> *root)
{
    if (root == nullptr) return;
    if (root->left == nullptr || root->right == nullptr) return;

    root->left->next = root->right;
    root->right->next = (root->next) ? root->next->left : nullptr;
    populate(root->left);
    populate(root->right);
}

int main(void)
{
    return 0;
}
