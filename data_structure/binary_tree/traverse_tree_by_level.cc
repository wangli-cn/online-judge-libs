//============================================================================
// Binary Tree Level Order Traversal
// Given a binary tree, return the level order traversal of its nodes' values.
// (ie, from left to right, level by level).
//
// For example:
// Given binary tree {3,9,20,#,#,15,7},
//    3
//   / \
//  9  20
//    /  \
//   15   7
// return its level order traversal as:
// [
//   [3],
//   [9,20],
//   [15,7]
// ]
//============================================================================

#include <iostream>
#include <vector>
#include <queue>

struct Node
{
    int data;
    std::vector<Node *> children;
};


void print_tree(Node *root)
{
    std::queue<Node *> Q;
    int current_level_counter, next_level_counter;

    Q.push(root);
    current_level_counter = 1;
    next_level_counter = 0;

    while (!Q.empty()) {
        Node *nd = Q.front(); Q.pop();

        current_level_counter -= 1;
        std::cout << nd->data << " ";

        for (int i = 0; i < nd->children.size(); i++) {
            Q.push(nd->children[i]);
            next_level_counter += 1;
        }

        if (current_level_counter == 0) {
            current_level_counter = next_level_counter;
            next_level_counter = 0;
            std::cout << std::endl;
        }
    }
}


int main(void)
{
    return 0;
}
