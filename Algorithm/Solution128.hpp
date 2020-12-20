//
//  Solution128.hpp
//  Algorithm
//
//  Created by Pancf on 2020/12/20.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution128_hpp
#define Solution128_hpp

#include <stdio.h>
#include <vector>

class Solution128 {
public:
    int longestConsecutive(std::vector<int>& nums);
    static void test()
    {
        std::vector<int> input1{100,4,200,1,3,2};
        std::vector<int> input2{0,3,7,2,5,8,4,6,0,1};
        Solution128 s;
        printf("%d\t%d\n", s.longestConsecutive(input1), s.longestConsecutive(input2));
    }
};

#endif /* Solution128_hpp */
