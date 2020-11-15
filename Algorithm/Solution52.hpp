//
//  Solution52.hpp
//  Algorithm
//
//  Created by Pancf on 2020/11/15.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution52_hpp
#define Solution52_hpp

#include <stdio.h>

class Solution52 {
public:
    int totalNQueens(int n);
    static void test()
    {
        Solution52 s;
        auto res1 = s.totalNQueens(4);
        printf("%d\n", res1);
        auto res2 = s.totalNQueens(5);
        printf("%d\n", res2);
    }
};

#endif /* Solution52_hpp */
