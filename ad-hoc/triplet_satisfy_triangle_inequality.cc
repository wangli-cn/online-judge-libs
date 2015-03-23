//How to know that a triangle triple exists in our array?
//http://stackoverflow.com/questions/5391207/how-to-know-that-a-triangle-triple-exists-in-our-array
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool triangle_exists(vector<int> &a)
{
    int n = a.size();

    sort(a.begin(), a.end());

    bool res = false;
    for (int i = n-3; i >= 0; i--) {
        if (a[i] + a[i+1] > a[i+2]) {
            res = true;
        }
    }

    return res;
}

int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    vector<int> input(a, a+10);

    cout << std::boolalpha << triangle_exists(input) << endl;
    return 0;
}
