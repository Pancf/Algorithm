//
//  Solution79.hpp
//  Algorithm
//
//  Created by Pancf on 2020/11/7.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution79_hpp
#define Solution79_hpp

#include <stdio.h>
#include <vector>
#include <string>

class Solution79 {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word);
    static void test()
    {
        Solution79 solution;
        std::vector<std::vector<char>> board{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
        std::string word{"SEE"};
        printf("%d\n", solution.exist(board, word));
        std::string word2{"ABCCED"};
        std::string word3{"ABCB"};
        printf("%d\n", solution.exist(board, word2));
        printf("%d\n", solution.exist(board, word3));
    }
};

#endif /* Solution79_hpp */
