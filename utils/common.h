#include <iostream>
#include <string>

template<class T>
void print_container(T&& c, std::string sep = " ")
{
    for (auto &&i = c.begin(); i != c.end(); ++i) {
        std::cout << *i << sep;
    }
    std::cout << std::endl;
}
