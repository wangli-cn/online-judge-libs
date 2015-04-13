#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

const int INF = std::numeric_limits<int>::max();

int patience(const std::vector<int> &a)
{
    const int n = a.size();
    std::vector<int> A(n, INF);
    std::vector<int> repetition(n, 0);

    for (int i = 0; i < n; i++) {
        auto it = std::lower_bound(A.begin(), A.end(), a[i]);
        int idx =  std::distance(A.begin(), it);

        if (idx == 0) {
            for (int j = n-1; j > 0; j--) {
                A[j] = A[j-1];
                repetition[j] = repetition[j-1];
            }

            A[0] = a[i];
            repetition[0] = 1;
        } else {
            if (A[idx] == a[i]) {
                repetition[idx] += 1;
            } else {
                A[idx-1] = a[i];
                repetition[idx-1] = 1;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] != INF) {
            //std::cout << A[i] << " " << repetition[i] << std::endl;
            sum += repetition[i];
        }
    }

    return sum;
}

int main()
{
    int n;
    std::vector<int> series;

    std::cin >> n;
    if (n == 1) {
        std::cout << 1 << std::endl;
    } else {
        for (int i = 0; i < n; i++) {
            int a;
            std::cin >> a;

            series.push_back(a);
        }

        std::cout << patience(series) << std::endl;
    }

    return 0;
}
