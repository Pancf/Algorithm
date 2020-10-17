//
//  Solution36.cpp
//  Algorithm
//
//  Created by Pancf on 2020/10/17.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution36.hpp"
#include <map>
#include <set>
#include <string>

bool Solution36::isValidSudoku(std::vector<std::vector<char> > &board)
{
    std::set<std::string> seen;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] != '.') {
                int num = board[i][j] - '0';
                // k1 = "(row)num", k2 = "num(col)", k3 = "xnumy", x&y identify 3*3 grid
                auto k1 = '('+ std::to_string(i) + ')' + std::to_string(num);
                auto k2 = std::to_string(num) + '(' + std::to_string(j) + ')';
                auto k3 = std::to_string(i / 3) + std::to_string(num) + std::to_string(j / 3);
                // if set don't contain value, then insert occured and return true, otherwise return false
                if (!seen.insert(k1).second ||
                    !seen.insert(k2).second ||
                    !seen.insert(k3).second) {
                    return false;
                }
            }
        }
    }
    return true;
    // 'num': {{x0, y0}, {x1, y1}, ..., {x9, y9}}
//    std::vector<std::map<int, int>> chToPositions(9, std::map<int, int>());
//    for (int row = 0; row < 9; ++row) {
//        for (int col = 0; col < 9; ++col) {
//            if (board[row][col] != '.') {
//                // 校验是否存在同一行
//                auto ch = board[row][col];
//                auto& positions = chToPositions[ch - '1'];
//                if (positions.find(row) != positions.end()) {
//                    // in the same row
//                    return false;
//                } else {
//                    positions[row] = col;
//                }
//            }
//        }
//    }
//    for (auto positions : chToPositions) {
//        std::vector<int> v(9, -1);
//        // 3*3 grid
//        std::vector<std::vector<int>> w(3, std::vector<int>(3, -1));
//        // 校验是否存在同一列或者同一个3*3 grid中的情况
//        for (auto position : positions) {
//            if (v[position.second] != -1) {
//                // in the same col
//                return false;
//            } else {
//                v[position.second] = 1;
//            }
//            if (w[position.first / 3][position.second / 3] != -1) {
//                // in the same grid
//                return false;
//            } else {
//                w[position.first / 3][position.second / 3] = 1;
//            }
//        }
//    }
//    return true;
}
