//============================================================================
// Rotate List
// Given a list, rotate the list to the right by k places, where k is
// non-negative.
//
// For example:
// Given 1->2->3->4->5->nullptr and k = 2,
// return 4->5->1->2->3->nullptr.
//============================================================================

#include <iostream>
#include "linkedlist.h"

Node<int> *rotate(Node<int> *head, int k)
{
    if (head == nullptr || head->next == nullptr) return head;

    Node<int> *curr = head;

    int n = 0;
    while (curr != nullptr) curr = curr->next, n++;
    k = k % n;

    if (k == 0) return head;

    Node<int> *fast = head;
    int i = 0;
    while (fast != nullptr) fast = fast->next, i++;

    Node<int> *slow = head;
    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    fast->next = head;
    head = slow->next;
    slow->next = nullptr;
    return head;
}

int main()
{
    auto head = build_linked_list();
    Node<int> *target = rotate(head, 3);
    print_list(target);

    return 0;
}
