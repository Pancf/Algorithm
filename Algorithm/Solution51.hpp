//
//  Solution51.hpp
//  Algorithm
//
//  Created by Pancf on 2020/11/15.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution51_hpp
#define Solution51_hpp

#include <stdio.h>
#include <vector>
#include <string>

class Solution51 {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n);
    static void test()
    {
        Solution51 s;
        auto res1 = s.solveNQueens(4);
        for (auto v : res1) {
            for (auto str : v) {
                printf("%s\n", str.c_str());
            }
            printf("\n");
        }
        auto res2 = s.solveNQueens(5);
        for (auto v : res2) {
            for (auto str : v) {
                printf("%s\n", str.c_str());
            }
            printf("\n");
        }
    }
};

#endif /* Solution51_hpp */
