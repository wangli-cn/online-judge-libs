#include <cstdlib>
#include <cstdio>
#include <climits>

using namespace std;

#define SKIPLIST_MAX_LEVEL 6

struct Node
{
    typedef Node *NodePtr;
    Node(int key, int value, int size) :key(key), value(value) {
        forward = new NodePtr[size+1];
    }

    ~Node() {
        if (forward != NULL) delete[] forward;
    }

    int key;
    int value;
    Node **forward;
};


struct SkipList
{
    SkipList()
    {
        header = new Node(INT_MAX, INT_MAX, SKIPLIST_MAX_LEVEL);
        for (int i = 0; i <= SKIPLIST_MAX_LEVEL; i++) {
            header->forward[i] = header;
        }

        level = 1;
        size = 0;
    }

    bool insert(int key, int value)
    {
        Node *update[SKIPLIST_MAX_LEVEL+1];
        Node *x = header;

        for (int i = level; i >= 1; i--) {
            while (x->forward[i]->key < key)
                x = x->forward[i];
            update[i] = x;
        }
        x = x->forward[1];

        if (key == x->key) {
            x->value = value;
            return true;
        } else {
            int l = rand_level();
            if (l > level) {
                for (int i = level+1; i <= l; i++) {
                    update[i] = header;
                }
                level = l;
            }

            x = new Node(key, value, l);
            for (int i = 1; i <= l; i++) {
                x->forward[i] = update[i]->forward[i];
                update[i]->forward[i] = x;
            }
        }

        return true;
    }

    Node *search(int key)
    {
        Node *x = header;
        for (int i = level; i >= 1; i--) {
            while (x->forward[i]->key < key)
                x = x->forward[i];
        }

        if (x->forward[1]->key == key) {
            return x->forward[1];
        } else {
            return NULL;
        }
    }

    bool remove(int key)
    {
        Node *update[SKIPLIST_MAX_LEVEL + 1];
        Node *x = header;

        for (int i = level; i >= 1; i--) {
            while (x->forward[i]->key < key)
                x = x->forward[i];
            update[i] = x;
        }

        x = x->forward[1];
        if (x->key == key) {
            for (int i = 1; i <= level; i++) {
                if (update[i]->forward[i] != x)
                    break;
                update[i]->forward[i] = x->forward[i];
            }

            delete x;

            while (level > 1 && header->forward[level] == header) level--;

            return true;
        } else {
            return false;
        }
    }

    void dump()
    {
        Node *x = header;
        while (x && x->forward[1] != header) {
            printf("%d[%d]->", x->forward[1]->key, x->forward[1]->value);
            x = x->forward[1];
        }
        printf("NIL\n");
    }

    int rand_level()
    {
        int l = 1;
        while (rand() < RAND_MAX/2 && l < SKIPLIST_MAX_LEVEL) l++;
        return l;
    }

    int level;
    int size;
    Node *header;
};



int main()
{
    int arr[] = {3, 6, 9, 2, 11, 1, 4};
    SkipList l;

    printf("Insert:--------------------\n");
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        l.insert(arr[i], arr[i]);
    }
    l.dump();


    printf("Search:--------------------\n");
    int keys[] = {3, 4, 7, 10, 111};

    for (int i = 0; i < sizeof(keys)/sizeof(keys[0]); i++) {
        Node *x = l.search(keys[i]);

        if (x) {
            printf("key = %d, value = %d\n", keys[i], x->value);
        } else {
            printf("key = %d, not fuound\n", keys[i]);
        }
    }

    printf("Search:--------------------\n");
    l.remove(1);
    l.dump();

    return 0;
}
