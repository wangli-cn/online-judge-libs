//============================================================================
// Populating Next Right Pointers in Each Node II
//¿
// Follow up for problem "Populating Next Right Pointers in Each Node".
//
// What if the given tree could be any binary tree? Would your previous¿
// solution still work?
//
// Note:
//
// You may only use constant extra space.
//¿
// For example, given the following perfect binary tree:
//  "     1     "
//  "    / \    "
//  "   2   3   "
//  "  / \   \  "
//  " 4  5    7 "
// After calling your function, the tree should look like:
//  "      1 -> NULL      "
//  "     /  \            "
//  "    2 -> 3 -> NULL   "
//  "   / \    \          "
//  "  4-> 5 -> 7 -> NULL "
//============================================================================


#include <iostream>

using namespace std;


Node<int> *get_next(Node<int> *curr, bool is_left)
{
    if (is_left) {
        if (curr->right) return curr->right;
    }

    while ((curr = curr->next)) {
        if (curr->left) return curr->left;
        if (curr->right) return curr->right;
    }

    return nullptr;
}

void populate(Node<int> *root)
{
    if (root == nullptr) return;

    Node<int> *next_head = nullptr;
    Node<int> *curr = root;
    while (curr) {
        if (curr->left) {
            curr->left->next = get_next(curr, true);
            if (next_head == nullptr) next_head = curr->left;
        }

        if (curr->right) {
            curr->right->next = get_next(curr, false);
            if (next_head == nullptr) next_head = curr->right;
        }

        curr = curr->next;
    }

    populate(next_head);
}


int main(void)
{
    return 0;
}
