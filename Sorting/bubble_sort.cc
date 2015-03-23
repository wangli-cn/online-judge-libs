#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(vector<int> &a)
{
    int n = a.size();
    bool swapped;

    do {
        swapped = false;
        n -= 1;
        for (int i = 0; i < n; i++) {
            if (a[i] > a[i+1]) {
                swap(a[i], a[i+1]);
                swapped = true;
            }
        }
    } while (swapped);
}

int main()
{
    vector<int> a { 6, 5, 4, 3, 2, 1 };
    bubble_sort(a);
    for (auto i: a) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    return 0;
}
