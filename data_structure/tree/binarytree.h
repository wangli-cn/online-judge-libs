namespace tree_with_normal_ptr {
    template<typename T, class = typename std::enable_if<std::is_copy_constructible<T>::value>::type >
    class Node
    {
        public:
            Node(T x) :val(x), left(nullptr), right(nullptr), parent(nullptr) {}
            T val;

            Node<T> *left, *right, *parent;

        private:
            Node();
            Node(const Node &) = delete;
            Node(const Node &&) = delete;
            Node &operator=(const Node&) = delete;
            Node &operator=(const Node&&) = delete;
    };
}

namespace tree_with_unique_ptr {
    template<typename T, class = typename std::enable_if<std::is_copy_constructible<T>::value>::type >
    class Node
    {
        public:
            Node(T x) :val(x), left(nullptr), right(nullptr) {}
            T val;

            std::unique_ptr<Node<T> > left, right;

        private:
            Node();
            Node(const Node &) = delete;
            Node(const Node &&) = delete;
            Node &operator=(const Node&) = delete;
            Node &operator=(const Node&&) = delete;
    };
}
