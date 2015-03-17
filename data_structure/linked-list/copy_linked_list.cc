#include <iostream>

using namespace std;


void copy_linked_list(Node *curr, Node **s)
{
    if (curr != NULL) {
        *s = (Node *)malloc(sizeof(Node));
        (*s)->value = curr->value;
        (*s)->next = NULL;
        copy_linked_list(curr->next, &((*s)->next));
    }
}

int main()
{
    return 0;
}
