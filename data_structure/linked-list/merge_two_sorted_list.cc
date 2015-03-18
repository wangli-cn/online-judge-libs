//============================================================================
// Merge two sorted linked lists and return it as a new list. The new list
// should be made by splicing together the nodes of the first two lists.
//============================================================================

#include <iostream>
#include "linkedlist.h"

Node<int> *merge(Node<int> *l1, Node<int> *l2)
{
    Node<int> *head = nullptr, *tail = nullptr;
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
            if (head == nullptr) {
                head = l1;
                tail = head;
            } else {
                tail->next = l1;
                tail = tail->next;
            }

            l1 = l1->next;
        } else {
            if (head == nullptr) {
                head = l2;
                tail = head;
            } else {
                tail->next = l2;
                tail = tail->next;
            }

            l2 = l2->next;
        }
    }

    if (l1 == nullptr) {
        if (head == nullptr) head = l2;
        else tail->next = l2;
    } else if (l2 == nullptr) {
        if (head == nullptr) head = l1;
        else tail->next = l1;
    }

    return head;
}

int main()
{
    auto head1 = build_linked_list(10);
    auto head2 = build_linked_list(2);

    auto res = merge(head1, head2);
    print_list(res);

    return 0;
}
