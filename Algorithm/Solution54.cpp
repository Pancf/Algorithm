//
//  Solution54.cpp
//  Algorithm
//
//  Created by Pancf on 2020/11/1.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution54.hpp"

std::vector<int> Solution54::spiralOrder(std::vector<std::vector<int> > &matrix)
{
    std::vector<int> res;
    int row = (int)matrix.size();
    if (row == 0) return res;
    int col = (int)matrix[0].size();
    if (col == 0) return res;
    int idx = 0, i = 0, j = 0, iter = 0;
    while (idx < row * col) {
        res.push_back(matrix[i][j]);
        idx++;
        if (i == iter && j < col - 1 - iter) {
            // top row，跳出时 i = iter, j = col-1-iter
            j++;
        } else if (j == col - 1 - iter && i < row - 1 - iter) {
            // right col，跳出时 i = row-1-iter, j=col-1-iter
            i++;
        } else if (i == row - 1 - iter && j > iter) {
            // bottom row，跳出时 i=row-1-iter, j=iter
            j--;
        } else if (j == iter && i > iter + 1) {
            // left col，跳出时 i=iter+1, j=iter
            i--;
        } else {
            iter++;
            i = iter;
            j = iter;
        }
    }
    return res;
}
