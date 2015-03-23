#include <tr1/memory>

template <class T>
class CowPtr
{
    public:
        typedef std::tr1::shared_ptr<T> RefPtr;

    private:
        RefPtr m_sp;

        void detach() {
            T *t = m_sp.get();

            if ( !(t == NULL || m_sp.unique()) ) {
                m_sp = RefPtr(new T(*t));
            }
        }

    public:

        CowPtr(T *t) :m_sp(t) {}
        CowPtr(const RefPtr &refptr) :m_sp(refptr) {}
        CowPtr(const CowPtr &cowptr) :m_sp(cowptr.m_sp) {}

        CowPtr &operator=(const CowPtr &rhs) {
            m_sp = rhs.m_sp;
            return *this;
        }

        const T& operator*() const {
            return *m_sp;
        }

        T& operator*() {
            detach();
            return *m_sp;
        }

        const T* operator->() const {
            return m_sp.operator->();
        }

        T* operator->() {
            detach();
            return m_sp.operator->();
        }
};

int main()
{
    return 0;
}
