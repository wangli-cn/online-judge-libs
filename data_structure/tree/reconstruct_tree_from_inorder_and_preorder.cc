//============================================================================
// Construct Binary Tree from Inorder and preorder Traversal
// Given inorder and preorder traversal of a tree, construct the binary tree.
//
// Note:
// You may assume that duplicates do not exist in the tree.
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include "binarytree.h"
#include "test_util.h"

using namespace std;
using namespace tree_with_normal_ptr;

Node<int> *build_tree(vector<int>::iterator begin, vector<int>::iterator end, vector<int> &preorder)
{
    if (preorder.empty()) return nullptr;

    vector<int>::iterator it = find(begin, end, preorder.back());
    if (it == end) return nullptr;

    int value = preorder.back(); preorder.pop_back();

    Node<int> *root = new Node<int>(value);
    root->left = build_tree(begin, it, preorder);
    root->right = build_tree(it+1, end, preorder);

    return root;
}

Node<int> *reconstruct(vector<int> inorder, vector<int> preorder)
{
    reverse(preorder.begin(), preorder.end());
    Node<int> *root = build_tree(inorder.begin(), inorder.end(), preorder);

    return root;
}

int main(void)
{
    return 0;
}
