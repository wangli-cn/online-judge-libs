//============================================================================
// Merge k sorted linked lists and return it as one sorted list.
// Analyze and describe its complexity.
//============================================================================

#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    Node(int x) :val(x), next(nullptr) {}
    int val;
    Node *next;
};

struct greater_node
{
    bool operator()(const Node *a, const Node *b) {
        return a->val > b->val;
    }
};

Node *merge(vector<Node *> &lists)
{
    priority_queue<Node *, vector<Node *>, greater_node > min_heap;

    for (vector<Node *>::iterator it = lists.begin(); it != lists.end(); ++it) {
        if ((*it) != nullptr) min_heap.push(*it);
    }

    if (min_heap.empty()) return nullptr;

    Node *head = min_heap.top(); min_heap.pop();
    Node *tail = head;

    if (tail->next != nullptr) min_heap.push(tail->next);
    while (!min_heap.empty()) {
        tail->next = min_heap.top(); min_heap.pop();

        tail = tail->next;
        if (tail->next != nullptr) {
            min_heap.push(tail->next);
        }
    }

    return head;
}


int main()
{
    return 0;
}
