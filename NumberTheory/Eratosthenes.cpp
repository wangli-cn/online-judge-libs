#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>

using namespace std;

const int MAXP = 100;

void sieve1(vector<int> &prime)
{
    static bool isprime[MAXP];
    fill(isprime, isprime + MAXP, true);

    isprime[0] = isprime[1] = false;
    for (int i = 2; i < MAXP; ++i) {
        if (isprime[i]) prime.push_back(i);

        for (int j = 0; (j < prime.size() && i * prime[j] < MAXP); ++j) {
            isprime[i * prime[j]] = false;
            if ((i % prime[j]) == 0) break;
        }
    }
}

// 2 N log N
void sieve2(vector<int> &prime)
{
    static bool isprime[MAXP];
    fill(isprime, isprime+MAXP, true);

    isprime[0] = isprime[1] = false;
    for (int i = 2; i < MAXP; i++) {
        if (isprime[i]) {
            prime.push_back(i);

            for (int j = i*i; j < MAXP; j += i) {
                isprime[j] = false;
            }
        }
    }
}

void sieve3(vector<int> &prime)
{
    static bool isprime[MAXP];
    fill(isprime, isprime+MAXP, true);

    isprime[0] = isprime[1] = false;
    for (int i = 2; i < MAXP; i++) {
        if (isprime[i]) {
            prime.push_back(i);

            for (int j = i+i; j < MAXP; j += i) {
                isprime[j] = false;
            }
        }
    }
}

int main(void)
{
    vector<int> prime;
    //sieve1(prime);
    sieve2(prime);
    copy(prime.begin(), prime.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
