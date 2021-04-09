//
//  Solution130.hpp
//  Algorithm
//
//  Created by Pancf on 2020/12/20.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution130_hpp
#define Solution130_hpp

#include <stdio.h>
#include <vector>

class Solution130 {
public:
    void solve(std::vector<std::vector<char>>& board);
    static void test()
    {
        std::vector<std::vector<char>> board{
            {'X', 'X', 'X', 'X'},
            {'X', 'O', 'O', 'X'},
            {'X', 'X', 'O', 'X'},
            {'X', 'O', 'X', 'X'}
        };
        Solution130 s;
        s.solve(board);
        for (auto row : board) {
            for (auto cell : row) {
                printf("%c\t", cell);
            }
            printf("\n");
        }
    }
};

#endif /* Solution130_hpp */
