#include <iostream>
#include "linkedlist.h"

void copy_linked_list(Node<int> *curr, Node<int> **s)
{
    if (curr != nullptr) {
        *s = new Node<int>(curr->val);
        copy_linked_list(curr->next, &((*s)->next));
    }
}

int main()
{
    static_assert(std::is_copy_constructible<int>::value, "int is not copy constructible");

    auto head = build_linked_list();
    Node<int> *new_head = nullptr;

    copy_linked_list(head, &new_head);
    print_list(head);
    print_list(new_head);
    return 0;
}
