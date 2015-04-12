#include <iostream>
#include <sstream>
#include "binarytree.h"
#include "test_util.h"

using namespace tree_with_unique_ptr;

void serialize(Node<int> *root, std::ostream &out)
{
    if (root == nullptr) {
        out << "# ";
        return;
    }

    out << root->val << " ";
    serialize(root->left.get(), out);
    serialize(root->right.get(), out);
}

std::unique_ptr<Node<int> > deserialize(std::unique_ptr<Node<int> > root, std::istream &in)
{
    int num;

    if (in >> num) {
        root = std::unique_ptr<Node<int> >(new Node<int>(num));
        std::unique_ptr<Node<int> > left(nullptr);
        std::unique_ptr<Node<int> > right(nullptr);

        root->left = deserialize(std::move(left), in);
        root->right = deserialize(std::move(right), in);
    }

    return std::move(root);
}

int main()
{
    std::unique_ptr<Node<int> > root = build_binary_tree();

    std::stringstream ss;
    serialize(root.get(), ss);

    std::cout << ss.str() << std::endl;

    std::unique_ptr<Node<int> > new_root(nullptr);
    new_root = deserialize(std::move(new_root), ss);

    return 0;
}
