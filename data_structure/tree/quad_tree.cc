//uva 297
#include <iostream>
#include <algorithm>

using namespace std;

enum State
{
    EMPTY,
    FULL,
    PARENT
};

struct Node
{
    Node(State val) :val(val) { fill(children, children+4, (Node *)NULL); }
    State val;
    Node *children[4];
};


Node *build_tree(Node *root, string &s, int pos)
{
    if (pos == s.length()) {
        return NULL;
    }

    switch (s[pos]) {
        case 'e':
            root = new Node(EMPTY);
            break;
        case 'f':
            root = new Node(FULL);
            break;
        case 'p':
            root = new Node(PARENT);
            for (int i = 0; i < 4; i++) {
                if (root->children[i] == NULL) {
                    root->children[i] = build_tree(root->children[i], s, pos);
                }
            }

            break;
    }

    return root;
}

int main()
{
    return 0;
}
