#include <iostream>
#include "linkedlist.h"

Node<int> *find_beginning(Node<int> *head)
{
    Node<int> *r1 = head, *r2 = head;

    while (r2->next != nullptr) {
        r1 = r1->next;
        r2 = r2->next->next;

        if (r1 == r2) {
            break;
        }
    }

    if (r2 == nullptr || r2->next == nullptr) return nullptr;

    r1 = head;
    while (r1 != r2) {
        r1 = r1->next;
        r2 = r2->next;
    }

    return r2;
}

int main(void)
{
    auto head = build_linked_list();

    print_list(head);
    auto target = find_beginning(head);

    if (target == nullptr) {
        std::cout << "not found" << std::endl;
    } else {
        std::cout << target->val << std::endl;
    }

    return 0;
}
