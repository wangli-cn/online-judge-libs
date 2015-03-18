//Take a binary tree and rearrange left and right pointers to make a circular doubly linked list.
//Convert a BST to a sorted circular doubly-linked list in-place.

#include <iostream>
#include "binarytree.h"
#include "test_util.h"

using namespace std;

void go(Node *root, Node *&prev, Node *&head)
{
    if (root == NULL) return;

    go(root->left, prev, head);

    root->left = prev;
    if (prev != NULL) prev->right = root;
    else head = root;

    Node *right = root->right;

    head->left = root;
    root->right = head;

    prev = root;
    go(right, prev, head);
}

Node *tree2list(Node *root)
{
    Node *prev = NULL, *head = NULL;
    go(root, prev, head);
    return head;
}

int main()
{
    std::unique_ptr<Node<int> > root = build_binary_tree();

    std::cout << std::boolalpha << is_bst(root.get()) << std::endl;

    return 0;
}
