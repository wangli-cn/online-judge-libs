#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool is_word(string s)
{
    if (s == "cat") return true;
    if (s == "cow") return true;
    return false;
}

void find_word_internal(char *matrix[], vector<vector<bool> > &visited, int m, int n, int i, int j, string s)
{
    if (i < 0 || i >= m) return;
    if (j < 0 || j >= n) return;
    if (visited[i][j]) return;

    visited[i][j] = true;
    s.push_back(matrix[i][j]);

    if (is_word(s)) cout << s << endl;

    find_word_internal(matrix, visited, m, n, i-1, j-1, s);
    find_word_internal(matrix, visited, m, n, i-1, j, s);
    find_word_internal(matrix, visited, m, n, i-1, j+1, s);
    find_word_internal(matrix, visited, m, n, i, j+1, s);
    find_word_internal(matrix, visited, m, n, i+1, j+1, s);
    find_word_internal(matrix, visited, m, n, i+1, j, s);
    find_word_internal(matrix, visited, m, n, i+1, j-1, s);
    find_word_internal(matrix, visited, m, n, i, j-1, s);

    visited[i][j] = false;
}

void find_word(char *matrix[], int m, int n)
{
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            vector< vector<bool> > visited(m, vector<bool>(n, false));
            find_word_internal(matrix, visited, m, n, i, j, string(""));
        }
    }
}

int main()
{
    char *matrix[] = {"woc", "dba", "atc"};
    find_word(matrix, 3, 3);
    return 0;
}
