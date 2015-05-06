#include <iostream>
#include <vector>
#include "utils/binary_tree.h"

using namespace std;

struct ListNode
{
    ListNode(int x) :val(x) {}
    int val;
    ListNode *next;
};

std::unique_ptr<Node<int> > convert_list(ListNode *&head, int start, int end)
{
    if (start > end) return nullptr;

    int mid = start + (end - start) / 2;

    std::unique_ptr<Node<int> > left_subtree = convert_list(head, start, mid-1);
    std::unique_ptr<Node<int> > root(new Node<int>(head->val));

    root->left = std::move(left_subtree);
    head = head->next;
    root->right = convert_list(head, mid+1, end);

    return std::move(root);
}

int main()
{
    std::unique_ptr<Node<int> > root = build_binary_tree();

    return 0;
}
