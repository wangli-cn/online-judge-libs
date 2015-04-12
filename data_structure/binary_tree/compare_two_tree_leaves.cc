//============================================================================
// Given references to roots of two binary trees, how do you determine whether the sequence of the leaf elements equal but you must implement short circuiting return when the first node violates the rule.
//
//============================================================================

#include <stack>
#include "utils/binary_tree.h"

using namespace tree_with_normal_ptr;

Node<int> *get_next_leaf(Node<int> *root, std::stack<Node<int> *> &S)
{
    bool done = false;
    Node<int> *curr = root;

    bool from_outer = true;
    while (!done) {
        if (!from_outer && curr->left == nullptr && curr->right == nullptr) {
            //is leaf
            break;
        }

        if (curr != nullptr) {
            S.push(curr);
            curr = curr->left;
        } else {
            if (!S.empty()) {
                curr = S.top(); S.pop();
                curr = curr->right;
            } else {
                done = true;
            }
        }
    }

    return curr;
}

bool compare_leaves(Node<int> *root1, Node<int> *root2)
{
    std::stack<Node<int> *> S1, S2;
    bool done = false;


    bool match = true;
    while (!done) {
        Node<int> *leaf1 = get_next_leaf(root1, S1);
        Node<int> *leaf2 = get_next_leaf(root2, S2);

        while (1) {
            leaf1 = get_next_leaf(root1, S1);
            leaf2 = get_next_leaf(root2, S2);

            if (leaf1 == nullptr || leaf2 == nullptr) {
                if (leaf1 == leaf2) match = true;
                else match = false;
                break;
            } else if (leaf1->val != leaf2->val) {
                match = false;
                break;
            }
            std::cout << leaf1->val << " " << leaf2->val << std::endl;
        }

        if (S1.empty() || S2.empty()) {
            done = true;
        }
    }

    return match;
}


int main()
{
    Node<int> *root1 = build_binary_tree();
    Node<int> *root2 = build_binary_tree();

    std::cout << std::boolalpha << compare_leaves(root1, root2) << std::endl;
    return 0;
}
