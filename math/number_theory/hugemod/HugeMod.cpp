#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cassert>

using namespace std;

struct MulMod
{
    int multiplier;
    int modulo;

    MulMod(int mu, int mo) 
        :multiplier(mu), modulo(mo) {};
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

int mul_mod(int x, int y, int n)
{
    //guarantee not to overflow
    int T = floor(sqrt(n) + 0.5);
    int t = T*T - n;

    int a = x/T; int b = x%T;
    int c = y/T; int d = y%T;
    int e = a*c/T; int f = a*c%T;

    int v = ((a*d + b*c)%n + e*t) % n;
    int g = v/T; int h = v%T;
    int ans = (((f + g)*t % n + b*d) % n + h*T) % n;
    while (ans < 0) ans += n;
    return ans;
}

// a^n mod p
int pow_mod(int a, int n, int p)
{
    int ans = 1, d = a % p;
    do {
        if (n & 1) ans = mul_mod(ans, d, p);
        d = mul_mod(d, d, p);
    } while (n >>= 1);
    return ans;
}

// a^n
int mod(int x, int n)
{
    assert(n > 0);

    if (x < 0) {
        x += (-(x / n) + 1) * n;
    }
    return x % n;
}

int HugeMod(vector<int> &Exp, int pos, int lambda, int mu)
{
    if (pos == Exp.size()-1) {
        //cout << lambda << " " << mu << endl;
        if (Exp[pos] <= mu) return Exp[pos];
        else return ((Exp[pos] - mu - 1) % lambda) + 1 + mu;
    }

    MulMod fObject(Exp[pos], lambda);
    pair<int, int> res = FloydCycleFinding(fObject, Exp[pos] % lambda); 
    int t = HugeMod(Exp, pos+1, res.first, res.second);
    //cout << lambda << " " << mu << " " << Exp[pos] << " " << t << endl;
    if (mu > 0) {
        //cout << pow_mod(Exp[pos], t, lambda) << endl;
        //cout << "mu = "  << mu << endl;
        return mod(pow_mod(Exp[pos], t, lambda) - mu - 1, lambda) + mu + 1;
    } else {
        return ((pow_mod(Exp[pos], t, lambda) - 1 + lambda) % lambda) + 1;
    }
}

int main(void)
{
    int M, N, t;
    char line[1024];
    int nCase = 0;

    while (cin.getline(line, 1024)) {
        if (line[0] == '#')
            break;

        istringstream src(line);
        src >> M >> N;
        //cout << M << " " << N << endl;

        vector<int> Exp;
        for (int i = 0; i < N; i++) {
            src >> t;
            Exp.push_back(t);
        }
        
        if (N == 1) {
            cout << "Case #" << ++nCase << ": " << Exp[0] % M << endl;
            continue;
        } else if (N == 2) {
            cout << "Case #" << ++nCase << ": " << pow_mod(Exp[0], Exp[1], M) << endl;
            continue;
        }

        MulMod fObject(Exp[0], M);
        pair<int, int> res = FloydCycleFinding(fObject, Exp[0] % M);
        int k = HugeMod(Exp, 1, res.first, res.second);
        //cout << "k = " << k << ", M = " << M << endl;
        cout << "Case #" << ++nCase << ": " << pow_mod(Exp[0], k, M) << endl;
    }
    return 0;
}
