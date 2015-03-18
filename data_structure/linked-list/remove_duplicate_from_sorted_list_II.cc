//============================================================================
// Remove Duplicates from Sorted List II
// Given a sorted linked list, delete all nodes that have duplicate numbers,
// leaving only distinct numbers from the original list.
//
// For example,
// Given 1->2->3->3->4->4->5, return 1->2->5.
// Given 1->1->1->2->3, return 2->3.
//============================================================================

struct Node {
    Node(int x) :data(x), next(nullptr) {}

    int data;
    Node *next;
}


Node *remove_duplicates(Node *head)
{
    if (nullptr == head || nullptr == head->next) return nullptr;

    Node *curr = head, next = nullptr;
    Node *new_head = nullptr, *new_curr = nullptr;

    while (curr != nullptr) {
        bool found = false;
        while (curr->data == curr->next->data) {
            next = curr->next;
            delete curr;
            curr = next;
            found = true;
        }

        if (found) {
            next = curr->next;
            delete curr;
            curr = next;
        } else {
            if (new_head == nullptr) {
                new_head = curr;
                new_curr = curr;
                curr = curr->next;
            } else {
                new_curr->next = curr;
                new_curr = new_curr->next;
                curr = curr->next
            }
        }
    }

    if (new_curr != nullptr) new_curr->next = nullptr;

    return new_head;
}
