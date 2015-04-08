#include <iostream>
#include <vector>

using VVI = std::vector<std::vector<int>>;

int sol_cnt = 0;

void print_board(VVI &board)
{
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (j == 8) {
                std::cout << board[i][j];
            } else {
                std::cout << board[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool get_next_empty_cell(VVI &board, int &row, int &col)
{
    while (row <= 8 && col <= 8) {
        if (board[row][col] == 0) return true;
        row = (col == 8) ? row + 1 : row;
        col = (col == 8) ? 0 : col + 1;
    }

    return false;
}

std::vector<int> get_possibles(VVI &board, int row, int col)
{
    std::vector<bool> used(10, false);

    for (int i = 0; i < 9; i++) {
        if (board[row][i] != 0) used[board[row][i]] = true;
        if (board[i][col] != 0) used[board[i][col]] = true;

        int l = board[row / 3 * 3 + i/3][col / 3 * 3 + i%3];

        if (l != 0) {
            used[l] = true;
        }
    }

    std::vector<int> possibles;
    for (int i = 1; i <= 9; i++) {
        if (!used[i]) {
            possibles.push_back(i);
        }
    }

    return std::move(possibles);
}

bool go(VVI &board, int row, int col)
{
    bool res = get_next_empty_cell(board, row, col);

    //std::cout << row << " " << col << std::endl;
    if (!res) {
        sol_cnt += 1;
        print_board(board);
        return true;
    }

    std::vector<int> possibles = get_possibles(board, row, col);
    //std::cout << "possibles.size(): " << possibles.size() << std::endl;

    if (possibles.size() == 0) return false;
    //for (auto elm: possibles) {
        //std::cout << elm << " ";
    //}
    //std::cout << std::endl;

    bool result = true;
    for (int i = 0; i < possibles.size(); i++) {
        board[row][col] = possibles[i];

        if (go(board, row, col)) {
            result = true;
        }

        board[row][col] = 0;
    }

    return result;
}


void solve(VVI &board)
{
    go(board, 0, 0);
    std::cout << "there are a total of " << sol_cnt << " solution(s)." << std::endl;
}

int main()
{
    int elm;
    VVI board(9, std::vector<int>(9, 0));

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cin >> elm;
            board[i][j] = elm;
        }
    }

    sol_cnt = 0;
    solve(board);
    return 0;
}
