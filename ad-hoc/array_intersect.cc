#include <vector>
#include "utils/common.h"

using namespace std;

vector<int> find_intersection(vector<int> &a, vector<int> &b)
{
    vector<int> intersect;

    size_t n1 = a.size(), n2 = b.size();

    size_t i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a[i] > b[j]) j += 1;
        else if (a[i] < b[j]) i += 1;
        else {
            intersect.push_back(a[i]);
            i += 1; j += 1;
        }
    }

    return intersect;
}

int main(void)
{
    vector<int> a {1,2,3,4,5};

    print_container(a);
    return 0;
}
