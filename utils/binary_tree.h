#ifndef __BINARY_TREE
#define __BINARY_TREE

#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>


namespace tree_with_normal_ptr {
    template<typename T, class = typename std::enable_if<std::is_copy_constructible<T>::value>::type >
    class Node
    {
        public:
            Node(T x) :val(x), left(nullptr), right(nullptr), parent(nullptr) {}
            T val;

            Node<T> *left, *right, *parent;

        private:
            Node();
            Node(const Node &) = delete;
            Node(const Node &&) = delete;
            Node &operator=(const Node&) = delete;
            Node &operator=(const Node&&) = delete;
    };
}

namespace tree_with_unique_ptr {
    template<typename T, class = typename std::enable_if<std::is_copy_constructible<T>::value>::type >
    class Node
    {
        public:
            Node(T x) :val(x), left(nullptr), right(nullptr) {}
            T val;

            std::unique_ptr<Node<T> > left, right;

        private:
            Node();
            Node(const Node &) = delete;
            Node(const Node &&) = delete;
            Node &operator=(const Node&) = delete;
            Node &operator=(const Node&&) = delete;
    };
}


namespace tree_with_unique_ptr {

std::unique_ptr<Node<int> > convert(const std::vector<int> &a, int start, int end, int &idx)
{
    if (start > end) return nullptr;

    int mid = start + (end - start) / 2;

    std::unique_ptr<Node<int> > left_subtree = convert(a, start, mid-1, idx);
    std::unique_ptr<Node<int> > root(new Node<int>(a[idx++]));

    root->left = std::move(left_subtree);
    root->right = convert(a, mid+1, end, idx);

    return std::move(root);
}

std::unique_ptr<Node<int> > build_binary_tree()
{
    std::vector<int> input {1,2,3,4,5,6,7,8,9,10};
    int idx = 0;

    std::unique_ptr<Node<int> > root = convert(input, 0, input.size()-1, idx);

    return std::move(root);
}

void print_tree(Node<int> *root, int indent = 0)
{
    if (root != nullptr) {
        if (root->left.get()) print_tree(root->left.get(), indent + 4);
        if (root->right.get()) print_tree(root->right.get(), indent + 4);
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        std::cout << root->val << std::endl << " ";
    }
}


}


namespace tree_with_normal_ptr {

Node<int> *convert(const std::vector<int> &a, int start, int end, int &idx)
{
    if (start > end) return nullptr;

    int mid = start + (end - start) / 2;

    Node<int> *left_subtree = convert(a, start, mid-1, idx);
    Node<int> *root = new Node<int>(a[idx++]);

    root->left = left_subtree;
    root->right = convert(a, mid+1, end, idx);

    if (root->left) {
        root->left->parent = root;
    }

    if (root->right) {
        root->right->parent = root;
    }

    return root;
}

Node<int> *build_binary_tree()
{
    std::vector<int> input {1,2,3,4,5,6,7,8,9,10};
    int idx = 0;

    Node<int> *root = convert(input, 0, input.size()-1, idx);

    return root;
}

void print_tree(Node<int> *root, int indent = 0)
{
    if (root != nullptr) {
        if (root->left) print_tree(root->left, indent + 4);
        if (root->right) print_tree(root->right, indent + 4);
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        std::cout << root->val << std::endl << " ";
    }
}

}

#endif
