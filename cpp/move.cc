#include <vector>

using namespace std;

vector<int> make_vec(int repeat)
{
    vector<int> v(10, repeat);
    return std::move(v);
}

int main()
{
    vector<int> a = make_vec(10000000);
    return 0;
}
