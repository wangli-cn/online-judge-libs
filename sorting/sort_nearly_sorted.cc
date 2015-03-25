//Sort a nearly sorted (or K sorted) array

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

struct min_heap
{
    min_heap(vector<int> a) :harr(a) {
        size = a.size();
        int i = (size-1) / 2;

        while (i >= 0) {
            min_heapify(i);
            i--;
        }
    }

    void min_heapify(int i) {
        int l = i+i+1;
        int r = i+i+2;
        int small = i;

        if (l < size && harr[l] < harr[i]) small = l;
        if (r < size && harr[r] < harr[small]) small = r;

        if (small != i) {
            swap(harr[i], harr[small]);
            min_heapify(small);
        }
    }

    int replace_min(int x) {
        int root = harr[0];
        harr[0] = x;

        if (root < x) {
            min_heapify(0);
        }

        return root;
    }

    int extract_min()
    {
        int root = harr[0];
        if (size > 1) {
            harr[0] = harr[size-1];
            size -= 1;
            min_heapify(0);
        }

        return root;
    }

    vector<int> harr;
    int size;
};


void sort_k(vector<int> &a, int K)
{
    vector<int> container(a.begin(), a.begin()+K+1);
    min_heap heap(container);
    int n = a.size();

    for (int i = K+1, j = 0; j < n; i++, j++) {
        if (i < n) a[j] = heap.replace_min(a[i]);
        else a[j] = heap.extract_min();
    }
}

int main()
{
    int K = 3;
    vector<int> input{2, 6, 3, 12, 56, 8};

    copy(input.begin(), input.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    sort_k(input, K);

    copy(input.begin(), input.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}
