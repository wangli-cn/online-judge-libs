//============================================================================
// Unique Binary Search Trees II
// Given n, generate all structurally unique BST's (binary search trees) that
// store values 1...n.
//
// For example,
// Given n = 3, your program should return all 5 unique BST's shown below.
//
//   1         3     3      2      1
//    \       /     /      / \      \
//     3     2     1      1   3      2
//    /     /       \                 \
//   2     1         2                 3
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    Node(int x) :val(x) {}
    int val;
    Node *left, *right;
};

vector<Node *> go(int l, int u)
{
    vector<Node *> res;

    if (l > u) {
        res.push_back(NULL);
        return res;
    }

    for (int k = l; k <= u; k++) {
        vector<Node *> left_tree = go(l, k-1);
        vector<Node *> right_tree = go(k+1, u);

        for (int i = 0; i < left_tree.size(); i++) {
            for (int j = 0; j < right_tree.size(); j++) {
                Node *root = new Node(k);
                root->left = left_tree[i];
                root->right = right_tree[j];
                res.push_back(root);
            }
        }
    }

    return res;
}

vector<Node *> gen_trees(int n)
{
    return go(1, n);
}

int main(void)
{
    return 0;
}
