#include <iostream>
#include <vector>
#include "binarytree.h"
#include "test_util.h"

using namespace std;
using namespace tree_with_normal_ptr;

void morris_traversal(Node<int> *root)
{
    Node<int> *curr = root;

    while (curr != nullptr) {
        if (curr->left == nullptr) {
            cout << curr->val << endl;
            curr = curr->right;
        } else {
            Node<int> *t = curr->left;
            while (t->right != nullptr && t->right != curr) t = t->right;

            if (t->right == nullptr) {
                cout << curr->val << endl;
                t->right = curr;
                curr = curr->left;
            } else {
                t->right = nullptr;
                curr = curr->right;
            }
        }
    }
}

int main(void)
{
    vector<int> input {1,2,3,4,5,6,7,8,9,10};
    Node<int> *root = build_binary_tree();

    morris_traversal(root);
    return 0;
}
