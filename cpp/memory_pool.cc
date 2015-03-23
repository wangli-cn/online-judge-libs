#include <iostream>
#include <boost/array.hpp>
#include <boost/pool/object_pool.hpp>

namespace detail {

    /// @brief Pre-allocated managed memory block.
    template <std::size_t N>
        class arena
        {
            public:

                /// @brief Constructor.
                arena()
                    : current_(&buffer_.front()), // Set current to start.
                    end_(current_ + N)          // End sentinel.
            {
                std::cout << "arena memory range: "
                    << static_cast<void*>(current_) << " - "
                    << static_cast<const void*>(end_) << std::endl;
            }

                /// @brief Attempt to allocate memory from pre-allocated block.
                ///
                /// @param n Count of bytes to allocate.
                ///
                /// @param Non-zero if allocation is succesfull.  Otherwise, zero.
                char* allocate(std::size_t n)
                {
                    // If there is no more memory, then return zero.
                    if ((current_ + n) > end_) return 0;

                    // Otherwise, return available memory and shift current.
                    std::cout << "arena allocating: "
                        << static_cast<void*>(current_) << std::endl;
                    char* ptr = current_;
                    current_ += n;
                    return ptr;
                }

                void deallocate(char* p, std::size_t n)
                {
                    // ...
                }

            private:

                /// @brief Block of memory used for allocations.
                boost::array<char, N> buffer_;

                /// @brief Pointer to current allocation.
                char* current_;

                //// @brief End pointer sentinel.
                const char* end_;
        };

} // namespace detail

/// @brief Allocator that meets Boost.Pool's UserAllocator Concepts.
///        This allocator will allocate memory from a pre-allocated
///        block of static memory.  Each instance of the template is
///        considered to be its own unique allocator, and thus has its
///        own memory.
template <std::size_t N>
class static_allocator
{
    public:
        typedef std::size_t size_type;
        typedef std::ptrdiff_t difference_type;

        static char* malloc(const size_type n) { return arena_.allocate(n); }
        static void free(char* p)              { arena_.deallocate(p, 1);   }

    private:
        static detail::arena<N> arena_;
};

template <std::size_t N>
detail::arena<N> static_allocator<N>::arena_;

/// @brief Helper type.
template <typename T, std::size_t N>
struct static_object_pool:
    boost::object_pool<T, static_allocator<N * sizeof(T)> >
{};

/// Mockup object.
class Foo {};

int main()
{
    static_object_pool<Foo, 128> pool;

    Foo* a = pool.malloc();
    std::cout << "a is at " << a << std::endl;
    Foo* b = pool.malloc();
    std::cout << "b is at " << b << " -- freeing b" << std::endl;
    pool.free(b);
    Foo* c = pool.malloc();
    std::cout << "c is at " << c << std::endl;
}
