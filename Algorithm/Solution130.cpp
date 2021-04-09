//
//  Solution130.cpp
//  Algorithm
//
//  Created by Pancf on 2020/12/20.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution130.hpp"

static std::vector<std::pair<int, int>> pathInsideBoard(std::vector<std::vector<char>> &board, int x, int y)
{
    
}

void Solution130::solve(std::vector<std::vector<char>> &board)
{
    int row = (int)board.size();
    int col = row;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (board[i][j] == 'O') {
                // search path to border
                // if has no path to border, flip all cell in the path
                
            }
        }
    }
}
