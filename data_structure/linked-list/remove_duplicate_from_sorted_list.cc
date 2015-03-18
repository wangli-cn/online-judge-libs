
struct Node {
    Node(int x) :data(x), next(nullptr) {}

    int data;
    Node *next;
}


Node *remove_duplicates(Node *head)
{
    if (nullptr == head) return nullptr;

    Node *curr = head;

    while (nullptr != curr->next) {
        if (curr->data == curr->next->data) {
            Node *next = curr->next;
            curr->next = next->next;
            delete next;
        } else {
            curr = curr->next;
        }
    }

    return head;
}

int main(void)
{
    return 0;
}
