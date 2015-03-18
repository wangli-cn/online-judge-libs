#include <iostream>

using namespace std;

struct Node
{
    Node *prev, *next;
};

void reverse(Node *&head)
{
    Node *t = NULL, *curr = head;

    while (curr != NULL) {
        t = curr->prev;
        curr->prev = curr->next;
        curr->next = t;
        curr = curr->prev;
    }

    if (t != NULL) {
        head = t->prev;
    }
}

int main()
{
    return 0;
}
