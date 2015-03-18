//============================================================================
// Remove Nth Node From End of List
// Given a linked list, remove the nth node from the end of list and return
// its head.
//
// For example,
//
// Given linked list: 1->2->3->4->5, and n = 2.
//
// After removing the second node from the end, the linked list becomes
// 1->2->3->5.
// Note:
// Given n will always be valid.
// Try to do this in one pass.
//============================================================================

#include <iostream>

using namespace std;

struct Node
{
    Node(int x) :val(x) {}

    int val;
    Node *next;
};

Node *remove_nth_to_last(Node *head, int k)
{
    Node *fast = head, *slow = head;
    for (int i = 1; i <= k; i++) {
        if (fast == NULL) return head;
        fast = fast->next;
    }

    if (fast == NULL) {
        head = head->next;
        delete slow;
        return head;
    }

    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    Node *next = slow->next;
    slow->next = next->next;
    delete next;
    return head;
}

int main(void)
{
    Node *head = NULL, *tail = NULL;

    for (int i = 1; i <= 5; i++) {
        Node *curr = new Node(i);

        if (head == NULL) {
            head = tail = curr;
        } else {
            tail->next = curr;
            tail = tail->next;
        }
    }

    head = remove_nth_to_last(head, 3);
    Node *p = head;

    while (p != NULL) {
        cout << p->val << endl;
        p = p->next;
    }

    return 0;
}
