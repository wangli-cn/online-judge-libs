//============================================================================
// You are given two linked lists representing two non-negative numbers.
// The digits are stored in reverse order and each of their nodes contain a
// single digit. Add the two numbers and return it as a linked list.
//
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
//============================================================================

#include <iostream>
#include "../linked-list/linkedlist.h"


Node<int> *add(Node<int> *l1, Node<int> *l2, int carry)
{
    if (l1 == nullptr && l2 == nullptr) {
        return nullptr;
    }

    Node<int> *result = new Node<int>(carry);
    int value = carry;
    if (l1 != nullptr) value += l1->val;
    if (l2 != nullptr) value += l2->val;

    result->val = value % 10;
    Node<int> *more = add(l1 == nullptr ? nullptr : l1->next, l2 == nullptr ? nullptr : l2->next, value > 10 ? 1 : 0);
    result->next = more;
    return result;
}

int main()
{
    return 0;
}
