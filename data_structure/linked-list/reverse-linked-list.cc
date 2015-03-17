#include <iostream>

using namespace std;

#define REP(i,n) for (int i = 0; i < (int)n; ++i)

struct Node
{
    Node(int data) :next(NULL), data(data) {}

    Node *next;
    int data;
};

Node *reverse(Node *curr)
{
    if (curr->next == NULL) return curr;

    Node *head = reverse(curr->next);
    curr->next->next = curr;
    curr->next = NULL;
    return head;
}

void release(Node *curr)
{
    if (curr != NULL) {
        release(curr->next);
        delete curr;
    }
}

int main(void)
{
    Node *head = NULL, *tail = NULL;

    REP(i, 10) {
        Node *curr = new Node(i);

        if (head == NULL) {
            head = tail = curr;
        } else {
            tail->next = curr;
            tail = tail->next;
        }
    }

    head = reverse(head);
    Node *p = head;

    while (p != NULL) {
        cout << p->data << endl;
        p = p->next;
    }

    return 0;
}
