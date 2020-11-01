//
//  Solution69.hpp
//  Algorithm
//
//  Created by Pancf on 2020/11/1.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution69_hpp
#define Solution69_hpp

#include <stdio.h>

class Solution69 {
public:
    int mySqrt(int x);
    static void test()
    {
        Solution69 s = Solution69();
        printf("%d\n", s.mySqrt(4));
        printf("%d\n", s.mySqrt(8));
    }
};

#endif /* Solution69_hpp */
