#include <iostream>

using namespace std;

struct Node
{
    Node *next;
    int value;
};

Node *bubble_sort(Node *head, int cnt)
{
    Node *p0, *p1, *p2, *p3;
    bool swapped;

    do {
        cnt -= 1;
        swapped = false;
        p0 = NULL; p1 = head;
        p2 = head->next; p3 = p2->next;

        if (p1->value > p2->value) {
            p1->next = p3;
            p2->next = p1;
            if (p0 != NULL) p0->next = p2;

            if (head == p1) head = p2;

            p0 = p2;
            p2 = p1->next;
            p3 = (p3->next != NULL) ? p3->next : NULL;
        } else {
            p0 = p1; p1 = p2; p2 = p3;
            p3 = (p3->next != NULL) ? p3->next : NULL;
        }
    } while (swapped);
}


int main()
{
    return 0;
}
