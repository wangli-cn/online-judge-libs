#ifndef __COMMON
#define __COMMON

#include <iostream>
#include <vector>
#include <string>

#define REP(i, n) for(int i = 0; i < (int)n; ++i)
#define FOR(i,c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define EPS 1e-8


#define Display(A, n, m) {                      \
	REP(i, n){		                            \
        REP(j, m) std::cout << A[i][j] << " ";  \
        std::cout << std::endl;		            \
	}						                    \
}


using LL = long long;

using VI = std::vector<int>;
using VVI = std::vector< std::vector<int> >;
using VC = std::vector<char>;
using VS = std::vector<std::string>;

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
