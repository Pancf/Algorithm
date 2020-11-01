//
//  Solution70.hpp
//  Algorithm
//
//  Created by Pancf on 2020/11/1.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution70_hpp
#define Solution70_hpp

#include <stdio.h>

class Solution70 {
public:
    int climbStairs(int n);
    static void test()
    {
        Solution70 s;
        printf("%d\n", s.climbStairs(3));
    }
};

#endif /* Solution70_hpp */
