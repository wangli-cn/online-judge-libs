//============================================================================
// Remove Element
// Given an array and a value, remove all instances of that value in place
// and return the new length.
//
// The order of elements can be changed. It doesn't matter what you leave
// beyond the new length.
//============================================================================

#include <iostream>

int remove_element(int a[], int n, int elem)
{
    int i = 0, j = 0;
    while (i < n) {
        if (a[i] != elem) {
            if (i == j) i++, j++;
            else a[j++] = a[i++];
        } else {
            i++;
        }
    }
    return j;
}

int main(void)
{
    int a[6] = {1,2,3,4,5,6};

    std::cout << remove_element(a, 6, 3) << std::endl;
    return 0;
}
