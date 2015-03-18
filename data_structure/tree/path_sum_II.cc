//============================================================================
// Path Sum II
// Given a binary tree and a sum, find all root-to-leaf paths where each
// path's sum equals the given sum.
//
// For example:
// Given the below binary tree and sum = 22,
//              5
//             / \
//            4   8
//           /   / \
//          11  13  4
//         /  \    / \
//        7    2  5   1
// return
// [
//   [5,4,11,2],
//   [5,8,4,5]
// ]
//============================================================================

#include <iostream>
#include <vector>
#include "binarytree.h"
#include "test_util.h"

using namespace std;
using namespace tree_with_normal_ptr;

bool go(Node<int> *root, int sum, vector<int> path)
{
    if (root == nullptr) return false;

    sum -= root->val;
    path.push_back(root->val);

    if (root->left == nullptr && root->right == nullptr) {
        for (auto it: path) cout << it << " ";
        cout << endl;

        return (sum == 0);
    }
    return go(root->left, sum, path) || go(root->right, sum, path);
}

int main()
{
    Node<int> *root = build_binary_tree();

    vector<int> path;
    std::cout << std::boolalpha << go(root, 22, path) << std::endl;
    return 0;
}
