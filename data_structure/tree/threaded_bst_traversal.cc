#include <iostream>
#include "binarytree.h"
#include "test_util.h"

using namespace std;
using namespace tree_with_normal_ptr;

void inorder_traversal(Node<int> *root)
{
    if (root == nullptr) return;

    Node<int> *curr = root;
    while (curr->left != nullptr) curr = curr->left;

    Node<int> *prev = nullptr;
    while (curr != nullptr) {
        cout << curr->val << endl;

        prev = curr;
        curr = curr->right;

        if (prev->right_is_child) {
            if (curr != nullptr) {
                while (curr->left != nullptr) {
                    curr = curr->left;
                }
            }
        }
    }
}

int main()
{
    return 0;
}
