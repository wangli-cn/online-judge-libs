#include <iostream>
#include "utils/binary_tree.h"

using namespace tree_with_unique_ptr;

Node<int> *lca(Node<int> *root, Node<int> *p, Node<int> *q)
{
    if (root == nullptr) return nullptr;

    if (root == p || root == q) return root;

    Node<int> *L = lca(root->left.get(), p, q);
    Node<int> *R = lca(root->right.get(), p, q);

    if (L && R) return root;
    return L ? L : R;
}

int main()
{
    std::unique_ptr<Node<int> > root = build_binary_tree();

    return 0;
}
