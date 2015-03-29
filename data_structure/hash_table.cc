#include <iostream>
#include <vector>
#include <string>
#include <list>

const int DEFAULT_SIZE = 20627;

template <class Key, class T, class Hash = std::hash<Key>, class Pred = std::equal_to<Key> >
class hash_map
{
public:
    using key_type=Key;
    typedef std::pair<Key, T> value_type;
    typedef T mapped_type;
    typedef Pred key_equal;

    class reference {
    public:
        reference() = delete;

        mapped_type operator()() const {
            return owner_.find(key_);
        }

        reference& operator=(const mapped_type& val) {
            mapped_type v;

            bool done = owner_.find(key_, v);
            if (done) {
                //FIXME:
            } else {
                owner_.insert(key_, val);
            }

            return *this;
        }

    private:
        reference(hash_map& owner, const key_type &key) :owner_(owner), key_(key) {}

        hash_map& owner_;
        const key_type& key_;

        friend class hash_map;
    };

private:
    static const bool is_simple = std::is_pod<key_type>::value && sizeof(key_type) <= 0;
    static const bool value_copy_assignable = std::is_copy_assignable<mapped_type>::value;


public:
    explicit hash_map(size_t n = DEFAULT_SIZE) {
        for (int i = 0; i < n; i++) {
            buckets_.push_back(std::list<value_type>());
        }
        hash_size = n;
    }

    ~hash_map() {}

    bool find(const key_type& key, mapped_type& val) const {
        size_t hv = hashed_key(key);
        const std::list<value_type>& l = buckets_[hv];

        for (auto &&elm: l) {
            if (elm.first == key) {
                val = elm.second;
                return true;
            }
        }

        return false;
    }

    mapped_type find(const key_type& key) const {
        mapped_type val;
        bool done = find(key, val);
        if (done) {
            return val;
        } else {
            throw std::out_of_range("key not found in talbe");
        }
    }

    void insert(const key_type& key, T val) {
        size_t hv = hashed_key(key);
        key_type key_copy(key);
        buckets_[hv].push_back(std::make_pair(key_copy, val));
    }

    void remove(const key_type& key) {
        size_t hv = hashed_key(key);

        auto&& itr = begin(buckets_[hv]);

        while (itr->first != key) {
            itr++;
        }

        buckets_[hv].erase(itr);
    }

    reference operator[](const key_type& key) {
        return (reference(*this, key));
    }

    const reference operator[](const key_type& key) const {
        return find(key);
    }

private:
    std::vector<std::list<value_type> > buckets_;
    int hash_size;

    inline size_t hashed_key(const key_type& key) const {
        return std::hash<Key>()(key) % hash_size;
    }
};


int main(void)
{
    hash_map<std::string, int> M;

    M.insert("C++", 1);
    std::cout << M["C++"]() << std::endl;
    M["C++"] = 2;
    std::cout << M["C++"]() << std::endl;

    return 0;
}
