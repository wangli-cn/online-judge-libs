//Write a function to get the intersection point of two Linked Lists.

#include <iostream>
#include "linkedlist.h"

int len(Node<int> *head)
{
    int l = 0;
    while (head != nullptr) {
        l += 1;
        head = head->next;
    }

    return l;
}

Node<int> *go(int diff, Node<int> *l1, Node<int> *l2)
{
    for (int i = 0; i < diff; i++) {
        l1 = l1->next;
    }

    while (l1 != nullptr && l2 != nullptr) {
        if (l1 == l2) return l1;

        l1 = l1->next;
        l2 = l2->next;
    }

    return nullptr;
}

Node<int> *list_intersection(Node<int> *l1, Node<int> *l2)
{
    int len_l1 = len(l1), len_l2 = len(l2);

    if (len_l1 > len_l2) {
        int diff = len_l1 - len_l2;
        return go(diff, l1, l2);
    } else {
        int diff = len_l2 - len_l1;
        return go(diff, l2, l1);
    }
}

int main()
{
    auto head = build_linked_list();

    return 0;
}
