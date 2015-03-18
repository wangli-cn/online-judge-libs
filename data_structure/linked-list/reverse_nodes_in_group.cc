//============================================================================
// Reverse Node<int>s in k-Group
// Given a linked list, reverse the nodes of a linked list k at a time and
// return its modified list.
//
// If the number of nodes is not a multiple of k then left-out nodes in the
// end should remain as it is.
//
// You may not alter the values in the nodes, only nodes itself may be
// changed.
//
// Only constant memory is allowed.
//
// For example,
// Given this linked list: 1->2->3->4->5
//
// For k = 2, you should return: 2->1->4->3->5
//
// For k = 3, you should return: 3->2->1->4->5
//============================================================================

#include <iostream>
#include "linkedlist.h"

using namespace std;

bool enough_to_reverse(Node<int> *head, int k)
{
    if (k == 1 && head != nullptr) return true;
    else if (head == nullptr) return false;
    else return enough_to_reverse(head->next, k-1);
}

Node<int> *reverse_k(Node<int> *head, int k, Node<int> **next_head)
{
    if (k == 1) {
        *next_head = head->next;
        return head;
    }

    if (nullptr == head) {
        *next_head = nullptr;
        return nullptr;
    }

    if (nullptr == head->next) {
        *next_head = nullptr;
        return head;
    }

    Node<int> *next = head->next;
    Node<int> *new_head = reverse_k(head->next, k-1, next_head);
    next->next = head;
    head->next = nullptr;

    return new_head;
}

Node<int> *reverse_in_group(Node<int> *head, int k)
{
    Node<int> *p = head;

    Node<int> *sentinel = new Node<int>(std::numeric_limits<int>::max());
    sentinel->next = head;
    Node<int> *temp;

    Node<int> *pre_head = sentinel;
    while (p != nullptr) {
        Node<int> **next_head = &temp;

        if (!enough_to_reverse(p, k)) break;

        Node<int> *t = reverse_k(p, k, next_head);
        pre_head->next = t;

        pre_head = p;
        p->next = *next_head;
        p = p->next;
    }

    return sentinel->next;
}

Node<int> *reverse_in_group_recursive(Node<int> *head, int k)
{
    Node<int> *curr = head;
    Node<int> *next = nullptr, *prev = nullptr;
    int cnt = 0;

    while (curr != nullptr && cnt < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt += 1;
    }

    if (next != nullptr) {
        head->next = reverse_in_group_recursive(next, k);
    }

    return prev;
}

int main(void)
{
    auto head = build_linked_list();

    print_list(head);

    head = reverse_in_group_recursive(head, 3);
    print_list(head);

    return 0;
}
