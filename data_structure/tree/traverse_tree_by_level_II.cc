#include <iostream>
#include <stack>
#include <vector>
#include "binarytree.h"
#include "test_util.h"

using namespace std;
using namespace tree_with_normal_ptr;

vector<vector<int> > traverse(Node<int> *root)
{
    vector<vector<int> > res;
    if (root == nullptr) return res;

    stack<vector<Node<int> *> > S;
    S.push(vector<Node<int> *>(1, root));

    while (1) {
        vector<Node<int> *> row;
        for (auto it: S.top()) {
            if (it->left) row.push_back(it->left);
            if (it->right) row.push_back(it->right);
        }

        if (row.empty()) break;
        S.push(row);
    }

    while (!S.empty()) {
        vector<int> row;
        for (auto it: S.top()) {
            row.push_back(it->val);
        }
        res.push_back(row);
        S.pop();
    }

    return res;
}


int main(void)
{
    Node<int> *root = build_binary_tree();

    vector<vector<int> > res = traverse(root);

    for (auto it1: res) {
        for (auto it2: it1) {
            cout << it2 << " ";
        }
        cout << endl;
    }

    return 0;
}

