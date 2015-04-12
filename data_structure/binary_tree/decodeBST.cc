#include <iostream>
#include <limits>
#include "binarytree.h"

void go(int l, int r, int &val, Node<int> *p, istream &in)
{

    if (l < val && val < r) {
        p = new Node<int>(val);

        int num;
        if (in >> num) {
            go(l, val, num, p->left, in);
            go(val, r, num, p->right, in);
        }
    }
}

void decode(Node<int> *root, istrean &in)
{
    int val;
    in >> val;

    go(std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), val, root, in);
}

int main()
{
    return 0;
}
