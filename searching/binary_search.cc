#include <iostream>
#include <vector>

int netty_binary_search(std::vector<int> &a, int M, int N, int v)
{
    int l = M-1, r = N+1;
    while (l+1 != r) {
        int m = l + ((r-l)/2);

        if (a[m] <= v) {
            l = m;
        } else if (a[m] > v) {
            r = m;
        }
    }

    if (l > M-1) return l;
    else return -1;
}

int bently_binary_search(std::vector<int> &a, int l, int r, int v)
{
    while (l < r) {
        int mid = l + ((r-l)/2);
        if (a[mid] < v) l = mid+1;
        else r = mid;
    }
    //r == l, using r or l depends on taste
    if ((l < a.size()) && a[l] == v) return l;
    else return -1;
}

int binary_search2(std::vector<int> &a, int l, int r, int v)
{
    if (r < l) return -1;

    int mid = l + ((r - l)/2);
    if (a[mid] > v) return binary_search2(a, l, mid-1, v);
    else if (a[mid] < v) return binary_search2(a, mid+1, r, v);
    else return mid;
}

int main(void)
{
    std::vector<int> a {1,2,3,4,5,6,7};

    std::cout << bently_binary_search(a, 0, 6, 3) << std::endl;
    std::cout << netty_binary_search(a, 0, 6, 3) << std::endl;
    return 0;
}
