#include <iostream>

using namespace std;

class MulMod
{
public:
    int multiplier;
    int modulo;

    MulMod() = delete;
    explicit MulMod(int mu, int mo) :multiplier(mu), modulo(mo) {};

    int operator()(int x) {
        return (x * multiplier) % modulo;
    }
};

pair<int, int> FloydCycleFinding(MulMod f, int x0)
{
    int tortoise = f(x0), hare = f(f(x0));
    while (tortoise != hare) {
        tortoise = f(tortoise);
        hare = f(f(hare));
    }

    int mu = 0; //the smallest index such that the value x_mu reappears infintely often within the sequence
    hare = tortoise; tortoise = x0;
    while (tortoise != hare) {
        tortoise = f(tortoise);
        hare = f(hare);
        mu += 1;
    }

    int lambda = 1; //loop length
    hare = f(tortoise);
    while (tortoise != hare) {
        hare = f(hare);
        lambda += 1;
    }

    return pair<int, int>(lambda, mu);
}

int main(void)
{
    MulMod fObject(814, 2960);
    pair<int, int> res = FloydCycleFinding(fObject, 814);
    cout << res.first << " " << res.second << endl;
    return 0;
}
