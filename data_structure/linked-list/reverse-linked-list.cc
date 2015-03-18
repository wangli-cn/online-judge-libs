#include <iostream>
#include "linkedlist.h"

using namespace std;

Node<int> *reverse(Node<int> *curr)
{
    if (curr->next == nullptr) return curr;

    Node<int> *head = reverse(curr->next);
    curr->next->next = curr;
    curr->next = nullptr;
    return head;
}

Node<int> *reverse_iterative(Node<int> *head)
{
    if (head == nullptr) return nullptr;

    Node<int> *prev = nullptr, *curr = head;
    while (curr != nullptr) {
        Node<int> *next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    return prev;
}

int main()
{
    auto head = build_linked_list();
    Node<int> *reversed = reverse(head);
    print_list(reversed);

    Node<int> *rreversed = reverse_iterative(reversed);
    print_list(rreversed);

    return 0;
}
