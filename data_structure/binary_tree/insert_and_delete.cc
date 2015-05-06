#include <iostream>
#include <memory>
#include <limits>
#include "utils/binary_tree.h"

using namespace tree_with_unique_ptr;

Node<int> *_min(Node<int> *curr)
{
    if (curr == nullptr || !curr->right) return nullptr;

    Node<int> *t = curr->right.get();
    while (t->left) t = t->left.get();

    return t;
}

std::unique_ptr<Node<int> > go(std::unique_ptr<Node<int> > curr, Node<int> *parent, int k)
{
    if (!curr) {
        return std::move(std::unique_ptr<Node<int> >());
    }

    if (curr->val > k) {
        curr->left = go(std::move(curr->left), curr.get(), k);
        return std::move(curr);
    } else if (curr->val < k) {
        curr->right = go(std::move(curr->right), curr.get(), k);
        return std::move(curr);
    } else {
        if (curr->left && curr->right) {
            Node<int> *t = _min(curr.get());
            curr->val = t->val;
            curr->right = std::move( go(std::move(curr->right), curr.get(), t->val) );
            return std::move(curr);
        } else if (parent->left == curr) {
            parent->left = std::move( (curr->left) ? curr->left : curr->right );
            return std::move(parent->left);
        } else if (parent->right == curr) {
            parent->right = std::move( (curr->left != nullptr) ? curr->left : curr->right );
            return std::move(parent->right);
        }
    }

    return std::move(std::unique_ptr<Node<int> >());
}

std::unique_ptr<Node<int> > remove(std::unique_ptr<Node<int> > root, int k)
{
    if (!root) return std::move(std::unique_ptr<Node<int> >());

    if (root->val == k) {
        std::unique_ptr<Node<int> > t(new Node<int>(std::numeric_limits<int>::max()));
        t->left = std::move(root);

        t->left = std::move( go(std::move(t->left), t.get(), k) );
        root = std::move(t->left);
    } else {
        root = std::move( go(std::move(root), nullptr, k) );
    }

    return std::move(root);
}

std::unique_ptr<Node<int> > insert(std::unique_ptr<Node<int> > root, int val)
{
    if (!root) {
        auto node = std::make_unique<Node<int>>(val);
        return std::move(node);
    }

    if (val <= root->val) {
        root->left = insert(std::move(root->left), val);
    } else {
        root->right = insert(std::move(root->right), val);
    }

    return std::move(root);
}

int main(void)
{
    std::unique_ptr<Node<int> > root1 = build_binary_tree();
    std::unique_ptr<Node<int> > root2 = insert(std::move(root1), 789);

    print_tree(root2.get());

    std::unique_ptr<Node<int> > root3 = remove(std::move(root2), 789);

    print_tree(root3.get());
    return 0;
}
