#include <iostream>

struct Node
{
    Node *next;
    int val;
};


Node *find_mid(Node *head)
{

}

Node *reverse(Node *head)
{

}

Node *merge(Node *l1, Node *l2)
{
    if (l1 == NULL && l2 == NULL) return NULL;
    if (l1 != NULL && l2 == NULL) return l1;
    if (l1 == NULL && l2 != NULL) return l2;

    Node *head = l1;
    head->next = l2;

    l2->next = merge(l1->next, l2->next);
    return head;
}


Node *intersperse_reverse(Node *head)
{
    Node *mid = find_mid(head);
    Node *rmid = reverse(mid);

    Node *new_head = merge(head, rmid);
    return new_head;
}

int main()
{
    return 0;
}
