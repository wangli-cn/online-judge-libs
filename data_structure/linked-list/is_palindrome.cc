#include <iostream>
#include "linkedlist.h"

using namespace std;

bool compare(Node<int> *a, Node<int> *b)
{
    while (a != nullptr && b != nullptr) {
        if (a->val != b->val) {
            return false;
        }

        a = a->next;
        b = b->next;
    }

    return true;
}

Node<int> *reverse(Node<int> *head)
{
    if (head->next == nullptr) return head;

    Node<int> *next = head->next;
    Node<int> *t = reverse(next);
    next->next = head;
    head->next = nullptr;

    return t;
}

bool is_palindrome(Node<int> *head)
{
    Node<int> *slow = head, *fast = head;
    Node<int> *mid = nullptr;
    Node<int> *second_half = nullptr, *prev_of_slow = head;
    bool res = false;

    if (head != nullptr) {
        while (fast != nullptr && fast->next != nullptr) {
            prev_of_slow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast != nullptr) {
            mid = slow;
            slow = slow->next;
        }

        second_half = slow;
        prev_of_slow->next = nullptr;
        second_half = reverse(second_half);

        res = compare(head, second_half);

        second_half = reverse(second_half);
        if (mid != nullptr) {
            prev_of_slow->next = mid;
            mid->next = second_half;
        } else {
            prev_of_slow->next = second_half;
        }
    }

    return res;
}

int main()
{
    return 0;
}
