//
//  Solution48.cpp
//  Algorithm
//
//  Created by Pancf on 2020/10/25.
//  Copyright © 2020 Pancf. All rights reserved.
//

#include "Solution48.hpp"
#include <algorithm>

/* time complexity is n^2 / 2
 * clockwise rotate
 * first reverse up to down, then swap the symmetry
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/
void rotate(std::vector<std::vector<int> > &matrix) {
    reverse(matrix.begin(), matrix.end());
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = i + 1; j < matrix[i].size(); ++j)
            std::swap(matrix[i][j], matrix[j][i]);
    }
}

/*
 * anticlockwise rotate
 * first reverse left to right, then swap the symmetry
 * 1 2 3     3 2 1     3 6 9
 * 4 5 6  => 6 5 4  => 2 5 8
 * 7 8 9     9 8 7     1 4 7
*/
void anti_rotate(std::vector<std::vector<int> > &matrix) {
    for (auto vi : matrix) reverse(vi.begin(), vi.end());
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = i + 1; j < matrix[i].size(); ++j)
            std::swap(matrix[i][j], matrix[j][i]);
    }
}

void Solution48::rotate(std::vector<std::vector<int> > &matrix)
{
    // (0, 0) -> (0, 3), (0, 3) -> (3, 3), (3, 3) -> (3, 0), (3, 0) -> (0, 0)
    // (0, 1) -> (1, 3), (1, 3) -> (3, 2), (3, 2) -> (2, 0), (2, 0) -> (0, 1)
    // (0, 2) -> (2, 3), (2, 3) -> (3, 1), (3, 1) -> (1, 0), (1, 0) -> (0, 2)
    // (1, 1) -> (1, 2), (1, 2) -> (2, 2), (2, 2) -> (2, 1), (2, 1) -> (1, 1)
    int n = (int)matrix.size();
    int numberOfCircles = n / 2;
    for (int i = 0; i < numberOfCircles; ++i) {
        // start at (i, i), end is (i, i + matrix[i].size() - 2 - i)
        for (int j = i; j <= std::max(i, n - i - 2); ++j) {
            auto temp = matrix[i][j];
            matrix[i][j] = matrix[n - j - 1][i];
            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
            matrix[j][n - i - 1] = temp;
        }
    }
}
