#include <iostream>
#include <vector>
#include <stack>
#include "utils/binary_tree.h"

using namespace tree_with_normal_ptr;

void iterative_postorder(Node<int> *root)
{
    std::stack<Node<int> *> S;
    Node<int> *curr = nullptr, *prev = nullptr;

    S.push(root);
    while (!S.empty()) {
        curr = S.top();

        if (prev == nullptr || prev->left == curr || prev->right == curr) {
            if (curr->left) S.push(curr->left);
            else if (curr->right) S.push(curr->right);
            else {
                std::cout << curr->val << std::endl;
                S.pop();
            }
        } else if (curr->left == prev) {
            if (curr->right != nullptr) {
                S.push(curr->right);
            } else {
                cout << curr->val << endl;
                S.pop();
            }
        } else if (curr->right == prev) {
            std::cout << curr->val << std::endl;
            S.pop();
        }

        prev = curr;
    }
}

int main(void)
{
    vector<int> input {1,2,3,4,5,6,7,8,9,10};
    Node<int> *root = build_binary_tree();

    iterative_postorder(root);
    return 0;
}

