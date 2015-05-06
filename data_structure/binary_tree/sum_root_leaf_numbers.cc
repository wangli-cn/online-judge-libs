//============================================================================
//  Given a binary tree containing digits from 0-9 only, each root-to-leaf¿
//  path could represent a number.
//
//  An example is the root-to-leaf path 1->2->3 which represents the number¿
//  123.
//
//  Find the total sum of all root-to-leaf numbers.
//
//  For example,
//
//  /*    1     */
//  /*   / \    */
//  /*  2   3   */
//  The root-to-leaf path 1->2 represents the number 12.
//  The root-to-leaf path 1->3 represents the number 13.
//
//  return the sum = 12 + 13 = 25.
//============================================================================

#include <iostream>
#include "utils/binary_tree.h"

using namespace tree_with_normal_ptr;

void go(Node<int> *root, int sum, int &res)
{
    if (root->left == nullptr && root->right == nullptr) {
        sum += root->val;
        res += sum;
        return;
    } else {
        sum += root->val;
        sum *= 10;

        if (root->left) go(root->left, sum, res);
        if (root->right) go(root->right, sum ,res);
    }
}

int summation(Node<int> *root)
{
    if (root == nullptr) return 0;

    int result;
    go(root, 0, result);

    return result;
}

int main()
{
    return 0;
}
