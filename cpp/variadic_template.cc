#include <array>

template <typename T, typename... Tail>
auto make_array(T head, Tail... tail) -> std::array<T, 1 + sizeof...(Tail)>
{
    std::array<T, 1 + sizeof...(Tail)> a = {head, tail ...};
    return a;
}

int main()
{
    auto a = make_array(1,2,3);
}
