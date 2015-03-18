#include <memory>
#include <type_traits>

template<typename T, class = typename std::enable_if<std::is_copy_constructible<T>::value>::type >
class Node {
    public:
        explicit Node(T val) :val(val), next(nullptr) {}

        Node<T> *next;
        T val;
    private:
        Node();
        Node(const Node &) = delete;
        Node(const Node &&) = delete;
        Node &operator=(const Node&) = delete;
        Node &operator=(const Node&&) = delete;
};


void print_list(Node<int> *p)
{
    while (p != nullptr) {
        std::cout << p->val << ' ';
        p = p->next;
    }
    std::cout << std::endl;
}

Node<int> *build_linked_list(int default_size = 10)
{
    Node<int> *head = nullptr, *tail = nullptr;

    for (int i = 1; i <= default_size; i++) {
        Node<int> *curr = new Node<int>(i);

        if (head == nullptr) {
            head = tail = curr;
        } else {
            tail->next = curr;
            tail = tail->next;
        }
    }

    return head;
}
