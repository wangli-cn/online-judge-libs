#include <iostream>
#include <deque>
#include <algorithm>

bool havel_hakimi(std::deque<int> degrees)
{
    if (degrees.size() == 0) {
        return true;
    }

    int d1 = degrees.front();
    degrees.pop_front();
    if (d1 == 0) {
        return true;
    } else if (d1 > degrees.size()) {
        return false;
    }

    for (int i = 0; i < d1; i++) {
        if (degrees[i] == 0) {
            return false;
        } else {
            degrees[i] -= 1;
        }
    }

    std::sort(degrees.begin(), degrees.end(), std::greater<int>());
    return havel_hakimi(std::move(degrees));
}

int main()
{
    int n;
    while (std::cin >> n) {
        if (n == 0) {
            break;
        }

        int d;
        std::deque<int> degrees;
        for (int i = 0; i < n; i++) {
            std::cin >> d;
            degrees.push_back(d);
        }

        std::sort(degrees.begin(), degrees.end(), std::greater<int>());
        if (havel_hakimi(std::move(degrees))) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }

    return 0;
}
