#include <iostream>
#include <vector>

using namespace std;

typedef int Weight;

struct HuffmanTree
{
    vector<Weight> w;
    struct Node {
        Weight weight; 
        Node *left, right;
        Node(Weight weight) :weight(weight) {
            left = right = NULL;
        }

        bool operator<(const Node &e) {
            return weight > e.weight;
        }
    } *root;

    template <class IN>
    HuffmanTree(IN begin, IN end) :w(begin, end) {
        root = build_tree(); 
    }

    ~HuffmanTree() {
        release(root);
    }

    void build_tree() {
        priority_queue<Node> Q;
        int n = w.size();
        for (int i = 0; i < n; ++i) {
            Q.push(Node(w[i]));
        }

        //for (int i = 0; i < n; ++i) {
            //Node v1 = Q.top(); Q.pop();
            //Node v2 = Q.top(); Q.pop();

            //Node *v = new Node(v1.weight + v2.weight, v1, v2);
            //Q.push();
        //}
    }

    void release(Node *t) {
        if (t->left) release(t->left);
        if (t->right) release(t->right);
        delete t;
    }
};


int main(void)
{
    return 0;
}

