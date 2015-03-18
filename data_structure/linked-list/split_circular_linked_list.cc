#include <iostream>

using namespace std;

struct Node
{
    Node(int val) :next(NULL), val(val) {}
    Node *next;
    int val;
};

typedef Node *NodePtr;

pair<NodePtr, NodePtr> split(Node *head)
{
    if (head == NULL) {
        pair<NodePtr, NodePtr> p = make_pair((Node *)NULL, (Node *)NULL);
        return p;
    }

    Node *slow = head, *fast = head;
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast->next->next == head) {
        fast = fast->next;
    }

    Node *head1 = NULL, *head2 = NULL;

    head1 = head;

    if (head->next != head) {
        head2 = slow->next;
    }

    fast->next = slow->next;
    slow->next = head;

    return make_pair(head1, head2);
}

void push_front(Node *&head, int val)
{
    Node *p = new Node(val);
    p->next = head;

    Node *t = head;

    if (head != NULL) {
        while (t->next != head) {
            t = t->next;
        }
        t->next = p;
    } else {
        p->next = p;
    }

    head = p;
}

void print_list(Node *head)
{
    if (head != NULL) {
        Node *t = head;
        do {
            cout << t->val << " ";
            t = t->next;
        } while (t != head);
        cout << endl;
    }
}

int main()
{
    Node *head = NULL;
    push_front(head, 12);
    push_front(head, 56);
    push_front(head, 2);
    push_front(head, 11);

    print_list(head);
    pair<NodePtr, NodePtr> np = split(head);

    print_list(np.first);
    print_list(np.second);

    return 0;
}
