//preorder iterator
//postorder iterator

#include <iostream>

template <class T, class A = std::allocator<T> >
class BinarySearchTree
{
    struct Node;

public:
    typedef A allocator_type;
    typedef typename A::value_type value_type;
    typedef typename A::reference reference;
    typedef typename A::const_reference const_reference;
    typedef typename A::difference_type difference_type;
    typedef typename A::size_type size_type;

    class Iterator {
        public:
            void operator++();
            const T& operator*() { return (static_cast<Node *>(_node))->data; }
            bool operator==(const Iterator &it) { return _node == it._node; }
            bool operator!=(const Iterator &it) { return !(*this == it); }
        private:
            Iterator(Node *node) : _node(node) {}
            ~Iterator();
            Node *_node;
            friend class BinarySearchTree<T>;
    }

    BinarySearchTree() : _begin(&_tail), _root(nullptr), _count(0) {}
    ~BinarySearchTree();

    Iterator begin() const { return Iterator(_begin); }
    Iterator end() const { return Iterator(&_tail); }

private:
    struct Node {
        Node() :parent(nullptr), left(nullptr), right(nullptr) {}

        Node *parent, *left, *right;
        T data;
    };

    static Node *_min(Node *);

    Node *_begin;
    Node *_root;
    mutable Node _tail;
    unsigned _count;
};


template <class T>
void BinarySearchTree<T>::Iterator::operator++()
{
    if (_node->right) {
        _node = BinarySearchTree<T>::_min(_node->right);
        return;
    }

    while (_node->parent->right == _node) {
        _node = _node->parent;
    }

    if (_node->parent->left == _node) {
        _node = _node->parent;
        return;
    }
}

template <class T>
typename BinarySearchTree<T>::Node * BinarySearchTree<T>::_min(Node *node)
{
    Node *result = node;
    while (result->left != nullptr) {
        result = result->left;
    }
    return result;
}

