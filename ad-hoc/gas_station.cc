//There are n gas stations positioned along a circular road. Each has a limite
//d supply of gas. You can only drive clockwise around the road. You start wit
//h zero gas. Knowing how much gas you need to get from each gas station to th
//e next and how much gas you can get at each station, design an algorithm to
//find the gas station you need to start at to get all the way around the circ
//le.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int select_gas_station(vector<int> &a, vector<int> &g)
{
    vector<int> net(a.size() * 2);
    int n = a.size();

    int sum_a = 0, sum_g = 0;
    for (int i = 0; i < n; i++) {
        net[i] = g[i] - a[i];
        sum_a += a[i];
        sum_g += g[i];
    }

    if (sum_g < sum_a) {
        return -1;
    }

    copy(net.begin(), net.begin() + n,  net.begin()+n);

    int sum = 0;
    int start = 0, end = 0;
    for (int i = 0; i < n+n; i++) {
        sum += net[i];

        if (sum < 0) {
            sum = 0;
            start = i+1;
            end = i+1;
        } else {
            end = i;

            if (end - start >= n) return start;
        }
    }

    return -1;
}

int main()
{
    vector<int> aa {3,50,3,3,3,3};
    vector<int> gg {3,3,3,1,3,3};
    cout << select_gas_station(aa, gg) << endl;
    return 0;
}
