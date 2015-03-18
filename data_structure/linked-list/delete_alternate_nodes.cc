#include <iostream>
#include "linkedlist.h"

void remove_alt(Node<int> *head)
{
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node<int> *t = head->next;
    head->next = t->next;
    delete t;

    remove_alt(head->next);
}

void remove_alt_iterative(Node<int> *head)
{
    if (head == nullptr) {
        return;
    }

    Node<int> *prev = head, *curr = head->next;
    while (prev != nullptr && curr != nullptr) {
        prev->next = curr->next;

        delete curr;

        prev = prev->next;
        if (prev != nullptr) {
            curr = prev->next;
        }
    }
}

int main()
{
    auto head1 = build_linked_list(10);
    remove_alt(head1);
    print_list(head1);

    auto head2 = build_linked_list(10);
    remove_alt_iterative(head2);
    print_list(head2);

    return 0;
}
