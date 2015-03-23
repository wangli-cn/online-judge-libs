#include <iostream>

template <typename T>
class SharedPtr
{
    private: 
        T *_ptr;
        unsigned *_refcnt;


    public:
        SharedPtr(T *ptr) {
            _ptr = ptr;
            _refcnt = new unsigned;
            *_refcnt = 1; 
        }

        SharedPtr(const SharedPtr<T> &self) {
            _ptr = self.ptr;
            _refcnt = self._refcnt;
            ++*_refcnt;
        }
        
        SharedPtr &operator=(const SharedPtr<T> &sptr) {
            if (this != &sptr) {
                _ptr = sptr._ptr;
                _refcnt = sptr._refcnt;
                ++*_refcnt; 
            }

            return *this;
        }

        ~SharedPtr() {
            --*_refcnt;
            if (*_refcnt == 0) { 
                delete _ptr; _ptr = NULL; 
                delete _refcnt; _refcnt = NULL;
            }
        }

        T *get() const { return _ptr; }
};

int main(void)
{
    SharedPtr<int> p(new int);

    return 0;
}
