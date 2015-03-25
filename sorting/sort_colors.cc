//============================================================================
// Sort Colors
// Given an array with n objects colored red, white or blue, sort them so that
// objects of the same color are adjacent, with the colors in the order red,
// white and blue.
//
// Here, we will use the integers 0, 1, and 2 to represent the color red,
// white, and blue respectively.
//
// Note:
// You are not suppose to use the library's sort function for this problem.
//
// Follow up:
// A rather straight forward solution is a two-pass algorithm using counting
// sort.
// First, iterate the array counting number of 0's, 1's, and 2's, then
// overwrite array with total number of 0's, then 1's and followed by 2's.
//
// Could you come up with an one-pass algorithm using only constant space?
//============================================================================


#include <iostream>
#include <vector>

void sort(std::vector<int> &a)
{
    int n = a.size();

    int l = 0, m = 0, r = n-1;
    while (m <= r) {
        if (a[m] == 0) {
            std::swap(a[l], a[m]);
            l++; m++;
        } else if (a[m] == 1){
            m++;
        } else if (a[m] == 2) {
            std::swap(a[m], a[r]);
            r--;
        }
    }
}


int main(void)
{
    std::vector<int> input {2,2,1,1,0,0};
    sort(input);

    for (auto it: input) {
        std::cout << it << " ";
    }
    std::cout << std::endl;
}
