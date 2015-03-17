Node *get_middle_of_list(Node *head)
{
    Node *p1 = head, *p2 = head;

    if (p2 != NULL) {
        while (p2->next != NULL && p2->next->next != NULL) {
            p1 = (p1 != NULL) ? p1->next : NULL;
            p2 = (p2 != NULL) ? p2->next : NULL;
            p2 = (p2 != NULL) ? p2->next : NULL;
        }
    }

    return p1;
}
