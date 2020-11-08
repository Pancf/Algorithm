//
//  Solution84.hpp
//  Algorithm
//
//  Created by Pancf on 2020/11/8.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution84_hpp
#define Solution84_hpp

#include <stdio.h>
#include <vector>

class Solution84 {
public:
    int largestRectangleArea(std::vector<int>& heights);
    static void test()
    {
        Solution84 solution;
        std::vector<int> heights1{2,1,5,6,2,3};
        std::vector<int> heights2{2,0,1,0,1,0};
        std::vector<int> heights3{1,2,2};
        std::vector<int> heights4{1,2,3,4,5};
        printf("%d\n", solution.largestRectangleArea(heights1));
        printf("%d\n", solution.largestRectangleArea(heights2));
        printf("%d\n", solution.largestRectangleArea(heights3));
        printf("%d\n", solution.largestRectangleArea(heights4));
    }
};

#endif /* Solution84_hpp */
