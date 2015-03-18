//============================================================================
// Flatten Binary Tree to Linked List
// Given a binary tree, flatten it to a linked list in-place.
//
// For example,
// Given
//
//         1
//        / \
//       2   5
//      / \   \
//     3   4   6
// The flattened tree should look like:
//   1
//    \
//     2
//      \
//       3
//        \
//         4
//          \
//           5
//            \
//             6
// Hints:
// If you notice carefully in the flattened tree, each node's right child
// points to the next node of a pre-order traversal.
//============================================================================

#include <iostream>

using namespace std;

struct Node
{
    Node(int x) :val(x) {}
    int val;
    Node *left, *right;
};

void go(Node *root, Node *&prev)
{
    if (root == nullptr) return;

    Node *left = root->left;
    root->left = nullptr;
    Node *right = root->right;
    root->right = nullptr;

    if (prev == nullptr) prev = root;
    else {
        prev->right = root;
        prev = prev->right;
    }

    go(left, prev);
    go(right, prev);
}

Node *flatten(Node *root)
{
    Node *prev = nullptr;
    return root;
}

int main()
{
    return 0;
}
