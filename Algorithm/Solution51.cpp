//
//  Solution51.cpp
//  Algorithm
//
//  Created by Pancf on 2020/11/15.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution51.hpp"

static bool isSafe(std::vector<std::string> &board, int n, int row, int col)
{
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 'Q') return false;
    }
    // to left-top
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }
    // to right-top
    for (int i = row - 1, j = col + 1; i >= 0 && j <= n; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }
    return true;
}

static void solve(std::vector<std::vector<std::string>> &res, std::vector<std::string> &board, int n, int row)
{
    if (row == n) {
        // find and save solution, then backtrack
        res.push_back(board);
        return;
    }
    for (int j = 0; j < n; ++j) {
        if (isSafe(board, n, row, j)) {
            board[row][j] = 'Q'; // set as placed
            solve(res, board, n, row + 1);
            board[row][j] = '.'; // reset as unplaced
        }
    }
}

std::vector<std::vector<std::string>> Solution51::solveNQueens(int n)
{
    std::vector<std::vector<std::string>> res;
    // we can also use vector<int> representing the placed cols, (i, v[i]) is the point where we place the queue in row i
    // if use such representation, judging the diagonal in isSafe become easier, because if in the same diagonal, abs(slope)==1
    // why I doesn't use such representation? because I'm lazy
    std::vector<std::string> board(n, std::string(n, '.'));
    solve(res, board, n, 0);
    return res;
}
