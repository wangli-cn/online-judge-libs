#include <iostream>

using namespace std;

struct SplayTree
{
    struct Node {
        int key;
        Node *left, *right;
        Node(int key = 0, Node *left = 0, Node *right = 0) 
            :key(key), left(left), right(right) {}
    } *root;

    Node *splay(int x, Node *t) {
        if (!t) return t;
        Node N, *l = &N, *r = &N, *s;
        while (1) {
            if (x < t->key) {
                if (t->left && x < t->left->key)
                    s = t->left, t->left = s->right, s->right = t, t = s;
                if (!t->left) 
                    break;
                r->left = t, r = t, t = t->left;
            } else if (x > t->key) {
                if (t->right && x > t->right->key) 
                    s = t->right, t->right = s->left, s->left = t, t = s;
                if (!t->right) 
                    break;
                l->right = t, l = t, t = t->right;
            } else {
                break;
            }
        }
        l->right = t->left; r->left = t->right;
        t->left = N.right; t->right = N.left;
        return t;
    }

    Node *find(int x) {
        root = splay(x, root);
        if (x == root->key) return root;
        else return 0;
    }

    void insert(int x) {
        if (!root) root = new Node(x);
        else {
            root = splay(x, root);
            if (x < root->key) {
                Node *t = new Node(x, root->left, root);
                root->left = 0; root = t;
            } else if (x > root->key) {
                Node *t = new Node(x, root, root->right);
                root->right = 0; root = t;
            }
        }
    }

    void erase(int x) {
        if (!find(x)) return;
        if (!root->left) root = root->right;
        else {
            Node *t = root->right;
            root = splay(x, root->left);
            root->right = t;
        }
    }

    SplayTree() :root(0) {}
};

int main(void)
{
    return 0;
}
