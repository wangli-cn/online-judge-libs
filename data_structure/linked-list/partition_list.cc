//============================================================================
// Partition List
// Given a linked list and a value x, partition it such that all nodes less
// than x come before nodes greater than or equal to x.
//
// You should preserve the original relative order of the nodes in each of the
// two partitions.
//
// For example,
// Given 1->4->3->2->5->2 and x = 3,
// return 1->2->2->4->3->5.
//============================================================================

#include <iostream>

using namespace std;

struct Node
{
    Node(int x) :val(x) {}
    int val;
    Node *next;
};

Node *partition(Node *head, int x)
{
    Node *front_head = nullptr, *front_tail = nullptr;
    Node *back_head = nullptr, *back_tail = nullptr;

    while (head != nullptr) {
        if (head->val < x) {
            if (front_head == nullptr) {
                front_head = head;
                front_tail = head;
            } else {
                front_tail->next = head;
                front_tail = front_tail->next;
            }
        } else {
            if (back_head == nullptr) {
                back_head = head;
                back_tail = head;
            } else {
                back_tail->next = head;
                back_tail = back_tail->next;
            }
        }

        head = head->next;
    }

    if (front_tail != nullptr) front_tail->next = back_head;
    if (back_tail != nullptr) back_tail->next = nullptr;
    if (front_head == nullptr) return back_head;
    return front_head;
}


int main()
{
    return 0;
}
