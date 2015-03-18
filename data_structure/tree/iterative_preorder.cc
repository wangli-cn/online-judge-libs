#include <iostream>
#include <vector>
#include <stack>
#include "binarytree.h"
#include "test_util.h"

using namespace std;
using namespace tree_with_unique_ptr;

void iterative_preorder(Node<int> *root)
{
    stack<Node<int> *> S;

    S.push(root);
    while (!S.empty()) {
        Node<int> *curr = S.top(); S.pop();

        cout << curr->val << endl;
        if (curr->right.get() != nullptr) S.push(curr->right.get());
        if (curr->left.get() != nullptr) S.push(curr->left.get());
    }
}

int main(void)
{
    vector<int> input {1,2,3,4,5,6,7,8,9,10};

    int idx = 0;
    std::unique_ptr<Node<int> > root = build_binary_tree();

    iterative_preorder(root.get());

    return 0;
}

