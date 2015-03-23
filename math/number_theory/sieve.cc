#include <iostream>
#include <vector>

using namespace std;

const int MAXP = 20000;

vector<int> sieve()
{
    static bool isprime[MAXP];
    fill(isprime, isprime+MAXP, true);
    vector<int> prime;

    isprime[0] = isprime[1] = false;
    for (int i = 2; i < MAXP; i++) {
        if (isprime[i]) {
            prime.push_back(i);

            for (int j = i*i; j < MAXP; j += i) {
                isprime[j] = false;
            }
        }
    }

    return std::move(prime);
}

int main()
{
    auto prime = sieve();

    for (auto e: prime) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    return 0;
}
