//============================================================================
// Path Sum
// Given a binary tree and a sum, determine if the tree has a root-to-leaf path
// such that adding up all the values along the path equals the given sum.
//
// For example:
// Given the below binary tree and sum = 22,
//              5
//             / \
//            4   8
//           /   / \
//          11  13  4
//         /  \      \
//        7    2      1
// return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
//============================================================================

#include <iostream>
#include "binarytree.h"
#include "test_util.h"

using namespace std;
using namespace tree_with_normal_ptr;

bool go(Node<int> *root, int sum)
{
    if (root == nullptr) return false;

    sum -= root->val;

    if (root->left == nullptr && root->right == nullptr) return (sum == 0);
    return go(root->left, sum) || go(root->right, sum);
}

int main()
{
    Node<int> *root = build_binary_tree();

    std::cout << std::boolalpha << go(root, 22) << std::endl;
    return 0;
}
