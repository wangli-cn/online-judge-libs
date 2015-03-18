#include <iostream>
#include <vector>
#include "binarytree.h"
#include "test_util.h"

using namespace tree_with_normal_ptr;

void iterative_inorder(Node<int> *root)
{
    Node<int> *prev = nullptr, *curr = root;

    while (curr != nullptr) {
        if (prev == curr->parent) {
            if (curr->left) {
                prev = curr;
                curr = curr->left;
            } else if (curr->right) {
                std::cout << curr->val << std::endl;
                prev = curr;
                curr = curr->right;
            } else {
                prev = nullptr;
            }
        } else if (prev == curr->left) {
            std::cout << curr->val << std::endl;
            if (curr->right) {
                prev = curr;
                curr = curr->right;
            } else {
                prev = curr;
                curr = curr->parent;
            }
        } else if (prev == curr->right) {
            prev = curr;
            curr = curr->parent;
        }
    }
}

int main(void)
{
    Node<int> *root = build_binary_tree();
    iterative_inorder(root);

    return 0;
}

