#include <iostream>
#include <random>
#include <vector>

int rand()
{
    static std::random_device rd;
    static std::mt19937 mt(rd());
    static std::uniform_int_distribution<> dist(1, 100);
    return dist(mt);
}

int rand_dist(std::vector<int> den)
{
    std::vector<int> dist(den.size());
    int n = den.size();

    dist[0] = den[0];
    for (int i = 1; i< den.size(); i++) {
        dist[i] = dist[i-1] + den[i];
    }

    int rand_num = rand() % (dist[n-1]+1);
    for (int i = 0; i < n ;i++) {
        if (rand_num <= dist[i]) {
            return i;
        }
    }
}

int main()
{
    std::vector<int> den {1,2,3,4,5};
    std::cout << rand_dist(den) << std::endl;
    return 0;
}
