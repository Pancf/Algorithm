//
//  Solution36.hpp
//  Algorithm
//
//  Created by Pancf on 2020/10/17.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution36_hpp
#define Solution36_hpp

#include <stdio.h>
#include <vector>

class Solution36 {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board);
    static void test()
    {
        std::vector<std::vector<char>> board = {
            {'.','.','.','9','.','.','.','.','.'},
            {'.','.','.','.','.','.','.','.','.'},
            {'.','.','3','.','.','.','.','.','1'},
            {'.','.','.','.','.','.','.','.','.'},
            {'1','.','.','.','.','.','3','.','.'},
            {'.','.','.','.','2','.','6','.','.'},
            {'.','9','.','.','.','.','.','7','.'},
            {'.','.','.','.','.','.','.','.','.'},
            {'8','.','.','8','.','.','.','.','.'}
        };
        Solution36 s = Solution36();
        printf("%s\n", s.isValidSudoku(board) ? "true" : "false");
    }
};

#endif /* Solution36_hpp */
