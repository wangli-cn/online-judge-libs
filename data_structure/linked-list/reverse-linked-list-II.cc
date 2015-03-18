//============================================================================
// Reverse a linked list from position m to n. Do it in-place and in one-pass.
//
// For example:
// Given 1->2->3->4->5->NULL, m = 2 and n = 4,
//
// return 1->4->3->2->5->NULL.
//
// Note:
// Given m, n satisfy the following condition:
// 1 ≤ m ≤ n ≤ length of list.
//============================================================================

#include <iostream>
#include <limits>
#include "linkedlist.h"

using namespace std;

Node<int> *reverse(Node<int> *head)
{
    if (nullptr == head) return nullptr;
    if (nullptr == head->next) return head;

    Node<int> *next = head->next;
    Node<int> *new_head = reverse(head->next);
    next->next = head;
    head->next = nullptr;

    return new_head;
}

Node<int> *reverse_between(Node<int> *head, int m, int n)
{
    if (m >= n) return head;
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) return head;

    Node<int> *sentinel = new Node<int>(std::numeric_limits<int>::max());
    sentinel->next = head;

    Node<int> *sub_tail = sentinel;
    for (int i = 1; i <= n; i++) {
        sub_tail = sub_tail->next;
    }
    Node<int> *next_sub_tail = sub_tail->next;

    Node<int> *pre_sub_head = sentinel;
    for (int i = 1; i <= m-1; i++) {
        pre_sub_head = pre_sub_head->next;
    }
    Node<int> *sub_head = pre_sub_head->next;

    sub_tail->next = nullptr;
    pre_sub_head->next = reverse(sub_head);
    sub_head->next = next_sub_tail;

    Node<int> *p = sentinel->next;
    delete sentinel;
    return p;
}

int main(void)
{
    auto head = build_linked_list();
    head = reverse_between(head, 1, 5);
    print_list(head);

    return 0;
}
