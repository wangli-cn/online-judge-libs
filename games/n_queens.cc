//============================================================================
// N-Queens
//
// The n-queens puzzle is the problem of placing n queens on an n×n chessboard
// such that no two queens attack each other.
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

bool is_safe(vector<bool> &row_occupied, vector<bool> &column_occupied, vector<bool> &diag_occupied, vector<bool> &adiag_occupied, int row, int col)
{
    int n = row_occupied.size();
    if (row_occupied[row]) return false;
    if (column_occupied[col]) return false;
    if (diag_occupied[row+col]) return false;
    if (adiag_occupied[n-1-(col-row)]) return false;

    return true;
}

void put_queen(vector<bool> &row_occupied, vector<bool> &column_occupied, vector<bool> &diag_occupied, vector<bool> &adiag_occupied, int row, int col)
{
    int n = row_occupied.size();
    row_occupied[row] = true;
    column_occupied[col] = true;
    diag_occupied[row + col] = true;
    adiag_occupied[n-1-(col-row)] = true;
}

void take_queen(vector<bool> &row_occupied, vector<bool> &column_occupied, vector<bool> &diag_occupied, vector<bool> &adiag_occupied, int row, int col)
{
    int n = row_occupied.size();
    row_occupied[row] = false;
    column_occupied[col] = false;
    diag_occupied[row + col] = false;
    adiag_occupied[n-1-(col-row)] = false;
}

void go(vector<bool> &row_occupied, vector<bool> &column_occupied, vector<bool> &diag_occupied, vector<bool> &adiag_occupied, int col, vector<pair<int, int> > &sol, vector<vector<pair<int, int> > > &result)
{
    int n = row_occupied.size();
    if (col == n) {
        result.push_back(sol);
    }

    for (int i = 0; i < n; i++) {
        if (is_safe(row_occupied, column_occupied, diag_occupied, adiag_occupied, i, col)) {
            put_queen(row_occupied, column_occupied, diag_occupied, adiag_occupied, i, col);
            sol.push_back(make_pair(i, col));
            go(row_occupied, column_occupied, diag_occupied, adiag_occupied, col+1, sol, result);
            take_queen(row_occupied, column_occupied, diag_occupied, adiag_occupied, i, col);
            sol.pop_back();
        }
    }
}

vector<vector<pair<int,int> > > solve(int n)
{
    vector<bool> row_occupied(n, false), column_occupied(n, false), diag_occupied(n, false), adiag_occupied(n, false);
    vector<pair<int, int> > sol;
    vector<vector<pair<int, int> > > result;

    go(row_occupied, column_occupied, diag_occupied, adiag_occupied, 0, sol, result);
    return result;
}

int main(void)
{
    vector<vector<pair<int, int> > > res = solve(8);
    cout << res.size() << endl;

    return 0;
}
