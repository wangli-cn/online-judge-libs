#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

struct Node
{
    Node() {}
    vector<Node *> neighbors;
};

typedef unordered_map<Node *, Node *> hash_map;

Node *clone(Node *start)
{
    if (start == nullptr) return nullptr;

    hash_map M;
    queue<Node *> Q;

    Q.push(start);

    Node *copied_start = new Node();
    M[start] = copied_start;
    while (!Q.empty()) {
        Node *t = Q.front(); Q.pop();

        for (int i = 0; i < t->neighbors.size(); i++) {
            Node *neighbor = t->neighbors[i];

            if (M.find(neighbor) == M.end()) {
                Node *p = new Node();

                M[t]->neighbors.push_back(p);
                M[neighbor] = p;

                Q.push(neighbor);
            } else {
                M[t]->neighbors.push_back(M[neighbor]);
            }
        }
    }

    return copied_start;
}

Node *dfs_clone_graph(Node *root, hash_map map)
{
    if (root == nullptr) return nullptr;
    if (map.find(root) != map.end()) return map[root];

    Node *new_node = new Node();
    map[root] = new_node;

    for (int i = 0; i < root->neighbors.size(); i++) {
        Node *v = dfs_clone_graph(root->neighbors[i], map);
        new_node->neighbors.push_back(v);
    }

    return new_node;
}

int main()
{
    return 0;
}
