//
//  Solution53.hpp
//  Algorithm
//
//  Created by Pancf on 2020/10/18.
//  Copyright © 2020 Pancf. All rights reserved.
//

#ifndef Solution53_hpp
#define Solution53_hpp

#include <stdio.h>
#include <vector>

class Solution53 {
public:
    int maxSubArray(std::vector<int>& nums);
    static void test()
    {
        std::vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
        Solution53 s = Solution53();
        printf("%d\n", s.maxSubArray(nums));
    }
};

#endif /* Solution53_hpp */
