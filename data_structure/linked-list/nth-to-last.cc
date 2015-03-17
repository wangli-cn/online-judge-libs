Node *nth_to_last(Node *head, int k)
{
    if (head == NULL || k < 1) return NULL;

    Node *p1 = head, *p2 = head;
    for (int j = 0; j < n-1; ++j) {
        if (p2 == NULL) return NULL;
        p2 = p2->next;
    }

    while (p2->next != NULL) {
        p1 = p1->next;
        p2 = p2->next;
    }

    return p1;
}

int main()
{
    return 0;
}
