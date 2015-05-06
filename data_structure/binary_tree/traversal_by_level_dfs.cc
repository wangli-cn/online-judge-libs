#include <iostream>
#include "utils/binary_tree.h"

using namespace tree_with_unique_ptr;

void print_level(Node *root, int level)
{
    if (p == nullptr) return;

    if (level == 1) {
        cout << p->val << " ";
    } else {
        print_level(p->left, level-1);
        print_level(p->right, level-1);
    }
}

void print_level_order(Node *root)
{
    int height = max_height(root);
    for (int level = 1; level <= height; level += 1) {
        print_level(root, level);
        cout << endl;
    }
}

int main()
{
    return 0;
}
