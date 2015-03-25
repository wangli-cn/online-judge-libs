//============================================================================
// Sudoku Solver
// Write a program to solve a Sudoku puzzle by filling the empty cells.
//
// Empty cells are indicated by the character '.'.
//
// You may assume that there will be only one unique solution.
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<char> > VVC;

bool get_next_empty_cell(VVC &board, int &row, int &col)
{
    while (row <= 8 && col <= 8) {
        if (board[row][col] == '.') return true;
        row = (col == 8) ? row + 1 : row;
        col = (col == 8) ? 0 : col+1;
    }

    return false;
}

vector<char> get_possibles(VVC &board, int row, int col)
{
    bool used[9] = {false};

    for (int i = 0; i < 9; i++) {
        if (board[row][i] != '.') used[board[row][i] - '1'] = true;
        if (board[i][col] != '.') used[board[i][col] - '1'] = true;

        char c = board[row/3 * 3 + i/3][col/3 * 3 + i % 3];
        if (c != '.') {
            used[c - '1'] = true;
        }
    }

    vector<char> possible;
    for (int i = 0; i < 9; i++) {
        if (!used[i]) {
            possible.push_back('1' + i);
        }
    }

    return possible;
}

bool go(VVC &board, int row, int col)
{
    bool res = get_next_empty_cell(board, row, col);

    if (!res) return true;

    vector<char> possible = get_possibles(board, row, col);

    if (possible.size() == 0) return false;

    for (int i = 0; i < possible.size(); i++) {
        board[row][col] = possible[i];

        if (go(board, row, col)) return true;

        board[row][col] = '.';
    }

    return false;
}

void solve(VVC &board)
{
    go(board, 0, 0);
}


int main()
{
    return 0;
}
