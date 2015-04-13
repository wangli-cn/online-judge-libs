#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
#include <memory>


namespace std {

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

};

template<typename T>
class CartesianTree
{
public:
    using Key = int;

    class Node
    {
    public:
        explicit Node(Key k, T x) :key(k), val(x), left(nullptr), right(nullptr) {}
        Key key;
        T val;

        std::unique_ptr<Node> left, right;

        friend class CartesianTree;
    };

    std::unique_ptr<Node> root;

    explicit CartesianTree(): root(nullptr) {}
    ~CartesianTree() {}


    void inorder(std::function<void(T)> f)
    {
        inorder(root.get(), f);
    }

    void inorder(Node *v, std::function<void(T)> f) {
        if (v == nullptr) return;

        inorder(v->left.get(), f);
        f(v->val);
        inorder(v->right.get(), f);
    }

    void preorder(std::function<void(T)> f)
    {
        preorder(root.get(), f);
    }

    void preorder(Node *v, std::function<void(T)> f) {
        if (v == nullptr) return;

        f(v->val);
        preorder(v->left.get(), f);
        preorder(v->right.get(), f);
    }

    void insert(Key k, T val) {
        if (root == nullptr) {
            root = std::move(std::make_unique<Node>(k, val));
        } else {
            auto t = insert(root.get(), k, val);
            if (t != nullptr) {
                t->left = std::move(root);
                root = std::move(t);
            }
        }
   }

    std::unique_ptr<Node> insert(Node *v, Key key, T val) {
        if (v == nullptr) {
            return std::make_unique<Node>(key, val);
        }

        assert(key > v->key);

        auto t = insert(v->right.get(), key, val);
        if (v->val < val && t != nullptr) {
            t->left = std::move(v->right);
            v->right = std::move(t);

            return nullptr;
        } else {
            return t;
        }
    }
};



int main()
{
    int n;
    while (std::cin >> n) {
        if (n == 0) break;

        int elm;
        CartesianTree<int> T;
        for (int i = 1; i <= n; i++) {
            std::cin >> elm;

            T.insert(i, elm);
        }

        T.preorder([](int x) { std::cout << x << " "; });
        std::cout << std::endl;
    }

    return 0;
}
