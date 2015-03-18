#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct Node
{
    Node *prev, *next;
};

int count_blocks(vector<Node *> &refs)
{
    int cnt = 0;
    unordered_set<Node *> S;

    for (auto curr:refs) {
        cnt += 1;

        if (S.find(curr->prev) != S.end()) cnt -= 1;
        if (S.find(curr->next) != S.end()) cnt -= 1;

        S.insert(curr);
    }

    return cnt;
}

int main()
{
    return 0;
}
