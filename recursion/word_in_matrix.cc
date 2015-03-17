#include <iostream>
#include <vector>

using namespace std;

bool has_word_helper(char *A[], int m, int n, char *word, int i, int j, vector<vector<bool> > &visited)
{
    if (word == NULL) return true;
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

bool has_word(char *A[], int m, int n, char *word)
{
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            vector< vector<bool> > visited(m, vector<bool>(n, false));
            if (has_word_helper(A, m, n, word, i, j, visited)) {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    char *matrix[] = {"woc", "dba", "atc"};
    cout << has_word(matrix, 3, 3, "cow") << endl;
}
