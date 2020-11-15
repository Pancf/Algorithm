//
//  Solution52.cpp
//  Algorithm
//
//  Created by Pancf on 2020/11/15.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution52.hpp"
#include <vector>

static bool isSafe(std::vector<int> &queens, int n, int row, int col)
{
    for (int i = 0; i < row; ++i) {
        if (queens[i] == col || (row - i) == abs(queens[i] - col)) return false;
    }
    return true;
}

static void solve(int &res, std::vector<int> &queens, int n, int row)
{
    if (row == n) {
        res += 1;
        return;
    }
    for (int j = 0; j < n; ++j) {
        if (isSafe(queens, n, row, j)) {
            queens[row] = j; // set queen in (row, j)
            solve(res, queens, n, row + 1);
            queens[row] = -1; // reset
        }
    }
}

int Solution52::totalNQueens(int n)
{
    int res = 0;
    std::vector<int> queens(n, -1);
    solve(res, queens, n, 0);
    return res;
}
