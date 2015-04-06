#include <iostream>
#include <algorithm>

std::pair<int,int> find(int matrix[5][5], int M, int N, int value)
{
    int r = 0, c = N-1;

    while (r < M && c >= 0) {
        if (matrix[r][c] == value) {
            return std::make_pair(r, c);
        } else if (matrix[r][c] > value) {
            c--;
        } else {
            r++;
        }
    }

    return std::make_pair(-1, -1);
}

int main()
{
    int a[5][5] = { {1,2,3,4,5},
                    {6,7,8,9,10},
                    {11,12,13,14,15},
                    {16,17,18,19,20},
                    {21,22,23,24,25}};

    auto&& res =  find(a, 5, 5, 18);
    std::cout << res.first << " " << res.second << std::endl;
    return 0;
}
