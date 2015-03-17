#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    Node *l, *r;
    int value;
};

Node *build_tree(vector<int>::iterator begin, vector<int>::iterator end, vector<int> &postorder)
{
    if (postorder.empty()) return NULL;

    vector<int>::iterator it = find(begin, end, postorder.back());
    if (it == end) return NULL;

    int value = postorder.back(); postorder.pop_back();

    Node *root = new Node;
    root->value = value;
    root->l = build_tree(begin, it, postorder);
    root->r = build_tree(it+1, end, postorder);
}


int main(void)
{
    return 0;
}
