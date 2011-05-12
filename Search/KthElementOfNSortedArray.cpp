#include <iostream>
#include <vector>

using namespace std;

struct Interval
{
    int low, high;  
    Interval(int low, int high) 
        :low(low), high(high) {}
};

int M_Query(int k, vector<int> &array)
{
}

int C_Query(int val, vector<int> &array)
{

}

int mid_value(vector<int> &array)
{

}

void kth_element(int k, vector< vector<int> > &arrays)
{
    int n = arrays.size();

    for (int i = 0; i < n; ++i) {
    
    }
}

int main(void)
{
    int n, m, element;
    cin >> n;

    vector< vector<int> > arrays;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        arrays.push_back(vector<int>());
        for (int j = 0; j < m; ++j) {
            cin >> element;
            arrays.back().push_back(element);
        }
    }

    kth_element(0, arrays);

    return 0;
}
