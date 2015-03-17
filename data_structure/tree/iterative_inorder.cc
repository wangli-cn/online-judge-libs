#include <iostream>

using namespace std;

struct Node 
{
    int data;
    Node *left, *right;
};

void iterative_inorder(Node *root)
{
    bool done = false;
    Node *curr = root;
    Stack<Node *> S;

    while (!done) {
        if (curr != NULL) {
            S.push(curr);
            curr = curr->left;
        } else {
            if (!S.empty()) {
                curr = S.top(); S.pop();
                cout << curr->data << endl;
                curr = curr->right;
            } else {
                done = true;
            }
        }
    }
}
