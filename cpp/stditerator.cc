#include <iostream>
#include <vector>
#include <list>
#include <iterator>

template <typename T>
class SomeSortedContainer
{
    std::Vector<T> m_data;

public:
    typedef typename std::vector<T>::iterator iterator;
    typedef typename std::vector<T>::const_iterator const_iterator;

    iterator begin() { return m_data.begin(); }
    const_iterator begin() const { return m_data.begin(); }
    const_iterator cbegin() const { return m_data.cbegin(); }
    iterator end() { return m_data.end(); }
    const_iterator end() const { return m_data.end(); }
    const_iterator cend() const { return m_data.cend(); }
};


template <class BDIter>
void alg(BDIter, BDIter, std::bidirectional_iterator_tag)
{
    std::cout << "alg() called for bidirectional iterator" << std::endl;
}

template <class RAIter>
void alg(RAIter, RAIter, std::random_access_iterator_tag)
{
    std::cout << "alg() called for random-access iterator" << std::endl;
}

template <class Iter>
void alg(Iter first, Iter last)
{
    alg(first, last, typename std::iterator_traits<Iter>::iterator_category());
}

int main()
{
    std::vector<int> v;
    alg(v.begin(), v.end());

    std::list<int> l;
    alg(l.begin(), l.end());

    return 0;
}
