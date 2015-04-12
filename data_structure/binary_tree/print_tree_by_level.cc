#include <iostream>
#include <vector>
#include <queue>

struct Node
{
    int data;
    vector<Node *> children;
};

void print_tree(Node *root)
{
    queue<Node *> Q;
    int current_level_counter, next_level_counter;

    Q.push(root);
    current_level_counter = 1;
    next_level_counter = 0;

    while (!Q.empty()) {
        Node *nd = Q.front(); Q.pop();

        current_level_counter -= 1;
        cout << nd->data << " ";

        for (int i = 0; i < nd->children.size(); i++) {
            Q.push(nd->children[i]);
            next_level_counter += 1;
        }

        if (current_level_counter == 0) {
            current_level_counter = next_level_counter;
            next_level_counter = 0;
            cout << endl;
        }
    }
}
