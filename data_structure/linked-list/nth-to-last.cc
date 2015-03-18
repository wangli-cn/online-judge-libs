#include <iostream>
#include "linkedlist.h"

Node<int> *nth_to_last(Node<int> *head, int k)
{
    if (head == nullptr || k < 1) return nullptr;

    Node<int> *p1 = head, *p2 = head;
    for (int j = 0; j < k-1; ++j) {
        if (p2 == nullptr) return nullptr;
        p2 = p2->next;
    }

    while (p2->next != nullptr) {
        p1 = p1->next;
        p2 = p2->next;
    }

    return p1;
}

int main()
{
    auto head = build_linked_list();
    Node<int> *target = nth_to_last(head, 3);
    std::cout << target->val << std::endl;

    return 0;
}
