//
//  Solution79.cpp
//  Algorithm
//
//  Created by Pancf on 2020/11/7.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution79.hpp"

bool _exist(std::vector<std::vector<char> > &board, int x, int y, std::string &word, int i)
{
    if (i == word.size()) return true;
    if (x < 0 || y < 0 || x == board.size() || y == board[0].size()) return false;
    if (word[i] != board[x][y]) return false;
    // if equal, flag as visited
    board[x][y] ^= 0xFF;
    bool res = _exist(board, x, y + 1, word, i + 1)
            || _exist(board, x + 1, y, word, i + 1)
            || _exist(board, x, y - 1, word, i + 1)
            || _exist(board, x - 1, y, word, i + 1);
    // flag as un-visited
    board[x][y] ^= 0xFF;
    return res;
}

bool Solution79::exist(std::vector<std::vector<char> > &board, std::string word)
{
    int row = (int)board.size(), col = (int)board[0].size();
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (_exist(board, i, j, word, 0)) {
                return true;
            }
        }
    }
    return false;
}
