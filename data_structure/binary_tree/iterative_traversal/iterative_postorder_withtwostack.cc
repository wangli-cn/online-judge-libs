#include <iostream>
#include <vector>
#include <stack>
#include "binarytree.h"
#include "test_util.h"

using namespace std;
using namespace tree_with_normal_ptr;

void iterative_postorder(Node<int> *root)
{
    stack<Node<int> *> S;
    stack<Node<int> *> SS;

    S.push(root);
    while (!S.empty()) {
        Node<int> *curr = S.top(); S.pop();

        SS.push(curr);

        if (curr->left != nullptr) S.push(curr->left);
        if (curr->right != nullptr) S.push(curr->right);
    }

    while (!SS.empty()) {
        cout << SS.top()->val << endl;
        SS.pop();
    }
}

int main(void)
{
    vector<int> input {1,2,3,4,5,6,7,8,9,10};
    Node<int> *root = build_binary_tree();

    iterative_postorder(root);
    return 0;
}

