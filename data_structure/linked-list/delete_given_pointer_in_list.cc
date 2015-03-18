//Given only a pointer to a node to be deleted in a singly linked list, how do you delete it?
//This solution doesn’t work if the node to be deleted is the last node of the list
#include <iostream>

void remove(Node *given)
{
    Node *t = given->next;
    given->val = t->val;
    given->next = t->next;
    delete t;
}
