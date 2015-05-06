#include <iostream>
#include <vector>
#include "utils/binary_tree.h"

using namespace tree_with_normal_ptr;

void morris_traversal(Node<int> *root)
{
    Node<int> *curr = root;

    while (curr != nullptr) {
        if (curr->left == nullptr) {
            std::cout << curr->val << std::endl;
            curr = curr->right;
        } else {
            Node<int> *t = curr->left;
            while (t->right && t->right != curr) t = t->right;

            if (t->right == nullptr) {
                t->right = curr;
                curr = curr->left;
            } else {
                t->right = nullptr;
                std::cout << curr->val << std::endl;
                curr = curr->right;
            }
        }
    }
}

int main()
{
    Node<int> *root = build_binary_tree();

    morris_traversal(root);
    return 0;
}
