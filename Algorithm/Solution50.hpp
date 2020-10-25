//
//  Solution50.hpp
//  Algorithm
//
//  Created by Pancf on 2020/10/25.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution50_hpp
#define Solution50_hpp

#include <stdio.h>

class Solution50 {
public:
    double myPow(double x, int n);
    static void test()
    {
        Solution50 s = Solution50();
        printf("%.5f\n", s.myPow(2.10, 3));
    }
};

#endif /* Solution50_hpp */
