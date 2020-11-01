//
//  Solution44.cpp
//  Algorithm
//
//  Created by Pancf on 2020/10/25.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution44.hpp"
#include <vector>

bool Solution44::isMatch(std::string s, std::string p)
{
    int row = (int)s.size(), col = (int)p.size();
    // matrix[i][j] means whether p[0, j-1] matches s[0, i-1] or not
    std::vector<std::vector<bool>> matrix(row + 1, std::vector<bool>(col + 1, false));
    matrix[0][0] = true;
    for (int i = 1; i <= col; ++i) {
        if (p[i - 1] == '*') matrix[0][i] = true;
        else break;
    }
    for (int i = 1; i <= row; ++i) {
        for (int j = 1; j <= col; ++j) {
            // whether p[0, j-1] matches s[0, i-1]
            if (p[j - 1] != '*') {
                // p[j-1] match? s[i-1]
                matrix[i][j] = (p[j - 1] == '?' || p[j - 1] == s[i - 1]) && matrix[i - 1][j - 1];
            } else {
                // '*' matches nothing(matrix[i][j-1]) or one character(matrix[i-1][j])
                matrix[i][j] = matrix[i][j - 1] || matrix[i - 1][j];
            }
        }
    }
    return matrix[row][col];
//    int i = 0, j = 0, match = 0, starIdx = -1;
//    while (i < s.size()){
//        // s[i] p[j]匹配，索引各自后移1位
//        if (j < p.size()  && (p[j] == '?' || s[i] == p[j])) {
//            i++;
//            j++;
//        } else if (j < p.size() && p[j] == '*') {
//            // p[j] == '*'，记录*的位置以便回溯
//            starIdx = j++;
//            match = i;
//        } else if (starIdx != -1) {
//            // 回溯时将*上次对应匹配的索引match自增，然后赋值给匹配串索引
//            j = starIdx + 1;
//            i = ++match;
//        } else return false;
//    }
//    while (j < p.size() && p[j] == '*')
//        j++;
//    
//    return j == p.size();
}
