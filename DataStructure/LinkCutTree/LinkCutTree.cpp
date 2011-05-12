#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef int Weight;

#define DEBUG

struct Node 
{
    int ID;
    Node *left, *right;
    Node *parent;
    Node *path_parent;

    Node(int ID, Node *left = NULL, Node *right = NULL, Node *parent = NULL, Node *path_parent = NULL)
        : ID(ID), left(left), right(right), parent(parent), path_parent(path_parent) {}
};

int N, M;
Node *trees[50005];

void print_tree()
{
#ifdef DEBUG
    printf("\n ---------- start ---------- \n");
    for (int i = 1; i <= N; i++) {
        if (trees[i]->parent != NULL && trees[i]->path_parent == NULL) {
            printf("%d --> %d\n", i, trees[i]->parent->ID);
        } else if (trees[i]->path_parent != NULL && trees[i]->parent == NULL) {
            printf("%d ... %d\n", i, trees[i]->path_parent->ID);
        } else if (trees[i]->parent == NULL && trees[i]->path_parent == NULL) {
            printf("%d --> NULL\n", i);
        } else {
            printf("Error\n");
        }
    }
    printf(" ----------- end ----------- \n\n");
#endif
}


Node *MAKE_TREE(int ID)
{
    Node *t = new Node(ID);
    return t;
}

Node *LEFT_ROTATE(Node *x)
{
    Node *y = x->right;
    x->right = y->left;

    if (y->left != NULL)
        y->left->parent = x;

    y->parent = x->parent;
    y->path_parent = x->path_parent;
    if (x->parent == NULL) {

    } else if (x == x->parent->left) {
        x->parent->left = y;   
    } else if (x == x->parent->right) {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
    x->path_parent = NULL;
    return y;
}

Node *RIGHT_ROTATE(Node *x)
{
    Node *y = x->left;
    x->left = y->right;

    if (y->right != NULL)
        y->right->parent = x;

    y->parent = x->parent;
    y->path_parent = x->path_parent;
    if (x->parent == NULL) {

    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    }

    y->right = x;
    x->parent = y;
    x->path_parent = NULL;
    return y;
}

Node *SPLAY(Node *v)
{
    if (v == NULL) {
        return v;
    }

    while (v->parent != NULL) {
        Node *p  = v->parent;
        if (p->left == v) {
            if (p->parent != NULL) {
                Node *pp = p->parent;

                if (pp->left == p) {
                    //zig zig
                    RIGHT_ROTATE(pp);
                    v = RIGHT_ROTATE(p);
                } else if (pp->right == p) {
                    //zig zag
                    RIGHT_ROTATE(p);
                    v = LEFT_ROTATE(pp);
                }
            } else {
                //single rotation
                v = RIGHT_ROTATE(p);
            }
        } else if (p->right == v) {
            if (p->parent != NULL) {
                Node *pp = p->parent;

                if (pp->left == p) {
                    //zig zag
                    LEFT_ROTATE(p);
                    v = RIGHT_ROTATE(pp);
                } else if (pp->right == p) {
                    //zig zig
                    LEFT_ROTATE(pp);
                    v = LEFT_ROTATE(p);
                }
            } else {
                //single rotation
                v = LEFT_ROTATE(p);
            }
        } 
    }
}

void EXPOSE(Node *v)
{
    SPLAY(v);

    if (v->right != NULL) {
        v->right->path_parent = v;
        v->right->parent = NULL;
        v->right = NULL;
    }

    Node *t = v;
    while (t->path_parent != NULL) {
        Node *w = t->path_parent;
        SPLAY(w);

        //switch
        if (w->right != NULL) {
            w->right->path_parent = w;
            w->right->parent = NULL;
        }

        w->right = t;
        t->parent = w;
        t->path_parent = NULL;

        t = w;
    }

    SPLAY(v);
}

Node *FIND_ROOT(Node *v)
{
    EXPOSE(v);

    Node *t = v;
    while (t->left != NULL) 
        t = t->left;

    SPLAY(t);
    return t;
}

void LINK(Node *v, Node *w)
{
    EXPOSE(v);
    EXPOSE(w);

    v->left = w;
    w->parent = v;
    w->path_parent = NULL;
}

void CUT(Node *v)
{
    EXPOSE(v);

    if (v->left != NULL) {
        v->left->parent = NULL;
        v->left->path_parent = NULL;
        v->left = NULL;
    }
}

Node *NCA(Node *v, Node *w)
{
    Node *r1 = FIND_ROOT(v);
    Node *r2 = FIND_ROOT(w);

    if (r1 != r2) 
        return NULL;
    
    Node *nca = NULL;
    EXPOSE(v);
    
    SPLAY(w);

    if (w->right != NULL) {
        w->right->path_parent = w;
        w->right->parent = NULL;
        w->right = NULL;
    }

    if (w->path_parent == NULL) {
        nca = w;
    }

    Node *t = w;
    while (t->path_parent != NULL) {
        Node *x = t->path_parent;
        SPLAY(x);

        if (x->path_parent == NULL) {
            nca = x;
        }

        //switch
        if (x->right != NULL) {
            x->right->path_parent = x;
            x->right->parent = NULL;
        }

        x->right = t;
        t->parent = x;
        t->path_parent = NULL;

        t = x;
    }

    SPLAY(w);
    return nca;
}

int main(void)
{
    int a, b;
    char command[8];

    int nCase = 1;
    while (scanf("%d", &N) == 1) {
        if (nCase > 1) printf("\n");
        nCase++;

        for (int i = 1; i <= N; i++) {
            trees[i] = MAKE_TREE(i);
        }

        for (int i = 1; i <= N; i++) {
            scanf("%d ", &a);
            if (a > 0) {
                LINK(trees[i], trees[a]);
            }
        }
            
        //print_tree();

        scanf("%d", &M);
        for (int i = 0; i < M; i++) {
            scanf("%s ", command);
            if (strcmp(command, "QUERY") == 0) {
                scanf("%d", &a);
                //printf("%s %d\n", command, a);

                Node *t = FIND_ROOT(trees[a]);
                printf("%d\n", t->ID);
            } else if (strcmp(command, "MOVE") == 0) {
                scanf("%d %d", &a, &b);
                //printf("%s %d %d\n", command, a, b);
    
                if (a == 0) {
                    continue;
                }

                //detect illegal commnad
                if (a > 0 && b > 0) {
                    Node *nca = NCA(trees[a], trees[b]);
                    if (nca != NULL && (nca == trees[a])) {
                        //printf("is illegal\n");
                        continue;
                    }
                }

                CUT(trees[a]);
                if (b > 0) {
                    LINK(trees[a], trees[b]);
                }
            }

            //print_tree();
            //fflush(stdout);
        }

        for (int i = 1; i <= N; i++) {
            delete trees[i];
        }
    }

    return 0;
}
