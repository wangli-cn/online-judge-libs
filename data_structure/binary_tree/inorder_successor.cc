#include <iostream>
#include "utils/binary_tree.h"

using namespace tree_with_normal_ptr;

Node<int> *__min(Node<int> *curr)
{
    if (curr == nullptr || curr->right == nullptr) return nullptr;

    Node<int> *t = curr->right;
    while (t->left) t = t->left;

    return t;
}

Node<int> *inorder_successor(Node<int> *root)
{
    if (root->right) {
        return __min(root);
    }

    Node<int> *p = root->parent;
    while (p && p->right == root) {
        root = p;
        p = p->parent;
    }

    return p;
}

int main()
{
    Node<int> *root = build_binary_tree();

    Node<int> *s = inorder_successor(root);
    std::cout << std::boolalpha << s->val << std::endl;

    return 0;
}
