#include <iostream>
#include "linkedlist.h"

Node<int> *get_middle_of_list(Node<int> *head)
{
    Node<int> *p1 = head, *p2 = head;

    if (p2 != nullptr) {
        while (p2->next != nullptr && p2->next->next != nullptr) {
            p1 = (p1 != nullptr) ? p1->next : nullptr;
            p2 = (p2 != nullptr) ? p2->next : nullptr;
            p2 = (p2 != nullptr) ? p2->next : nullptr;
        }
    }

    return p1;
}

int main()
{
    auto head = build_linked_list(5);

    Node<int> *m = get_middle_of_list(head);
    std::cout << m->val << std::endl;

    return 0;
}
