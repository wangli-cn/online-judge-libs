#include <iostream>
#include <limits>
#include "linkedlist.h"

Node<int> *swap_pairs(Node<int> *head)
{
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) return head;

    Node<int> *sentinel = new Node<int>(std::numeric_limits<int>::max());
    sentinel->next = head;

    Node<int> *pre = sentinel, *curr = head, *next = head->next;
    while (curr != nullptr && next != nullptr) {
        Node<int> *nextnext = next->next;

        pre->next = next;
        next->next = curr;
        curr->next = nextnext;

        pre = curr;
        curr = (curr != nullptr) ? curr->next : nullptr;
        next = (curr != nullptr) ? curr->next : nullptr;
    }

    Node<int> *p = sentinel->next;
    delete sentinel;

    return p;
}

int main(void)
{
    auto head = build_linked_list();
    print_list(head);
    auto swapped = swap_pairs(head);
    print_list(swapped);

    return 0;
}
