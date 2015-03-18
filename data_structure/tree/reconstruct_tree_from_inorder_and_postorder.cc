//============================================================================
// Construct Binary Tree from Inorder and Postorder Traversal
// Given inorder and postorder traversal of a tree, construct the binary tree.
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

Node<int> *build_tree(vector<int>::iterator begin, vector<int>::iterator end, vector<int> &postorder)
{
    if (postorder.empty()) return nullptr;

    vector<int>::iterator it = find(begin, end, postorder.back());
    if (it == end) return nullptr;

    int value = postorder.back(); postorder.pop_back();

    Node<int> *root = new Node<int>(value);
    root->right = build_tree(it+1, end, postorder);
    root->left = build_tree(begin, it, postorder);

    return root;
}

Node<int> *reconstruct(vector<int> inorder, vector<int> postorder)
{
    Node<int> *root = build_tree(inorder.begin(), inorder.end(), postorder);

    return root;
}

int main(void)
{
    return 0;
}
