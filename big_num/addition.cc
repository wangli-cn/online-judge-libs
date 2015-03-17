Node *add(NOde *l1, Node *l2, int carry)
{
    if (l1 == NULL && l2 == NULL) {
        return NULL;
    }

    Node *result = new Node(carry, NULL, NULL);
    int value = carry;
    if (l1 != NULL) value += l1->data;
    if (l2 != NULL) value += l2->data;

    result->data = value % 10;
    Node *more = add(l1 == NULL ? NULL : l1->next, l2 == NULL ? NULL : l2->next, value > 10 ? 1 : 0);
    result->next = more;
    return result;
}
