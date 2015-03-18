#include <iostream>
#include "linkedlist.h"

void sorted_insert(Node<int> *&head, Node<int> *to_insert)
{
    if (head == nullptr || head->val >= to_insert->val) {
        to_insert->next = head;
        head = to_insert;
    } else {
        Node<int> *curr = head;
        while (curr->next != nullptr && curr->next->val < to_insert->val) {
            curr = curr->next;
        }

        to_insert->next = curr->next;
        curr->next = to_insert;
    }
}

int main()
{
    auto head = build_linked_list();

    return 0;
}
