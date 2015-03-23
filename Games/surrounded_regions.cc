//============================================================================
// Given a 2D board containing 'X' and 'O', capture all regions surrounded¿
// by 'X'.
//
// A region is captured by flipping all 'O's into 'X's in that surrounded¿
// region.
//
// For example,
// X X X X
// X O O X
// X X O X
// X O X X
// After running your function, the board should be:
//
// X X X X
// X X X X
// X X X X
// X O X X
//============================================================================


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<char> > VVC;
typedef pair<int, int> coordinate;

void BFS(VVC &board, int i, int j)
{
    int m = board.size();
    int n = board[0].size();

    queue<coordinate> Q;

    Q.push(make_pair(i, j));
    while (!Q.empty()) {
        int row = Q.front().first;
        int col = Q.front().second;
        Q.pop();

        if (row > 1 && board[row-1][col] == 'O') {
            board[row-1][col] = 'D';
            Q.push(make_pair(row-1, col));
        }

        if (row < m-1 && board[row+1][col] == 'O') {
            board[row+1][col] = 'D';
            Q.push(make_pair(row+1, col));
        }

        if (col > 1 && board[row][col-1] == 'O') {
            board[row][col-1] = 'D';
            Q.push(make_pair(row, col-1));
        }

        if (col < n-1 && board[row][col+1] == 'O') {
            board[row][col+1] = 'D';
            Q.push(make_pair(row, col+1));
        }
    }
}

void solve(VVC &board)
{
    if (board.empty()) {
        return;
    }

    int m = board.size();
    int n = board[0].size();

    for (int i = 0; i < m; i++) {
        if (board[i][0] == 'O') BFS(board, i, 0);
        if (board[i][n-1] == 'O') BFS(board, i, n-1);
    }

    for (int j = 0; j < n; j++) {
        if (board[0][j] == 'O') BFS(board, 0, j);
        if (board[m-1][j] == 'O') BFS(board, m-1, j);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'O') board[i][j] = 'X';
            else if (board[i][j] == 'X') board[i][j] = 'O';
        }
    }
}

int main()
{
    return 0;
}
