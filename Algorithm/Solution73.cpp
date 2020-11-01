//
//  Solution73.cpp
//  Algorithm
//
//  Created by Pancf on 2020/11/1.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution73.hpp"
#include <set>

void Solution73::setZeroes(std::vector<std::vector<int> > &matrix)
{
    int row = (int)matrix.size(), col = (int)matrix[0].size();
    std::set<int> rowSet;
    std::set<int> colSet;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (matrix[i][j] == 0) {
                rowSet.insert(i);
                colSet.insert(j);
            }
        }
    }
    for (auto r : rowSet) {
        for (int j = 0; j < col; ++j) {
            matrix[r][j] = 0;
        }
    }
    for (auto c : colSet) {
        for (int i = 0; i < row; ++i) {
            matrix[i][c] = 0;
        }
    }
}
