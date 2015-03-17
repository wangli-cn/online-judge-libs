#include <iostream>

using namespace std;

struct Node 
{
    int data;
    Node *next;
};

Node *find_beginning(Node *head)
{
    Node *r1 = head;
    Node *r2 = head;

    while (r2->next != NULL) {
        r1 = r1->next;
        r2 = r2->next->next;

        if (r1 == r2) {
            break;
        }
    }

    if (r2->next == NULL) return NULL;

    r1 = head;
    while (r1 != r2) {
        r1 = r1->next;
        r2 = r2->next;
    }

    return r2;
}

int main(void)
{
    return 0;
}
