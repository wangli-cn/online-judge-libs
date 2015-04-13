#ifndef __COMMON
#define __COMMON

#include <iostream>
#include <string>

#define REP(i, n) for(int i = 0; i < (int)n; ++i)
#define FOR(i,c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define EPS 1e-8

const int INF = std::numeric_limits<int>::max();


template<class T>
void print_container(T&& c, std::string sep = " ")
{
    for (auto &&i = c.begin(); i != c.end(); ++i) {
        std::cout << *i << sep;
    }
    std::cout << std::endl;
}

#endif
