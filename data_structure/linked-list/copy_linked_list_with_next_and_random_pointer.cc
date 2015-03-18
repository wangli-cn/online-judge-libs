//There is a doubly linked list with next pointer and random pointer (points to an arbitrary node in list). You have to make a copy of the linked list and return. In the end original list shouldn't be modified. Time complexity should be O(n).

#include <iostream>

struct Node
{
    Node(const Node &t) :random(nullptr), next(nullptr), val(t.val) {}
    Node *random;
    Node *next;
    int val;
};

Node *copy_list(Node *head)
{
    Node *curr = head;

    while (curr != nullptr) {
        Node *t = new Node(*curr);
        t->next = curr->next;
        Node *next = curr->next;
        curr->next = t;
        curr = next;
    }

    Node *res = head->next;

    curr = head;
    while (curr != nullptr) {
        curr->next->random = curr->random->next;
        curr = curr->next->next;
    }

    curr = head;
    Node *copied = head->next;
    while (curr != nullptr && copied != nullptr) {
        curr->next = curr->next->next;
        curr = curr->next;

        if (copied != nullptr) {
            copied->next = copied->next->next;
            copied = copied->next;
        }
    }

    return res;
}


int main()
{
    return 0;
}

