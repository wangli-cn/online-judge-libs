#include <iostream>
#include <vector>

using VVB = std::vector<std::vector<bool>>;

bool has_word_helper(const char *A[], int m, int n, const char *word, int i, int j, VVB &visited)
{
    if (word == nullptr) return true;
    if (*word == '\0') return true;

    if (i < 0 || i >= m) return false;
    if (j < 0 || j >= n) return false;
    if (visited[i][j]) return false;
    if (A[i][j] != *word) return false;

    visited[i][j] = true;

    if (has_word_helper(A, m, n, word+1, i-1, j, visited) ||
        has_word_helper(A, m, n, word+1, i+1, j, visited) ||
        has_word_helper(A, m, n, word+1, i, j-1, visited) ||
        has_word_helper(A, m, n, word+1, i, j+1, visited)) {
        return true;
    }

    visited[i][j] = false;
    return false;
}

bool has_word(const char *A[], int m, int n, const char *word)
{
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            VVB visited(m, std::vector<bool>(n, false));
            if (has_word_helper(A, m, n, word, i, j, visited)) {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    const char *matrix[] = {"woc", "dba", "atc"};
    std::cout << std::boolalpha << has_word(matrix, 3, 3, "cow") << std::endl;
    return 0;
}
